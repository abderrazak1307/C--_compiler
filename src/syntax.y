%{
#include <stdio.h>
#include "semantic.h"
#include <time.h>

clock_t start;
FILE* inputStream;

extern int numLn;
extern int numCol;
extern int savedNumCol;
extern int numErrors;
extern FILE* yyin;

int yyerror(char* msg);
extern int yylex();
extern int yytext;
extern int yyleng;

extern int decType;
extern double savedVal;
extern int isLastReadAVal;
%}
%locations
%union {
int pint;
float pfloat;
char* string;
}

%start S
%token Program PDEC PINST Begin End FOR WHILE DO ENDFOR IF ELSE ENDIF define ASSIGN Pint Pfloat GRT GRT_EQ EQ NOT_EQ LESS_EQ LESS
%token<string> IDF
%token<pint> PintVal //type==0
%token<pfloat> PfloatVal //type==1

%type<string> OP_Comparison '+' '-' '*' '/' '=' ASSIGN;
%type<pint> Expression Val Type Sign;

%left '|'
%left '&'
%left '!'

%left GRT GRT_EQ EQ NOT_EQ LESS_EQ LESS

%left '+' '-'
%left '*' '/'

%%
S : Header PartieDeclaration PartieInstructions {
    double duration = (1000.0*(clock() - start)) / CLOCKS_PER_SEC;
    printf("===== Compilation finished in %.2fms with %d error(s) =====\n", duration, numErrors);
    afficher();
    YYACCEPT;
};

Header : Program IDF;

PartieDeclaration : PDEC Declaration;

PartieInstructions : PINST Begin Instruction End;

Declaration : Declaration define Type IDF '=' Val ';' {
                savedNumCol = @4.first_column;
                if(!checkNoDoubleDeclaration($4)) return 1;

                savedNumCol = @5.first_column;
                if(checkTypeCompatAffect($4, $3, $6, "="))
                    insert($4, decType, 1);
            }
            | define Type IDF '=' Val ';' {
                savedNumCol = @3.first_column;
                if(!checkNoDoubleDeclaration($3)) return 1;

                savedNumCol = @4.first_column;
                if(checkTypeCompatAffect($3, $2, $5, "="))
                    insert($3, decType, 1);
            }
            | Declaration ListeIdf ':' Type ';' {
                MAJRecentVariables();
            }
            | ListeIdf ':' Type ';' {
                MAJRecentVariables();
            };            

ListeIdf : ListeIdf '|' IDF {
            savedNumCol = @3.first_column;
            if(checkNoDoubleDeclaration($3))
                insert($3, 0, 0);
         }
         | IDF {
            savedNumCol = @1.first_column;
            if(checkNoDoubleDeclaration($1))
                insert($1, 0, 0);
         }; 

Instruction : Instruction Assignement ';'
     | Assignement ';'
     | Instruction Boucle
     | Boucle
     | Instruction DO_IF_Cond 
     | DO_IF_Cond;

Assignement : IDF ASSIGN Expression  {
                savedNumCol = @1.first_column;
                if(checkIsDeclared($1)){
                    savedNumCol = @2.first_column;
                    checkNotReassigningConstant($1);
                    checkTypeCompatAffect($1, search($1)->type, $3, "<--");
                }
            };

Boucle : FOR Assignement WHILE Val DO Instruction ENDFOR;

DO_IF_Cond : DO Assignement ':' IF '(' Condition ')' ENDIF
           | DO Assignement ':' IF '(' Condition ')' ELSE Instruction ENDIF
           | DO Instruction Assignement ':' IF '(' Condition ')' ENDIF
           | DO Instruction Assignement ':' IF '(' Condition ')' ELSE Instruction ENDIF
           | DO Instruction ':' IF '(' Condition ')' ENDIF
           | DO Instruction ':' IF '(' Condition ')' ELSE Instruction ENDIF;

Condition : '(' Condition ')'
          | '!' Condition
          | Condition '&' Condition
          | Condition '|' Condition
          | Expression OP_Comparison Expression  {
              savedNumCol = @2.first_column;
              checkTypeCompat($1, $2, $3);
          }

OP_Comparison : EQ {$$="=="}| NOT_EQ {$$="!="}| GRT {$$=">"}| GRT_EQ {$$=">="}| LESS {$$="<"}| LESS_EQ {$$="<="};

Expression : Val {
        $$ = $1;
        isLastReadAVal = 1;
    }
    | IDF {
        isLastReadAVal = 0;
        savedNumCol = @1.first_column;
        if(checkIsDeclared($1))
            $$ = search($1)->type;
    }
    | '(' Expression ')' {$$ = $2;}
    | Sign '(' Expression ')' {$$ = $3;}
    | Expression '+' Expression {
        $$ = $1;
        savedNumCol = @2.first_column;
        checkTypeCompat($1, "+", $3);
    }
    | Expression '-' Expression {
        $$ = $1;
        savedNumCol = @2.first_column;
        checkTypeCompat($1, "-", $3);
    }
    | Expression '*' Expression {
        $$ = $1;
        savedNumCol = @2.first_column;
        checkTypeCompat($1, "*", $3);
    }
    | Expression '/' Expression {
        $$ = $1;
        savedNumCol = @2.first_column;
        checkTypeCompat($1, "/", $3);
        checkNoDivisionByZero();
    };

Type : Pint {$$=0; decType=0;}
     | Pfloat {$$=1; decType=1;};

Val : Sign PintVal {
        $$ = 0; 
        savedVal = ($1==0) ? $2 : -$2;
    }
    | PintVal {
        $$ = 0; 
        savedVal = $1;
    }
    | Sign PfloatVal {
        $$ = 1;
        savedVal = ($1==0) ? $2 : -$2;
    }
    | PfloatVal {
        $$ = 1;
        savedVal = $1;
    };

Sign : '-' {$$=1;}| '+'{$$=0;};

%%
int yyerror(char* msg){
    numErrors++;
    double s = (1000.0*(clock() - start)) / CLOCKS_PER_SEC;
    printf("SyntaxError, Ln %d, Col %d: Unexpected '%s'.\n", numLn, numCol-yyleng, yytext);
    showLineHighlightError(numLn, numCol-yyleng);
    printf("===== Compilation stopped in %.2fms with %d error(s) =====\n", s, numErrors);
    return 1;
}
int main( int argc, char *argv[] ){
    start = clock();
    if (argc > 1){
        inputStream = fopen( argv[1], "r" );
        yyin = fopen( argv[1], "r" );
    }else{
        inputStream = stdin;
        yyin = stdin;
    }
    yyparse();
    return 0;
}