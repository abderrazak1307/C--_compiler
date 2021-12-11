%{
#include <stdio.h>
#include "routine.h"
#include <time.h>
#define YYERROR_VERBOSE 1

clock_t start;

extern int numLn;
extern int numCol;
extern int numErrors;
extern FILE* yyin;
extern list TS;

int yyerror(char* msg);
extern int yylex();
extern int yytext;
extern int yyleng;

int decType=0;
int varRecents=0;
double lastSavedVal;
int lastReadVal=0;
%}

%union {
int pint;
float pfloat;
char* string;
}
%start S
%token Program PDEC PINST Begin End FOR WHILE DO ENDFOR IF ELSE ENDIF define ASSIGN Pint Pfloat
%token GRT GRT_EQ EQ NOT_EQ LESS_EQ LESS
%token<string> IDF
%token<pint> PintVal //type==0
%token<pfloat> PfloatVal //type==1

%type<pint> Expression;
%type<pint> Val;
%type<pint> Type;
%type<pint> Sign;

%left '*' '/'
%left '+' '-'

%left GRT GRT_EQ EQ NOT_EQ LESS_EQ LESS

%left '!'
%left '&'
%left '|'
%%
S : Program IDF PDEC PartieDeclaration PINST Begin PartieInstructions End {
    double duration = (1000.0*(clock() - start)) / CLOCKS_PER_SEC;
    printf("\n===== Compilation finished in %.2fms with %d error(s) =====\n", duration, numErrors);
    printf("\nTable des Symboles genere:\n");
    afficher();
    YYACCEPT;
};

PartieDeclaration : Declaration;

PartieInstructions : Instruction;

Declaration : Declaration define Type IDF '=' Val ';' {
                if(rechercher($4) != NULL) printError(1, $4);
                else{
                    if ($3 != $6){
                        printErrorTypeCompatAffect($4, $3, $6);
                    }else
                        insert($4, decType, 1);
                }
            }
            | define Type IDF '=' Val ';' {
                if(rechercher($3) != NULL) printError(1, $3);
                else{
                    if ($2 != $5){
                        printErrorTypeCompatAffect($3, $2, $5);
                    }else
                        insert($3, decType, 1);
                }
            }
            | Declaration ListeVar ':' Type ';' {
                MAJRecentVariables(varRecents, decType);
                varRecents=0;
            }
            | ListeVar ':' Type ';' {
                MAJRecentVariables(varRecents, decType);
                varRecents=0;
            };            

ListeVar : ListeVar '|' IDF {
             if(rechercher($3) != NULL) printError(1, $3);
             else{
                insert($3, 0, 0);
                varRecents++;
             }
         }
         | IDF {
             if(rechercher($1) != NULL) printError(1, $1);
             else{
                insert($1, 0, 0);
                varRecents++;
             }
         }; 

Instruction : Instruction Assignement ';'
     | Assignement ';'
     | Instruction Boucle
     | Boucle
     | Instruction DO_IF_Cond 
     | DO_IF_Cond;

Assignement : IDF ASSIGN Expression  {
                if(rechercher($1) == NULL)printError(0, $1);
                else if(rechercher($1)->nature == 1) printError(2, $1);
                else{
                    if(rechercher($1)->type!=$3) printErrorTypeCompatAffect(rechercher($1)->nom, rechercher($1)->type, $3);
                }
            };

Boucle : FOR Assignement WHILE Val DO Instruction ENDFOR;

DO_IF_Cond : DO Instruction ':' IF '(' Condition ')' ENDIF
           | DO Instruction ':' IF '(' Condition ')' ELSE Instruction ENDIF;

Condition : '(' Condition ')'
          | '!' Condition
          | Condition '&' Condition
          | Condition '|' Condition
          | Expression OP_Comparison Expression;

OP_Comparison : EQ | NOT_EQ | GRT | GRT_EQ | LESS | LESS_EQ;

Expression : Val {
        $$ = $1;
        lastReadVal = 1;
    }
    | IDF {
        lastReadVal = 0;
        if(rechercher($1) == NULL){
            printError(0, $1);
            $$ = 1;
        }
        else $$ = rechercher($1)->type;
    }
    | '(' Expression ')' {$$ = $2;}
    | Sign '(' Expression ')' {$$ = $3;}
    | Expression '+' Expression {
        $$ = $1;
        if($1!=$3) printErrorTypeCompat("+", $1, $3);
    }
    | Expression '-' Expression {
        $$ = $1;
        if($1!=$3) printErrorTypeCompat("-", $1, $3);
    }
    | Expression '*' Expression {
        $$ = $1;
        if($1!=$3) printErrorTypeCompat("*", $1, $3);
    }
    | Expression '/' Expression {
        $$ = $1;
        if($1!=$3) printErrorTypeCompat("/", $1, $3);
        else {
            if(lastSavedVal==0 && lastReadVal==1){
                printError(3, "/");
            }
        }
    };

Type : Pint {$$=0; decType=0;}
     | Pfloat {$$=1; decType=1;};

Val : Sign PintVal {
        $$ = 0; 
        lastSavedVal = ($1==0) ? $2 : -$2;
    }
    | PintVal {
        $$ = 0; 
        lastSavedVal = $1;
    }
    | Sign PfloatVal {
        $$ = 1;
        lastSavedVal = ($1==0) ? $2 : -$2;
    }
    | PfloatVal {
        $$ = 1;
        lastSavedVal = $1;
    };

Sign : '-' {$$=1;}| '+'{$$=0;};

%%
int yyerror(char* msg){
    numErrors++;
    double s = (1000.0*(clock() - start)) / CLOCKS_PER_SEC;
    printf("SyntaxError, Ln %d, Col %d: Unexpected '%s'\n", numLn, numCol-yyleng, yytext);
    printf("\n===== Compilation stopped in %.2fms with %d error(s) =====\n", s, numErrors);
    return 1;
}
int main( int argc, char *argv[] ){
    start = clock();

    if (argc > 1) yyin = fopen( argv[1], "r" );
    else yyin = stdin;

    yyparse();

    return 0;
}