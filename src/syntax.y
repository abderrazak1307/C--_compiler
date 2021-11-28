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

int decType;
%}

%union {
int pint;
float pfloat;
char* string;
}
%start S
%token Program PDEC PINST Begin End FOR WHILE DO ENDFOR IF ELSE ENDIF define Pint Pfloat
%token GRT GRT_EQ EQ NOT_EQ LESS_EQ LESS ASSIGN
%token<string> IDF
%token<pint> PintVal //type==0
%token<pfloat> PfloatVal //type==1

%left '*' '/'
%left '+' '-'

%left GRT GRT_EQ EQ NOT_EQ LESS_EQ LESS

%left '!'
%left '&'
%left '|'
%%
S : Program IDF PDEC PartieDeclaration PINST Begin PartieInstructions End {
    double s = (1000.0*(clock() - start)) / CLOCKS_PER_SEC;
    printf("\n===== Compilation finished in %.2fms with %d error(s) =====\n", s, numErrors);
    afficher();
};

PartieDeclaration : Declaration {printf("Partie Declaration Done\n");};

PartieInstructions : Instruction {printf("Partie Instructions Done\n");};

Declaration : define Type IDF '=' Val ';' Declaration {
                if(rechercher($3) != NULL) printf("ca existe mec deja mec '%s'\n",$3);
                else insert($3, decType, 1);
            };
            | define Type IDF '=' Val ';' {
                if(rechercher($3) != NULL) printf("ca existe mec deja mec '%s'\n",$3);
                else insert($3, decType, 1);
            };
            | ListeVar ':' Type ';' Declaration
            | ListeVar ':' Type ';';            

ListeVar : IDF '|' ListeVar {
             if(rechercher($1) != NULL) printf("ca existe mec deja mec '%s'\n",$1);
             else insert($1, decType, 0);
         };
         | IDF {
             if(rechercher($1) != NULL) printf("ca existe deja mec '%s'\n",$1);
             else insert($1, decType, 0);
         }; 

Instruction : Assignement Instruction 
     | Assignement
     | Boucle Instruction
     | Boucle
     | DO_IF_Cond Instruction
     | DO_IF_Cond;

Assignement : IDF ASSIGN Expression ';' {
             if(rechercher($1) == NULL) printf("ca n'existe pas mec '%s'\n",$1);
             else if(rechercher($1)->nature == 1) printf("c'est un constant mec '%s'\n",$1);
         };

Boucle : FOR IDF ASSIGN Expression WHILE Val DO Instruction ENDFOR;

DO_IF_Cond : DO Instruction ':' IF '(' Condition ')' ENDIF
           | DO Instruction ':' IF '(' Condition ')' ELSE Instruction ENDIF;

Expression : '(' Expression ')'
    | Expression OP_Arithmitique Expression
    | IDF {
        if(rechercher($1) == NULL) printf("ca n'existe pas mec '%s'\n",$1);
    };
    | Val;

Condition : '(' Condition ')'
          | '!' Condition
          | Condition '&' Condition
          | Condition '|' Condition
          | Expression OP_Comparison Expression;

OP_Comparison : EQ | NOT_EQ | GRT | GRT_EQ | LESS | LESS_EQ;

OP_Arithmitique : '+' | '-' | '*' | '/';

Type : '(' Type ')' 
     | Pint {
         decType = 0;
     }
     | Pfloat {
         decType = 1;
     };

Val : '(' Val ')' | Sign PintVal | Sign PfloatVal | PintVal | PfloatVal;

Sign : '-' | '+';

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