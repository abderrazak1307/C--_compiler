%{
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "syntax.tab.h"

int numLn=1;
int numCol=0;
int numErrors=0;
int isTwoDecimals(char* str);

extern YYSTYPE yylval;
%}
Pint [0-9]+
Pfloat {Pint}\.[0-9]+
IDF ([a-z]([a-z]|[0-9]|_)*([a-z]|[0-9]))|[a-z]
OP (\+)|(\*)|(\-)|(\/)
MLCmnt \/\*(.|\n)*\*\/
Cmnt \/\/.*

%%
{Cmnt} {numCol+=yyleng;}
{MLCmnt} {
    for(int i=0; i<yyleng; i++){
        if(yytext[i]=='\n'){
            numLn++;
            numCol=1;
        }else{
            numCol++;
        }
    }
}

Program {numCol+=yyleng; return Program;}
PDEC {numCol+=yyleng; return PDEC;}
PINST {numCol+=yyleng; return PINST;}
Begin {numCol+=yyleng; return Begin;}
End {numCol+=yyleng; return End;}
FOR {numCol+=yyleng; return FOR;}
WHILE {numCol+=yyleng; return WHILE;}
DO {numCol+=yyleng; return DO;}
ENDFOR {numCol+=yyleng; return ENDFOR;}
IF {numCol+=yyleng; return IF;}
ELSE {numCol+=yyleng; return ELSE;}
ENDIF {numCol+=yyleng; return ENDIF;}

"@define" {numCol+=yyleng; return define;}
Pint {numCol+=yyleng; return Pint;}
Pfloat {numCol+=yyleng; return Pfloat;}

{IDF} {
    if(yyleng <= 12){
        numCol+=yyleng;
        yylval.string = strdup(yytext);
        return IDF;
    }else{
        printf("LexicalError, Ln %d, Col %d: un identificateur '%s' ne peut pas depasser 12 caracteres.\n", numLn, numCol, yytext);
        numCol+=yyleng;
        numErrors++;
    }
}
{Pint} {
    if(atoi(yytext)< -32768 || atoi(yytext) > 32767){
        printf("LexicalError, Ln %d, Col %d: Pint '%s' a depasse l'intervalle de 32bit.\n", numLn, numCol, yytext);
        numErrors++;
    }else{
        numCol+=yyleng;
        yylval.pint = (int)atoi(yytext);
        return PintVal;
    }   
}
{Pfloat} {
    if(atof(yytext) < -32768 || atof(yytext) > 32767){
        printf("LexicalError, Ln %d, Col %d: Pfloat '%s' a depasse l'intervalle de 32bit.\n", numLn, numCol, yytext);
        numErrors++;
    }else if(!isTwoDecimals(yytext)){
        printf("LexicalError, Ln %d, Col %d: Pfloat '%s' ne peut pas avoir plus de 2 chiffres decimaux.\n", numLn, numCol, yytext);
        numErrors++;
    }else{
        numCol+=yyleng;
        yylval.pfloat = (float)atof(yytext);
        return PfloatVal;
    }
}

\( {numCol+=yyleng; return '(';}
\) {numCol+=yyleng; return ')';}

\| {numCol+=yyleng; return '|';}
\& {numCol+=yyleng; return '&';}
\! {numCol+=yyleng; return '!';}

\> {numCol+=yyleng; return GRT;}
\>= {numCol+=yyleng; return GRT_EQ;}
\== {numCol+=yyleng; return EQ;}
\!= {numCol+=yyleng; return NOT_EQ;}
\<= {numCol+=yyleng; return LESS_EQ;}
\< {numCol+=yyleng; return LESS;}

"<--" {numCol+=yyleng; return ASSIGN;}
\+ {numCol+=yyleng; return '+';}
\- {numCol+=yyleng; return '-';}
\* {numCol+=yyleng; return '*';}
\/ {numCol+=yyleng; return '/';}
: {numCol+=yyleng; return ':';}
; {numCol+=yyleng; return ';';}
= {numCol+=yyleng; return '=';}

[ \t]* {numCol+=yyleng;}
\n {numLn++; numCol=1;}
. {
    printf("LexicalError, Ln %d, Col %d: token '%s' not recognised.\n", numLn, numCol, yytext);
    numErrors++;
}
%%
int isTwoDecimals(char* str){
    float v1 = (float)(atof(str)*100.0);
    float v2 = (float)(floorf(atof(str)*100.0));

    return v1 == v2;
}

int yywrap(void){
    return 0;
}
