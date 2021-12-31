%{
#include <stdio.h>
#include <math.h>

#define INCREMENT_NumCol numCol += yyleng

int numLn=1;
int numCol=0;
int numErrors=0;

int isTwoDecimals(char* str);
%}
Pint [0-9]+
Pfloat {Pint}\.[0-9]+
IDF [a-z]([a-z]|[0-9]|_)*
OP (\+)|(\*)|(\-)|(\/)
MLCmnt \/\*(.|\n)+?\*\/
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

Program {printf("Program keyword detected\n"); INCREMENT_NumCol;}
PDEC {printf("PDEC keyword detected\n"); INCREMENT_NumCol;}
PINST {printf("PINST keyword detected\n"); INCREMENT_NumCol;}
Begin {printf("Begin keyword detected\n"); INCREMENT_NumCol;}
End {printf("End keyword detected\n"); INCREMENT_NumCol;}
FOR {printf("FOR keyword detected\n"); INCREMENT_NumCol;}
WHILE {printf("WHILE keyword detected\n"); INCREMENT_NumCol;}
DO {printf("DO keyword detected\n"); INCREMENT_NumCol;}
ENDFOR {printf("ENDFOR keyword detected\n"); INCREMENT_NumCol;}
IF {printf("IF keyword detected\n"); INCREMENT_NumCol;}
ELSE {printf("ELSE keyword detected\n"); INCREMENT_NumCol;}
ENDIF {printf("ENDIF keyword detected\n"); INCREMENT_NumCol;}

"@define" {printf("define keyword detected\n"); INCREMENT_NumCol;}
Pint {printf("Pint keyword was detected\n"); INCREMENT_NumCol;}
Pfloat {printf("Pfloat keyword was detected\n"); INCREMENT_NumCol;}

{IDF} {
    if(yyleng <= 12){
        printf("IDF detected (%s)\n",yytext);
        INCREMENT_NumCol;
       
    }else{
        printf("LexicalError, Ln %d, Col %d: un identificateur '%s' ne peut pas depasser 12 caracteres\n", numLn, numCol, yytext);
        INCREMENT_NumCol;
        numErrors++;
    }
}
{Pint} {
    if(atoi(yytext)< -32768 || atoi(yytext) > 32767){
        printf("LexicalError, Ln %d, Col %d: Pint '%s' a depasse l'intervalle de 32bit\n", numLn, numCol, yytext);
        numErrors++;
    }else{
        printf("PintVal detected (%s)\n",yytext);
        INCREMENT_NumCol;
       
    }   
}
{Pfloat} {
    if(atof(yytext) < -32768 || atof(yytext) > 32767){
        printf("LexicalError, Ln %d, Col %d: Pfloat '%s' a depasse l'intervalle de 32bit\n", numLn, numCol, yytext);
        numErrors++;
    }else if(!isTwoDecimals(yytext)){
        printf("LexicalError, Ln %d, Col %d: Pfloat '%s' ne peut pas avoir plus de 2 chiffres decimaux\n", numLn, numCol, yytext);
        numErrors++;
    }else{
        printf("PfloatVal was detected (%s)\n",yytext);
        INCREMENT_NumCol;
       
    }
}

\( {printf("'(' detected\n"); INCREMENT_NumCol;}
\) {printf("')' detected\n"); INCREMENT_NumCol;}

\| {printf("'|' detected\n"); INCREMENT_NumCol;}
\& {printf("'&' detected\n"); INCREMENT_NumCol;}
\! {printf("'!' detected\n"); INCREMENT_NumCol;}

\> {printf("GRT detected\n"); INCREMENT_NumCol;}
\>= {printf("GRT_EQ detected\n"); INCREMENT_NumCol;}
\== {printf("EQ detected\n"); INCREMENT_NumCol;}
\!= {printf("NOT_EQ detected\n"); INCREMENT_NumCol;}
\<= {printf("LESS_EQ detected\n"); INCREMENT_NumCol;}
\< {printf("LESS detected\n"); INCREMENT_NumCol;}

"<--" {printf("ASSIGN detected\n"); INCREMENT_NumCol;}
\+ {printf("'+' detected\n"); INCREMENT_NumCol;}
\- {printf("'-' detected\n"); INCREMENT_NumCol;}
\* {printf("'*' detected\n"); INCREMENT_NumCol;}
\/ {printf("'/' detected\n"); INCREMENT_NumCol;}
: {printf("':' detected\n"); INCREMENT_NumCol;}
; {printf("';' detected\n"); INCREMENT_NumCol;}
= {printf("'=' detected\n"); INCREMENT_NumCol;}

[ \t] {INCREMENT_NumCol;}
\n {numLn++; numCol=1;}
. {
    printf("LexicalError, Ln %d, Col %d: token '%s' not recognised\n", numLn, numCol, yytext);
    numErrors++;
}
%%
int isTwoDecimals(char* str){
    float v1 = (float)(atof(str)*100.0);
    float v2 = (float)(floorf(atof(str)*100.0));

    return v1 == v2;
}

int main( int argc, char *argv[] ){
    if (argc > 1) yyin = fopen( argv[1], "r" );
    else yyin = stdin;
    
    yylex();

   return 0;
}
int yywrap(void){
   return 0;
}
