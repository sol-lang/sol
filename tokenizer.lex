%{
#define YYSTYPE void *

#include "ast.h"
#include "parser.tab.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void yyerror(YYLTYPE *, stmt_node **, char *);
int yywrap(void);

char *str, *curptr;
int cursz, chars;
#define SZMUL 128
int writing_html = 0;

void str_init(void) {
	str = malloc(SZMUL);
	curptr = str;
	cursz = SZMUL;
	chars = 0;
}

void str_putc(char c) {
	*curptr++ = c;
	chars++;
	if(chars >= cursz) {
		str = realloc(str, cursz + SZMUL);
		curptr = str + chars;
		cursz += SZMUL;
	}
}

/* http://stackoverflow.com/questions/656703/how-does-flex-support-bison-location-exactly */
/* Many thanks to hugomg and David Elson! */

static void update_loc(YYLTYPE *yylloc, char *yytext){
 int curr_line;
 int curr_col;

  curr_line = yylloc->first_line   = yylloc->last_line;
  curr_col = yylloc->first_column = yylloc->last_column;

  {char * s; for(s = yytext; *s != '\0'; s++){
    if(*s == '\n'){
      curr_line++;
      curr_col = 1;
    }else{
      curr_col++;
    }
  }}

  yylloc->last_line   = curr_line;
  yylloc->last_column = curr_col-1;
}

char *FONTS[] = {
	"Adobe Courier",
	"Adobe Helvetica",
	"Adobe New Century Schoolbook",
	"Adobe Times",
	"Andale Mono",
	"Arial",
	"Arial Black",
	"C059",
	"Cantarell",
	"Century Schoolbook L",
	"Comic Sans MS",
	"Courier New",
	"cursor.pcf",
	"D050000L",
	"DejaVu Math TeX Gyre",
	"DejaVu Sans",
	"DejaVu Sans,DejaVu Sans Condensed",
	"DejaVu Sans,DejaVu Sans Light",
	"DejaVu Sans Mono",
	"DejaVu Serif",
	"DejaVu Serif,DejaVu Serif Condensed",
	"Denemo",
	"Dingbats",
	"Emmentaler",
	"feta26",
	"Georgia",
	"GNU Unifont",
	"GNU Unifont CSUR",
	"GNU Unifont Sample",
	"Impact",
	"Misc Fixed",
	"Misc Fixed Wide",
	"Nimbus Mono L",
	"Nimbus Mono PS",
	"Nimbus Roman",
	"Nimbus Roman No9 L",
	"NimbusSans",
	"Nimbus Sans",
	"Nimbus Sans L",
	"Nimbus Sans Narrow",
	"P052",
	"Standard Symbols L",
	"Standard Symbols PS",
	"Times New Roman",
	"Trebuchet MS",
	"Unifont",
	"Unifont CSUR",
	"Unifont Sample",
	"Unifont Upper",
	"URW Bookman",
	"URW Bookman L",
	"URW Chancery L",
	"URW Gothic",
	"URW Gothic L",
	"URW Palladio L",
	"Verdana",
	"Webdings",
	"Z003",
};

static void write_html(char *yytext) {
	if(writing_html) {
		printf("<span style=\"font-family: %s;%s%s%s%s\">%s</span>",
			FONTS[rand() % (sizeof(FONTS) / sizeof(*FONTS))],
			rand() & 1 ? "font-weight: bold;" : "",
			rand() & 1 ? "font-style: italic;" : "",
			rand() & 1 ? "text-decoration: underline;" : "",
			rand() & 1 ? "font-variant: small-caps;" : "",
			yytext
		);
	}
}

#define YY_USER_ACTION update_loc(yylloc, yytext); write_html(yytext);

%}

DIGIT [0-9]
HEXDIGIT [0-9a-fA-F]
ALPHA [a-zA-Z]
IDENT [a-zA-Z_][a-zA-Z0-9_]*

/* This is the right way to do it, but it keeps generating token $undefined.

%x STRING

\" { str_init(); BEGIN STRING; }
<STRING>\\n { str_putc('\n'); }
<STRING>\\t { str_putc('\t'); }
<STRING>\\b { str_putc('\b'); }
<STRING>\\r { str_putc('\r'); }
<STRING>\\x{HEXDIGIT}{HEXDIGIT} { str_putc(strtol(yytext+2, NULL, 16)); }
<STRING>\\\" { str_putc('"'); }
<STRING>\" { str_putc('\0'); yylval = str; BEGIN 0; return STRING; }
<STRING>. { str_putc(*yytext); }

*/

%option bison-bridge bison-locations

%%

{DIGIT}+"."{DIGIT}* { *yylval = malloc(sizeof(double)); *((double *) *yylval) = atof(yytext); return FLOAT; }

{DIGIT}+ { *yylval = malloc(sizeof(long)); *((long *) *yylval) = atol(yytext); return INT; }

\"[^"]*\"	|
\'[^']*\' { *yylval = malloc(sizeof(unsigned long) + (yyleng - 2) * sizeof(char)); *((unsigned long *) *yylval) = yyleng - 2; memcpy(((char *) *yylval) + sizeof(unsigned long), yytext + 1, yyleng - 2); return STRING; }

if { return IF; }

then { return THEN; }

else { return ELSE; }

elseif { return ELSEIF; }

while { return WHILE; }

for { return FOR; }

in { return IN; }

do { return DO; }

func { return FUNC; }

macro { return MACRO; }

lambda { return LAMBDA; }

return { return RETURN; }

break { return BREAK; }

continue { return CONTINUE; }

end { return END; }

None { return NONE; }

"+" { return PLUS; }

"-" { return MINUS; }

"*" { return STAR; }

"/" { return SLASH; }

"%" { return PERCENT; }

"mod" { return PERCENT; }

"**" { return DSTAR; }

"&" { return BAND; }

"|" { return BOR; }

"^" { return BXOR; }

"~" { return BNOT; }

"&&" { return LAND; }

"and" { return LAND; }

"||" { return LOR; }

"or" { return LOR; }

"!" { return LNOT; }

"not" { return LNOT; }

"true" { *yylval = malloc(sizeof(long)); *((long *) *yylval) = 1; return INT;  }

"True" { *yylval = malloc(sizeof(long)); *((long *) *yylval) = 1; return INT;  }

"false" { *yylval = malloc(sizeof(long)); *((long *) *yylval) = 0; return INT;  }

"False" { *yylval = malloc(sizeof(long)); *((long *) *yylval) = 0; return INT;  }

"=" { return ASSIGN; }

"+=" { return ASSIGNPLUS; }

"-=" { return ASSIGNMINUS; }

"*=" { return ASSIGNSTAR; }

"/=" { return ASSIGNSLASH; }

"**=" { return ASSIGNDSTAR; }

"&=" { return ASSIGNBAND; }

"|=" { return ASSIGNBOR; }

"^=" { return ASSIGNBXOR; }

"==" { return EQUAL; }

"!=" { return NEQUAL; }

"<" { return LESS; }

">" { return GREATER; }

"<=" { return LESSEQ; }

">=" { return GREATEREQ; }

">>" { return RSHIFT; }

"<<" { return LSHIFT; }

"{" { return LBRACE; }

"}" { return RBRACE; }

"[" { return LBRACKET; }

"]" { return RBRACKET; }

^[ \t]*"(" { return BLPAREN; } /* "Breaking" paren, not allowed to introduce a call_expr */

"(" { return LPAREN; } 

")" { return RPAREN; }

"." { return DOT; }

":" { return COLON; }

";" { return SEMICOLON; }

"," { return COMMA; }

"#" { return POUND; }

"!!!" { return TBANG; }

{IDENT} { *yylval = (void *) strdup(yytext); return IDENT; }

--[^\n]*\n /* Skip comments */

[ \t\n]+ /* Skip whitespace */

%%

int yywrap(void) {
	return 1;
}

void yyerror(YYLTYPE *locp, stmt_node **prog, char *err) {
	fputs(err, stderr);
	fprintf(stderr, "\n(at lines %d-%d, cols %d-%d)\n", locp->first_line, locp->last_line, locp->first_column, locp->last_column);
	if(prog && *prog) {
		fprintf(stderr, "(while building a stmt of type %d)\n", (*prog)->type);
	}
}

stmt_node *sol_compile(const char *prgstr) {
    stmt_node *program = NULL;
    YY_BUFFER_STATE buf = yy_scan_string(prgstr);
    yyparse(&program);
    yy_delete_buffer(buf);
    return program;
}

stmt_node *sol_compile_buffer(const char *prgbuf, size_t sz) {
	stmt_node *program = NULL;
	YY_BUFFER_STATE buf = yy_scan_bytes(prgbuf, sz);
	yyparse(&program);
	yy_delete_buffer(buf);
	return program;
}

stmt_node *sol_compile_file(FILE *prgfile) {
    stmt_node *program = NULL;
    YY_BUFFER_STATE buf = yy_create_buffer(prgfile, YY_BUF_SIZE);
    yy_switch_to_buffer(buf);
    yyparse(&program);
    yy_delete_buffer(buf);
    return program;
}

void sol_write_html(FILE *prgfile) {
	stmt_node *program = NULL;
	YY_BUFFER_STATE buf = yy_create_buffer(prgfile, YY_BUF_SIZE);
	writing_html = 1;
	printf("<html><head><title>Sol Source File</title></head><body style=\"white-space: pre-wrap;\">\n");
	yy_switch_to_buffer(buf);
	yyparse(&program);
	yy_delete_buffer(buf);
	//stmt_free(program);
	printf("</body></html>\n");
}
