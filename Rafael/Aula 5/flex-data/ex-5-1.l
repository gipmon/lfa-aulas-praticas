%{
    #include <stdio.h>

    #define red "31;1"
    #define green "32;2"
    #define blue "34;2"
    #define yellow "33;1"
    #define somecolor "42;1"

    #define printColor(c,t) fprintf(yyout, "\e[%sm%s\e[0m",c,t)
%}

%option noyywrap

e1  [0-9]+
e2  [a-z]+
e3  [A-Z]+
e4  [a-zA-Z]+
e5  [a-zA-Z][a-zA-Z0-9]*

%%

{e1} { printColor(red, yytext); }
{e2} { printColor(green, yytext); }
{e3} { printColor(somecolor, yytext); }
{e4} { printColor(blue, yytext); }
{e5} { printColor(yellow, yytext); }

.|\n { ECHO; }

%%

int main(int argc, char *argv[])
{
    switch (argc)
    {
        case 1: // read from stdin, the default
        {
            break;
        }
        case 2: // read from given file
        {
            if ((yyin = fopen(argv[1], "r")) == NULL)
            {
                fprintf(stderr, "Fail openning input file \"%s\"\n", argv[1]);
                exit(EXIT_FAILURE);
            }
            break;
        }
        default:
        {
            fprintf(stderr, "Wrong number of arguments\n");
            exit(EXIT_FAILURE);
        }
    }

    return yylex();
}

