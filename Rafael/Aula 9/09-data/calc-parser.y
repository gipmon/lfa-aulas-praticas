%union
{
    double vnum;
    unsigned char vid;
    unsigned char vchar;
}

%{
    #include <stdio.h>

    int yylex(YYSTYPE* yylval);

    int yyerror(const char *s);
%}

%token <vnum> NUM
%token <vid> ID
%token <vchar> OTHER

%type <vnum> F T E

%pure-parser

%defines

%%

S   :   E '\n' { printf(" = %g\n", $1); } S
    |   error '\n' { printf(" --> parse error\n"); } S
    |	/* lambda */
    ;

E	:	T { $$ = $1; }
    |	E '+' T { $$ = $1 + $3; }
    |	E '-' T { $$ = $1 - $3; }
    ;

T	:	F { $$ = $1; }
    |	T '*' F { $$ = $1 * $3; }
    |	T '/' F { $$ = $1 / $3; }
    ;

F	:	NUM { $$ = $1; }
    |	'(' E ')' { $$ = $2; }
    ;

%%

int yyerror(const char *s)
{
    return 0;
}
