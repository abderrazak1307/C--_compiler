%{
#include <stdio.h>
#include <time.h>
#define YYERROR_VERBOSE 1

clock_t start;
double s;

extern int numLn;
extern int numCol;
extern int numErrors;
extern FILE* yyin;

int yyerror(char* msg);
extern int yylex();
extern int yytext;
extern int yyleng;
%}

%union {
int pint;
float pfloat;
char* string;
}
%start S
%token Program PDEC PINST Begin End FOR WHILE DO ENDFOR IF ELSE define Pint Pfloat
%token GRT GRT_EQ EQ NOT_EQ LESS_EQ LESS ASSIGN
%token<string> IDF
%token<pint> PintVal
%token<pfloat> PfloatVal

%left '*' '/'
%left '+' '-'

%left GRT GRT_EQ EQ NOT_EQ LESS_EQ LESS

%left '!'
%left '&'
%left '|'
%%
S : Program IDF PDEC PartieDeclaration PINST Begin PartieInstructions End {
    s = (1000.0*(clock() - start)) / CLOCKS_PER_SEC;
    printf("\n===== Compilation finished in %.2fms with %d error(s) =====\n", s, numErrors); YYACCEPT; 
};

PartieDeclaration : Declaration {printf("Partie Declaration Done\n");};

PartieInstructions : Instruction {printf("Partie Instructions Done\n");};

Declaration : define Type IDF '=' Val ';' Declaration
            | VarDec Declaration
            | ;

VarDec : IDF '|' VarDec
       | IDF ':' Type ';';

Instruction : IDF ASSIGN Expression ';' Instruction
     | Boucle Instruction
     | DO_IF_Cond Instruction
     | ;

Boucle : FOR IDF ASSIGN Expression WHILE Val DO Instruction ENDFOR;

DO_IF_Cond : DO Instruction ':' IF '(' Condition ')'
           | DO Instruction ':' IF '(' Condition ')' ELSE Instruction;

Expression : '(' Expression ')'
    | Expression OP_Arithmitique Expression
    | Val
    | IDF;

Condition : '(' Condition ')'
          | '!' Condition
          | Condition '&' Condition
          | Condition '|' Condition
          | Expression OP_Comparison Expression;

OP_Comparison : EQ | NOT_EQ | GRT | GRT_EQ | LESS | LESS_EQ;

OP_Arithmitique : '+' | '-' | '*' | '/';

Type : '(' Type ')' | Pint | Pfloat;

Val : '(' Val ')' | Sign PintVal | Sign PfloatVal;

Sign : '-' | '+' | ;

%%
int yyerror(char* msg){
    numErrors++;
    s = (1000.0*(clock() - start)) / CLOCKS_PER_SEC;
    printf("SyntaxError, Ln %d, Col %d: Unexpected '%s'\n", numLn, numCol-yyleng, yytext);
    // or maybe: printf("SyntaxError, Ln %d, Col %d: %s\n", numLn, numCol-yyleng, msg);
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