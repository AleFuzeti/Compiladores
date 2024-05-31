%option noyywrap
%{
%}
%%
if                              {printf("%s IF\n",yytext);}
--[a-z]+\n                      {yytext[strlen(yytext)-1] = '\0';printf("%s comment\n",yytext);}
[a-z][a-z0-9]*                  {printf("%s ID\n",yytext);}
([0-9]+[.][0-9]*)|([.][0-9]+)   {printf("%s REAL\n",yytext);}
[0-9]+                          {printf("%s NUM\n",yytext);}
[ ]+                            {printf("white space\n");}
[.]                             {printf("error\n");}
.                               {printf("error\n");}
%%
int main(int argc, char** argv)
{
yylex();
return 0;
}