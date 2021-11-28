#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1- Déclarer une structure de données « élément »
typedef struct element *list;
typedef struct element{
    char* nom;
    int type;
    int nature;
    struct element *svt;
} element;

list TS = NULL;

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

// 5- Afficher tous les éléments de la liste
void afficher(){
    list p = TS;
    printf("Table des Symboles genere:\n");
    while (p != NULL){
        printf("%s(%s)(%s)", p->nom, p->type==0?"Pint":"Pfloat", p->nature==0?"var":"const");
        if (p->svt != NULL) printf("\n");
        p = p->svt;
    }
}