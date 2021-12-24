#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HighlightErrors 1

extern int numLn;
extern int numCol;
extern int numErrors;
extern FILE* inputStream;

int savedNumCol=1;
int decType=0;
int varRecents=0;
double savedVal;
int isLastReadAVal=0;

// 1- Déclarer une structure de données « élément »
typedef struct element *list;
typedef struct element{
    char* nom;
    int type;
    int nature;
    struct element *svt;
} element;

list TS = NULL;
int size = 0;

list creer_element(char* nom, int type, int nature){
    list node = (list) malloc(sizeof(element));
    // reserver l'espace necessaire et recopier la chaine temporaire dans un noeud de la liste chainée
    node->nom = (char*)malloc((strlen(nom)+1) * sizeof(char));
    strcpy(node->nom, nom);
    node->type = type;
    node->nature = nature;
    node->svt = NULL;

    return node;
}

// 3- ajouter un element dans la liste chainée
void insert(char* nom, int type, int nature){
    list x = creer_element(nom, type, nature);
    size++;
    // only one item in the list
    if (TS == NULL){
        TS = x;
    }
    else{
        list p = TS;
        while (p->svt!=NULL) p = p->svt;
        x->svt= p->svt;
        p->svt = x;
    }
}

// 4- Rechercher un élément dans la liste selon le champ « Nom »
list rechercher(char x[100]){
    list p = TS;
    list result = NULL;
    while(p!=NULL && result==NULL){
        if(strcmp(p->nom, x) == 0){
            result=p;
        }
        p = p->svt;
    }
    return result;
}

void afficher(){
    list p = TS;
    printf("\nTable des Symboles genere:\n");
    while (p != NULL){
        printf("%s : %s (%s)\n", p->nom, p->type==0?"Pint":"Pfloat", p->nature==0?"var":"const");
        p = p->svt;
    }
}

void showLineHighlightError(int ln, int col);

int checkNoDoubleDeclaration(char* variable){
    if(rechercher(variable) != NULL){
        numErrors++;
        printf("SemanticError, Ln %d, Col %d: '%s' was already declared in this scope\n", numLn, savedNumCol, variable);
        showLineHighlightError(numLn, savedNumCol);
        return 0;
    }
    return 1;
}
int checkNotReassigningConstant(char* variable){
    if(rechercher(variable)->nature == 1){
        numErrors++;
        printf("SemanticError, Ln %d, Col %d: Assignement of constant variable '%s'\n", numLn, savedNumCol, variable);
        showLineHighlightError(numLn, savedNumCol);
        return 0;
    }
    return 1;
}
int checkIsDeclared(char* variable){
    if(rechercher(variable) == NULL){
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
int checkNoDivisionByZero(){
    if(savedVal==0 && isLastReadAVal==1){
        numErrors++;
        printf("SemanticError, Ln %d, Col %d: Division by zero not allowed\n", numLn, savedNumCol);
        showLineHighlightError(numLn, savedNumCol);
        return 0;
    }
    return 1;
}
void MAJRecentVariables(int varRecents, int decType){
    list p = TS;
    while (p != NULL && size-varRecents>0){
        varRecents++;
        p = p->svt;
    }
    while(p != NULL){
        p->type = decType;
        p = p->svt;
    }
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