%{
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "syntax.tab.h"

#define INCREMENT_NumCol numCol += yyleng

int numLn=1;
int numCol=0;
int numErrors=0;

int isTwoDecimals(char* str);
extern void showLineHighlightError(int ln, int col);

extern YYLTYPE yylloc;
extern YYSTYPE yylval;
// on definie a USER_ACTION qui s'éxecute aprés la lecture de chaque entité
// et cela pour garder debut et fin de chaque entité dans @n dans les régles de grammaires
#define YY_USER_ACTION\
  yylloc.first_column = yylloc.last_column;\
  yylloc.last_column += yyleng;
%}
Pint [0-9]+
Pfloat {Pint}\.[0-9]+
IDF ([a-z]([a-z]|[0-9]|_)*([a-z]|[0-9]))|[a-z]
MLCmnt \/\*(.|\n)*\*\/
Cmnt \/\/.*
%%
{Cmnt} {INCREMENT_NumCol;}
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
Program {INCREMENT_NumCol; return Program;}
PDEC {INCREMENT_NumCol; return PDEC;}
PINST {INCREMENT_NumCol; return PINST;}
Begin {INCREMENT_NumCol; return Begin;}
End {INCREMENT_NumCol; return End;}
FOR {INCREMENT_NumCol; return FOR;}
WHILE {INCREMENT_NumCol; return WHILE;}
DO {INCREMENT_NumCol; return DO;}
ENDFOR {INCREMENT_NumCol; return ENDFOR;}
IF {INCREMENT_NumCol; return IF;}
ELSE {INCREMENT_NumCol; return ELSE;}
ENDIF {INCREMENT_NumCol; return ENDIF;}
"@define" {INCREMENT_NumCol; return define;}
Pint {INCREMENT_NumCol; return Pint;}
Pfloat {INCREMENT_NumCol; return Pfloat;}
{IDF} {
    if(yyleng <= 12){
        INCREMENT_NumCol;
        yylval.string = strdup(yytext);
        return IDF;
    }else{
        printf("LexicalError, Ln %d, Col %d: un identificateur '%s' ne peut pas depasser 12 caracteres.\n", numLn, numCol, yytext);
        showLineHighlightError(numLn, numCol);
        INCREMENT_NumCol;
        numErrors++;
    }
}
{Pint} {
    if(atoi(yytext)< -32768 || atoi(yytext) > 32767){
        printf("LexicalError, Ln %d, Col %d: Pint '%s' a depasse l'intervalle de 32bit.\n", numLn, numCol, yytext);
        showLineHighlightError(numLn, numCol);
        INCREMENT_NumCol;
        numErrors++;
    }else{
        INCREMENT_NumCol;
        yylval.pint = (int)atoi(yytext);
        return PintVal;
    }   
}
{Pfloat} {
    if(atof(yytext) < -32768 || atof(yytext) > 32767){
        numErrors++;
        printf("LexicalError, Ln %d, Col %d: Pfloat '%s' a depasse l'intervalle de 32bit.\n", numLn, numCol, yytext);
        showLineHighlightError(numLn, numCol);
        INCREMENT_NumCol;
    }else if(!isTwoDecimals(yytext)){
        numErrors++;
        printf("LexicalError, Ln %d, Col %d: Pfloat '%s' ne peut pas avoir plus de 2 chiffres decimaux.\n", numLn, numCol, yytext);
        showLineHighlightError(numLn, numCol);
        INCREMENT_NumCol;
    }else{
        INCREMENT_NumCol;
        yylval.pfloat = (float)atof(yytext);
        return PfloatVal;
    }
}

\( {INCREMENT_NumCol; return '(';}
\) {INCREMENT_NumCol; return ')';}

\| {INCREMENT_NumCol; return '|';}
\& {INCREMENT_NumCol; return '&';}
\! {INCREMENT_NumCol; return '!';}

\> {INCREMENT_NumCol; return GRT;}
\>= {INCREMENT_NumCol; return GRT_EQ;}
\== {INCREMENT_NumCol; return EQ;}
\!= {INCREMENT_NumCol; return NOT_EQ;}
\<= {INCREMENT_NumCol; return LESS_EQ;}
\< {INCREMENT_NumCol; return LESS;}

\<-- {INCREMENT_NumCol; return ASSIGN;}
\+ {INCREMENT_NumCol; return '+';}
\- {INCREMENT_NumCol; return '-';}
\* {INCREMENT_NumCol; return '*';}
\/ {INCREMENT_NumCol; return '/';}
: {INCREMENT_NumCol; return ':';}
; {INCREMENT_NumCol; return ';';}
= {INCREMENT_NumCol; return '=';}

[ \t]* {INCREMENT_NumCol;}
\n {
    numLn++; numCol = 1;
    yylloc.first_column = 1; yylloc.last_column = 1;
}
. {
    numErrors++;
    printf("LexicalError, Ln %d, Col %d: token '%s' not recognised.\n", numLn, numCol, yytext);
    showLineHighlightError(numLn, numCol);
    INCREMENT_NumCol;
}
%%
int isTwoDecimals(char* str){
    float v1 = (float)(atof(str)*100.0);
    float v2 = (float)(floorf(atof(str)*100.0));

    return v1 == v2;
}
int yywrap(void){ return 0; }
