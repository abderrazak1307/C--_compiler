%{
#include <stdio.h>
#include <time.h>
#include "semantic.h"

clock_t start;
FILE* inputStream;
extern FILE* yyin;

extern int numLn;
extern int numCol;
extern int savedNumCol;
extern int numErrors;

extern int yylex();
extern int yytext;
extern int yyleng;
int yyerror(char* msg);

extern int decType;
%}
%locations
%union {
    char* string;
    int pint;
    float pfloat;
    struct expressionData {
            int type;
            float value;
            int hasError;
    } expressionData;
}

%start S
%token Program PDEC PINST Begin End FOR WHILE DO ENDFOR IF ELSE ENDIF define ASSIGN Pint Pfloat GRT GRT_EQ EQ NOT_EQ LESS_EQ LESS
%token<string> IDF
%token<pint> PintVal //type==0
%token<pfloat> PfloatVal //type==1

%type<string> OP_Comparison;
%type<pint> Type Sign;
%type<expressionData> Expression Val Assignement;

%left '|'
%left '&'
%left '!'

%left GRT GRT_EQ EQ NOT_EQ LESS_EQ LESS

%left '+' '-'
%left '*' '/'

%%
S : Header PartieDeclaration PartieInstructions {
    double duration = (1000.0*(clock() - start)) / CLOCKS_PER_SEC;
    printf("===== Compilation finished in %.2fms with %d error(s) =====\n\n", duration, numErrors);
    afficher();
    YYACCEPT;
};

Header : Program IDF;

PartieDeclaration : PDEC Declaration;

PartieInstructions : PINST Begin Instruction End;

Declaration : Declaration define Type IDF '=' Val ';' {
                savedNumCol = @4.first_column;
                if(checkNoDoubleDeclaration($4)){
                    savedNumCol = @5.first_column;
                    if(checkTypeCompatAffect($4, $3, $6.type, "=")){
                        insert($4, decType, 1);
                        updateValue($4, $6.value);
                    }
                }
            }
            | define Type IDF '=' Val ';' {
                savedNumCol = @3.first_column;
                if(checkNoDoubleDeclaration($3)){
                    savedNumCol = @4.first_column;
                    if(checkTypeCompatAffect($3, $2, $5.type, "=")){
                        insert($3, decType, 1);
                        updateValue($3, $5.value);
                    }
                }
            }
            | Declaration ListeIdf ':' Type ';' {
                MAJRecentVariables();
            }
            | ListeIdf ':' Type ';' {
                MAJRecentVariables();
            };            

ListeIdf : ListeIdf '|' IDF {
            savedNumCol = @3.first_column;
            if(checkNoDoubleDeclaration($3)){
                insert($3, -1, 0);
                updateValue($3, 0);
            }
         }
         | IDF {
            savedNumCol = @1.first_column;
            if(checkNoDoubleDeclaration($1)){
                insert($1, -1, 0);
                updateValue($1, 0);
            }
         }; 

Instruction : Instruction Assignement ';'
     | Assignement ';'
     | Instruction Boucle
     | Boucle
     | Instruction DO_IF_Cond 
     | DO_IF_Cond;

Assignement : IDF ASSIGN Expression  {
                savedNumCol = @1.first_column;
                $$.type = $3.type;
                $$.value = $3.value;
                $$.hasError = $3.hasError;
                if(checkIsDeclared($1)){
                    savedNumCol = @2.first_column;
                    if(checkNotReassigningConstant($1) && checkTypeCompatAffect($1, search($1)->type, $3.type, "<--") && $3.hasError==0){
                        updateValue($1, $3.value);
                    }
                }
            };

Boucle : FOR Assignement WHILE Val {
            savedNumCol = @3.first_column;
            checkTypeCompat($2.type, "WHILE", $4.type);
        } DO Instruction ENDFOR ;

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
              checkTypeCompat($1.type, $2, $3.type);
          }

OP_Comparison : EQ {$$="=="}| NOT_EQ {$$="!="}| GRT {$$=">"}| GRT_EQ {$$=">="}| LESS {$$="<"}| LESS_EQ {$$="<="};

Expression : Val {
        $$.type = $1.type;
        $$.value = $1.value;
    }
    | IDF {
        savedNumCol = @1.first_column;
        if(checkIsDeclared($1)){
            $$.type = search($1)->type;
            $$.value = searchValue($1)->value;
            $$.hasError = 0;
        }
    }
    | '(' Expression ')' {
        $$.type = $2.type;
        $$.value = $2.value;
        $$.hasError = $2.hasError;
    }
    | Sign '(' Expression ')' {
        $$.type = $3.type;
        $$.value = ($1==0) ? $3.value : -$3.value;
        $$.hasError = $3.hasError;
    }
    | Expression '+' Expression {
        savedNumCol = @2.first_column;
        $$.type = $1.type;
        if(checkTypeCompat($1.type, "+", $3.type)){
            $$.value = $1.value + $3.value;
            $$.hasError = $1.hasError || $3.hasError;
        }else
            $$.hasError = 1;
    }
    | Expression '-' Expression {
        savedNumCol = @2.first_column;
        $$.type = $1.type;
        if(checkTypeCompat($1.type, "-", $3.type)){
            $$.value = $1.value - $3.value;
            $$.hasError = $1.hasError || $3.hasError;
        }else
            $$.hasError = 1;
    }
    | Expression '*' Expression {
        savedNumCol = @2.first_column;
        $$.type = $1.type;
        if(checkTypeCompat($1.type, "*", $3.type)){
            $$.value = $1.value * $3.value;
            $$.hasError = $1.hasError || $3.hasError;
        }else
            $$.hasError = 1;
        
    }
    | Expression '/' Expression {
        savedNumCol = @2.first_column;
        $$.type = $1.type;
        if(checkTypeCompat($1.type, "/", $3.type) && checkNoDivisionByZero($3.value)){
            if($1.type == 0)$$.value = ((int)$1.value)/((int)$3.value);// division entiere
            else $$.value = $1.value/$3.value; // division réelle
            $$.hasError = $1.hasError || $3.hasError;
        }else
            $$.hasError = 1;
    };

Type : Pint {$$=0; decType=0;}
     | Pfloat {$$=1; decType=1;};

Val : Sign PintVal {
        $$.type = 0; 
        $$.value = ($1==0) ? $2 : -$2;
        $$.hasError = 0;
    }
    | PintVal {
        $$.type = 0;
        $$.value = $1;
        $$.hasError = 0;
    }
    | Sign PfloatVal {
        $$.type = 1;
        $$.value = ($1==0) ? $2 : -$2;
        $$.hasError = 0;
    }
    | PfloatVal {
        $$.type = 1;
        $$.value = $1;
        $$.hasError = 0;
    };

Sign : '-' {$$=1;}| '+'{$$=0;};

%%
int yyerror(char* msg){
    numErrors++;
    double s = (1000.0*(clock() - start)) / CLOCKS_PER_SEC;
    printf("SyntaxError, Ln %d, Col %d: Unexpected '%s'.\n", numLn, numCol-yyleng, yytext);
    showLineHighlightError(numLn, numCol-yyleng);
    printf("===== Compilation stopped in %.2fms with %d error(s) =====\n\n", s, numErrors);
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