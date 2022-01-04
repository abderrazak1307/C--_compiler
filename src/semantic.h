#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HighlightErrors 1

/********************* Type Declaration *********************/
typedef struct element *list;
typedef struct element{
    char* nom;
    int type;
    int nature;
    struct element *svt;
} element;

typedef struct element2 *list2;
typedef struct element2{
    char* nom;
    float value;
    struct element2 *svt;
} element2;

/****************** Variable Declaration *******************/
list SymbolTable = NULL;
list2 ValueTable = NULL;
int size = 0;

extern int numLn;
extern int numCol;
extern int numErrors;
extern FILE* inputStream;

int savedNumCol=1;
int decType=0;
int varRecents=0;

list2 searchValue(char* x);
void updateValue(char* nom, float value);


/********************* Base Functions *********************/
list creer_element(char* nom, int type, int nature){
    list node = (list) malloc(sizeof(element));
    node->nom = (char*)malloc((strlen(nom)+1) * sizeof(char));
    strcpy(node->nom, nom);
    node->type = type;
    node->nature = nature;
    node->svt = NULL;

    return node;
}
void insert(char* nom, int type, int nature){
    list x = creer_element(nom, type, nature);
    size++;
    if(nature==0) varRecents++; // if inserting a variable, keep track to update type later on
    // only one item in the list
    if (SymbolTable == NULL){
        SymbolTable = x;
    }
    else{
        list p = SymbolTable;
        while (p->svt!=NULL) p = p->svt; // skip to last element     
        p->svt = x; // add to end of queue
    }
}
void updateValue(char* nom, float value){
    if(searchValue(nom) != NULL){
        searchValue(nom)->value = value;
    }
    else{
        list2 x = (list2) malloc(sizeof(element2));
        x->nom = (char*)malloc((strlen(nom)+1) * sizeof(char));
        strcpy(x->nom, nom);
        x->value = value;
        x->svt = NULL;
        if (ValueTable == NULL){
            ValueTable = x;
        }
        else{
            list2 p = ValueTable;
            while (p->svt!=NULL) p = p->svt; // skip to last element     
            p->svt = x; // add to end of queue
        }
    }
}

list search(char* x){
    list p = SymbolTable;
    list result = NULL;
    while(p!=NULL && result==NULL){
        if(strcmp(p->nom, x) == 0){
            result=p;
        }
        p = p->svt;
    }
    return result;
}
list2 searchValue(char* x){
    list2 p = ValueTable;
    list2 result = NULL;
    while(p!=NULL && result==NULL){
        if(strcmp(p->nom, x) == 0){
            result=p;
        }
        p = p->svt;
    }
    return result;
}

char currentLineBuffer[256];
int currentLine=1;
int currentLineLength=0;
int x=0;
void showLineHighlightError(int ln, int col){
    if(HighlightErrors == 0 || inputStream == NULL) return;

    while(currentLine <= ln){
        char c;
        while ((c = fgetc(inputStream)) != EOF && currentLine<=ln){
            if(c=='\n'){
                currentLine++;
                currentLineLength = x;
                x = 0;
                break;
            }else{
                currentLineBuffer[x++] = (char)c;
            }
        }
    }

    for(int i = 0; i < currentLineLength; i++)
        printf("%c", currentLineBuffer[i]);
    printf("\n");
    for(int i = 0; i < col - 1; i++)
        printf("_");
    printf("^\n\n");
}

void afficher(){
    list p = SymbolTable;
    printf("********************* Table de Symboles ********************\n");
    printf("+----------------------------------------------------------+\n");
    printf("|    Nom       |     Type    |    Nature   |    Valeur     |\n");
    printf("+----------------------------------------------------------+\n");
    while (p != NULL){
        list2 elem = searchValue(p->nom);
        if(elem != NULL){
            if(p->type == 0)
                printf("| %12s | %11s | %11s | %13d |\n", p->nom, "Pint", p->nature==0?"var":"const", (int)(elem->value));
            else
                printf("| %12s | %11s | %11s | %13.2f |\n", p->nom, "Pfloat", p->nature==0?"var":"const", elem->value);
        }else
            printf("| %12s | %11s | %11s | %13s |\n", p->nom, p->type==0?"Pint":"Pfloat", p->nature==0?"var":"const", "undefined");
        p = p->svt;
    }
    printf("+----------------------------------------------------------+\n");
}

/********************* ROUTINES *********************/
void showLineHighlightError(int ln, int col);
int checkNoDoubleDeclaration(char* variable){
    if(search(variable) != NULL){
        numErrors++;
        printf("SemanticError, Ln %d, Col %d: '%s' was already declared in this scope\n", numLn, savedNumCol, variable);
        showLineHighlightError(numLn, savedNumCol);
        return 0;
    }
    return 1;
}
int checkNotReassigningConstant(char* variable){
    if(search(variable)->nature == 1){
        numErrors++;
        printf("SemanticError, Ln %d, Col %d: Assignement of constant variable '%s'\n", numLn, savedNumCol, variable);
        showLineHighlightError(numLn, savedNumCol);
        return 0;
    }
    return 1;
}
int checkIsDeclared(char* variable){
    if(search(variable) == NULL){
        numErrors++;
        printf("SemanticError, Ln %d, Col %d: '%s' was not declared in this scope\n", numLn, savedNumCol, variable);
        showLineHighlightError(numLn, savedNumCol);
        return 0;
    }
    return 1;
}
int checkTypeCompat(int type, char* token, int type2){
    if(type != type2){
        numErrors++;
        printf("SemanticError, Ln %d, Col %d: Type incompatibality, %s %s %s\n", numLn, savedNumCol, type==0?"Pint":"Pfloat", token, type2==0?"Pint":"Pfloat");
        showLineHighlightError(numLn, savedNumCol);
        return 0;
    }
    return 1;
}
int checkTypeCompatAffect(char* variable, int type, int type2, char* op){
    if(type != type2){
        numErrors++;
        printf("SemanticError, Ln %d, Col %d: Type incompatibality, %s(%s) %s %s\n", numLn, savedNumCol, variable, type==0?"Pint":"Pfloat", op, type2==0?"Pint":"Pfloat");
        showLineHighlightError(numLn, savedNumCol);
        return 0;
    }
    return 1;
}
int checkNoDivisionByZero(float value){
    if(value==0){
        numErrors++;
        printf("SemanticError, Ln %d, Col %d: Division by zero not allowed\n", numLn, savedNumCol);
        showLineHighlightError(numLn, savedNumCol);
        return 0;
    }
    return 1;
}
void MAJRecentVariables(){
    list p = SymbolTable;
    int i = varRecents;
    while (p != NULL && size-i>0){
        i++;
        p = p->svt;
    }
    while(p != NULL){
        p->type = decType;
        p = p->svt;
    }
    varRecents=0;
}