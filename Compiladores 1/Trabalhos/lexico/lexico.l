%option noyywrap
%{
    #include <stdio.h>
    #include <string.h>

    int linha = 1,
        coluna = 1,
        colunaComentario = 1,
        linhaComentario = 1,
        pulin = 0;

    void reset_stats();
    void Pulin(int pulin);

%}

%x COMMENT

%%      

<INITIAL>{
"void"    {Pulin(pulin); printf("VOID");    coluna += yyleng; pulin++;}
"int"     {Pulin(pulin); printf("INT");     coluna += yyleng; pulin++;}
"char"    {Pulin(pulin); printf("CHAR");    coluna += yyleng; pulin++;}
"return"  {Pulin(pulin); printf("RETURN");  coluna += yyleng; pulin++;}
"break"   {Pulin(pulin); printf("BREAK");   coluna += yyleng; pulin++;}
"switch"  {Pulin(pulin); printf("SWITCH");  coluna += yyleng; pulin++;}
"case"    {Pulin(pulin); printf("CASE");    coluna += yyleng; pulin++;}
"default" {Pulin(pulin); printf("DEFAULT"); coluna += yyleng; pulin++;}
"do"      {Pulin(pulin); printf("DO");      coluna += yyleng; pulin++;}
"while"   {Pulin(pulin); printf("WHILE");   coluna += yyleng; pulin++;}
"for"     {Pulin(pulin); printf("FOR");     coluna += yyleng; pulin++;}
"if"      {Pulin(pulin); printf("IF");      coluna += yyleng; pulin++;}
"else"    {Pulin(pulin); printf("ELSE");    coluna += yyleng; pulin++;}
"typedef" {Pulin(pulin); printf("TYPEDEF"); coluna += yyleng; pulin++;}
"struct"  {Pulin(pulin); printf("STRUCT");  coluna += yyleng; pulin++;}

"+"       {Pulin(pulin); printf("PLUS");                coluna += yyleng; pulin++;}
"-"       {Pulin(pulin); printf("MINUS");               coluna += yyleng; pulin++;}
"*"       {Pulin(pulin); printf("MULTIPLY");            coluna += yyleng; pulin++;}
"/"       {Pulin(pulin); printf("DIV");                 coluna += yyleng; pulin++;}
"%"       {Pulin(pulin); printf("REMAINDER");           coluna += yyleng; pulin++;}
"++"      {Pulin(pulin); printf("INC");                 coluna += yyleng; pulin++;}
"--"      {Pulin(pulin); printf("DEC");                 coluna += yyleng; pulin++;}
"&"       {Pulin(pulin); printf("BITWISE_AND");         coluna += yyleng; pulin++;}
"|"       {Pulin(pulin); printf("BITWISE_OR");          coluna += yyleng; pulin++;}
"~"       {Pulin(pulin); printf("BITWISE_NOT");         coluna += yyleng; pulin++;}
"^"       {Pulin(pulin); printf("BITWISE_XOR");         coluna += yyleng; pulin++;}
"!"       {Pulin(pulin); printf("NOT");                 coluna += yyleng; pulin++;}
"&&"      {Pulin(pulin); printf("LOGICAL_AND");         coluna += yyleng; pulin++;}
"||"      {Pulin(pulin); printf("LOGICAL_OR");          coluna += yyleng; pulin++;}
"=="      {Pulin(pulin); printf("EQUAL");               coluna += yyleng; pulin++;}
"!="      {Pulin(pulin); printf("NOT_EQUAL");           coluna += yyleng; pulin++;}
"<"       {Pulin(pulin); printf("LESS_THAN");           coluna += yyleng; pulin++;}
">"       {Pulin(pulin); printf("GREATER_THAN");        coluna += yyleng; pulin++;}
"<="      {Pulin(pulin); printf("LESS_EQUAL");          coluna += yyleng; pulin++;}
">="      {Pulin(pulin); printf("GREATER_EQUAL");       coluna += yyleng; pulin++;}
">>"      {Pulin(pulin); printf("R_SHIFT");             coluna += yyleng; pulin++;}
"<<"      {Pulin(pulin); printf("L_SHIFT");             coluna += yyleng; pulin++;}
"="       {Pulin(pulin); printf("ASSIGN");              coluna += yyleng; pulin++;}
"+="      {Pulin(pulin); printf("ADD_ASSIGN");          coluna += yyleng; pulin++;}
"-="      {Pulin(pulin); printf("MINUS_ASSIGN");        coluna += yyleng; pulin++;}
";"       {Pulin(pulin); printf("SEMICOLON");           coluna += yyleng; pulin++;}
","       {Pulin(pulin); printf("COMMA");               coluna += yyleng; pulin++;}
":"       {Pulin(pulin); printf("COLON");               coluna += yyleng; pulin++;}
"("       {Pulin(pulin); printf("L_PAREN");             coluna += yyleng; pulin++;}
")"       {Pulin(pulin); printf("R_PAREN");             coluna += yyleng; pulin++;}
"{"       {Pulin(pulin); printf("L_CURLY_BRACKET");     coluna += yyleng; pulin++;}
"}"       {Pulin(pulin); printf("R_CURLY_BRACKET");     coluna += yyleng; pulin++;}
"["       {Pulin(pulin); printf("L_SQUARE_BRACKET");    coluna += yyleng; pulin++;}
"]"       {Pulin(pulin); printf("R_SQUARE_BRACKET");    coluna += yyleng; pulin++;}
"?"       {Pulin(pulin); printf("TERNARY_CONDITIONAL"); coluna += yyleng; pulin++;}
"#"       {Pulin(pulin); printf("NUMBER_SIGN");         coluna += yyleng; pulin++;}

"->"      {Pulin(pulin); printf("POINTER"); coluna += yyleng; pulin++;}
"printf"  {Pulin(pulin); printf("PRINTF");  coluna += yyleng; pulin++;}
"scanf"   {Pulin(pulin); printf("SCANF");   coluna += yyleng; pulin++;}
"define"  {Pulin(pulin); printf("DEFINE");  coluna += yyleng; pulin++;}
"exit"    {Pulin(pulin); printf("EXIT");    coluna += yyleng; pulin++;}

"/*"      {linhaComentario=linha; colunaComentario=coluna; coluna += yyleng; BEGIN(COMMENT);}
"//".*\n  {linha++;}

[a-zA-Z_][_a-zA-Z0-9]*  { 
    Pulin(pulin); 
    if (yyleng>255)
        printf("error:lexical:%d:%d: identifier too long",linha,coluna);
    else
    printf("IDENTIFIER(%s)",yytext); coluna += yyleng; pulin++;
    }
0(X|x)[0-9a-fA-F]+      {Pulin(pulin); printf("NUM_HEXA(%s)",yytext);       coluna += yyleng; pulin++;}
0[1-7][0-7]*            {Pulin(pulin); printf("NUM_OCTAL(%s)",yytext);      coluna += yyleng; pulin++;}
[0-9]+                  {Pulin(pulin); printf("NUM_INTEGER(%s)",yytext);    coluna += yyleng; pulin++;}

[']"\\"[abfnrtv\\\'\"\?0][']      {Pulin(pulin); printf("CHARACTER(%.*s)", yyleng - 2, yytext + 1);   coluna += yyleng; pulin++;}
['].[']                 {Pulin(pulin); printf("CHARACTER(%.*s)", yyleng - 2, yytext + 1);   coluna += yyleng; pulin++;}
"\""[^"]*"\""           {Pulin(pulin); printf("STRING(%.*s)", yyleng - 2, yytext + 1);      coluna += yyleng; pulin++;}
" "                     {coluna++;}
\n                      {coluna = 1; linha++;}

.                       {Pulin(pulin); printf("error:lexical:%d:%d: %s",linha,coluna, yytext); coluna += yyleng; pulin++;}

}

<COMMENT>{

<<EOF>> {printf("\nerror:lexical:%d:%d: unterminated comment",linhaComentario,colunaComentario); return -1;}
\n      {coluna=1;linha++;}
"/*/"   {BEGIN(INITIAL); coluna += yyleng;}
"*/"    {BEGIN(INITIAL); coluna += yyleng;}
"/*"    {printf("\nwarning:%d:%d: '/*' within block comment",linha,coluna); coluna += yyleng;}
.       {coluna++;}
}

%%

void Pulin(int pulin){
    if (pulin){
        printf("\n");
    }
}

int main(int argc, char** argv)
{
yylex();
return 0;
}