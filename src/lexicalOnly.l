%{
#include <stdio.h>
#include <math.h>

int numLn=1;
int numCol=0;
int numErrors=0;
int isTwoDecimals(char* str);

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

Program {printf("Program keyword detected\n"); numCol+=yyleng;}
PDEC {printf("PDEC keyword detected\n"); numCol+=yyleng;}
PINST {printf("PINST keyword detected\n"); numCol+=yyleng;}
Begin {printf("Begin keyword detected\n"); numCol+=yyleng;}
End {printf("End keyword detected\n"); numCol+=yyleng;}
FOR {printf("FOR keyword detected\n"); numCol+=yyleng;}
WHILE {printf("WHILE keyword detected\n"); numCol+=yyleng;}
DO {printf("DO keyword detected\n"); numCol+=yyleng;}
ENDFOR {printf("ENDFOR keyword detected\n"); numCol+=yyleng;}
IF {printf("IF keyword detected\n"); numCol+=yyleng;}
ELSE {printf("ELSE keyword detected\n"); numCol+=yyleng;}
ENDIF {printf("ENDIF keyword detected\n"); numCol+=yyleng;}

"@define" {printf("define keyword detected\n"); numCol+=yyleng;}
Pint {printf("Pint keyword was detected\n"); numCol+=yyleng;}
Pfloat {printf("Pfloat keyword was detected\n"); numCol+=yyleng;}

{IDF} {
    if(yyleng <= 12){
        printf("IDF detected (%s)\n",yytext);
        numCol+=yyleng;
       
    }else{
        printf("LexicalError, Ln %d, Col %d: un identificateur '%s' ne peut pas depasser 12 caracteres\n", numLn, numCol, yytext);
        numCol+=yyleng;
        numErrors++;
    }
}
{Pint} {
    if(atoi(yytext)< -32768 || atoi(yytext) > 32767){
        printf("LexicalError, Ln %d, Col %d: Pint '%s' a depasse l'intervalle de 32bit\n", numLn, numCol, yytext);
        numErrors++;
    }else{
        printf("PintVal detected (%s)\n",yytext);
        numCol+=yyleng;
       
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
        numCol+=yyleng;
       
    }
}

\( {printf("'(' detected\n"); numCol+=yyleng;}
\) {printf("')' detected\n"); numCol+=yyleng;}

\| {printf("'|' detected\n"); numCol+=yyleng;}
\& {printf("'&' detected\n"); numCol+=yyleng;}
\! {printf("'!' detected\n"); numCol+=yyleng;}

\> {printf("GRT detected\n"); numCol+=yyleng;}
\>= {printf("GRT_EQ detected\n"); numCol+=yyleng;}
\== {printf("EQ detected\n"); numCol+=yyleng;}
\!= {printf("NOT_EQ detected\n"); numCol+=yyleng;}
\<= {printf("LESS_EQ detected\n"); numCol+=yyleng;}
\< {printf("LESS detected\n"); numCol+=yyleng;}

"<--" {printf("ASSIGN detected\n"); numCol+=yyleng;}
\+ {printf("'+' detected\n"); numCol+=yyleng;}
\- {printf("'-' detected\n"); numCol+=yyleng;}
\* {printf("'*' detected\n"); numCol+=yyleng;}
\/ {printf("'/' detected\n"); numCol+=yyleng;}
: {printf("':' detected\n"); numCol+=yyleng;}
; {printf("';' detected\n"); numCol+=yyleng;}
= {printf("'=' detected\n"); numCol+=yyleng;}

[ \t] {numCol+=yyleng;}
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
