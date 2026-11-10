%{
#include <stdio.h>
%}

%%
[6-9][0-9]{9}    printf("Valid Mobile Number");
[0-9]+           printf("Invalid Mobile Number");
%%

int main()
{
    printf("Enter Mobile Number: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
