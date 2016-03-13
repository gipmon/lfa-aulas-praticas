%union
{
    double vnum;
    unsigned char vid;
    unsigned char vchar;
}

%{
    #include <stdio.h>
    #include <math.h>

    double var[26];

    int yylex(YYSTYPE* yylval);

    int yyerror(const char *s);
%}

%token <vnum> NUM
%token <vid> ID
%token <vchar> OTHER

%type <vnum> F P T E

%pure-parser

%defines

%%

S   :   E '\n' { printf(" = %g\n", $1); } S
    |   ID '=' E '\n' S { var[$1 - 'a'] = $3; }
    |   error '\n' { printf(" --> parse error\n"); } S
    |	/* lambda */
    ;

E	:	T { $$ = $1; }
    |	E '+' T { $$ = $1 + $3; }
    |	E '-' T { $$ = $1 - $3; }
    ;

T	:	P { $$ = $1; }
    |	T '*' P { $$ = $1 * $3; }
    |	T '/' P { $$ = $1 / $3; }
    ;

P   :   F { $$ = $1; }
    |   F '^' P { $$ = pow($1, $3); } 

F	:	NUM { $$ = $1; }
    |	'(' E ')' { $$ = $2; }
    |   '-' NUM {$$ = $2; }
    |   ID {$$ = var[$1 - 'a']; }
    ;

%%

int yyerror(const char *s)
{
    return 0;
}
