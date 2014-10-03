%{
#define YYSTYPE void *

#include "ast.h"
#include "parser.tab.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void yyerror(char *);
int yywrap(void);

char *str, *curptr;
int cursz, chars;
#define SZMUL 128

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

%%

{DIGIT}+"."{DIGIT}* { yylval = malloc(sizeof(double)); *((double *) yylval) = atof(yytext); return FLOAT; }

{DIGIT}+ { yylval = malloc(sizeof(long)); *((long *) yylval) = atol(yytext); return INT; }

\"[^"]*\" { yylval = strdup(yytext+1); ((char *) yylval)[yyleng-2] = 0; return STRING; }

\'[^']*\' { yylval = strdup(yytext+1); ((char *) yylval)[yyleng-2] = 0; return STRING; }

if { return IF; }

then { return THEN; }

else { return ELSE; }

while { return WHILE; }

for { return FOR; }

in { return IN; }

do { return DO; }

func { return FUNC; }

return { return RETURN; }

break { return BREAK; }

continue { return CONTINUE; }

end { return END; }

None { return NONE; }

"+" { return PLUS; }

"-" { return MINUS; }

"*" { return STAR; }

"/" { return SLASH; }

"**" { return DSTAR; }

"&" { return BAND; }

"|" { return BOR; }

"^" { return BXOR; }

"~" { return BNOT; }

"&&" { return LAND; }

"||" { return LOR; }

"!" { return LNOT; }

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

"<" { return LESS; }

">" { return GREATER; }

"<=" { return LESSEQ; }

">=" { return GREATEREQ; }

"{" { return LBRACE; }

"}" { return RBRACE; }

"[" { return LBRACKET; }

"]" { return RBRACKET; }

"(" { return LPAREN; }

")" { return RPAREN; }

"." { return DOT; }

":" { return COLON; }

";" { return SEMICOLON; }

"," { return COMMA; }

"#" { return POUND; }

{IDENT} { yylval = strdup(yytext); return IDENT; }

--[^\n]*\n /* Skip comments */

[ \t\n]+ /* Skip whitespace */

%%

int yywrap(void) {
	return 1;
}

void yyerror(char *s) {
	puts(s);
}

stmt_node *sol_compile(const char *prgstr) {
    stmt_node *program = NULL;
    YY_BUFFER_STATE buf = yy_scan_string(prgstr);
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
