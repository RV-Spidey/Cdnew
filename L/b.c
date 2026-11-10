
%{
#include <stdio.h>

int l = 0, s = 0, t = 0, c = 0;
%}

%%
\n              l++;
\t              t++;
" "             s++;
[^a-zA-Z0-9 \t\n]  c++;
%%

int main()
{
    yyin = fopen("input.txt", "r");

    if (yyin == NULL)
        printf("File not found");
    else
    {
        yylex();

        printf("Number of lines is %d\n", l);
        printf("Number of tabs is %d\n", t);
        printf("Number of spaces is %d\n", s);
        printf("Number of special characters is %d\n", c);

        fclose(yyin);
    }

    return 0;
}

int yywrap()
{
    return 1;
}
