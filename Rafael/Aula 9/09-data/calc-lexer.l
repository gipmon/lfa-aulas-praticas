%{
    #include <stdlib.h>

    #include "calc-parser.tab.h"

    #define YY_DECL int yylex(YYSTYPE* p)
%}


%option noyywrap
%option nounput
%option noinput

nint    [0-9]+
num 	{mant}{exp}?
mant    {nint}|{nint}\.{nint}
exp		[eE][+-]?{nint}

id      [a-z]

valid   [-+()*/=\n]

spaces  [ \t]+

%%

{num}       { p->vnum = atof(yytext); return NUM; }

{id}        { p->vid = yytext[0]; return ID; }

{spaces}    { }

{valid}     { return yytext[0]; }

.           { p->vchar = yytext[0]; return OTHER; }

%%

