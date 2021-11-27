/*
@author
- Abderrazak BRAHIM
- L3 ISIL A (TD G2, TP G3)
- 191932019713
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1- Déclarer une structure de données « élément »
typedef struct element *list;
typedef struct element{
    char* nom;
    int taille;
    struct element *svt;
} element;

list lire_element(){
    list node = (list) malloc(sizeof(element));
    // lire chaine dans un tableau temporaire
    char temp[100];
    gets(temp);

    // reserver l'espace necessaire et recopier la chaine temporaire dans un noeud de la liste chainée
    node->nom = (char*)malloc((strlen(temp)+1) * sizeof(char));
    strcpy(node->nom, temp);
    node->taille = strlen(temp);
    node->svt = NULL;

    return node;
}

// 3-a ajouter en tête de liste chainée
void ajouter_tete(list* ListElts, list x){
    
}
// 3- ajouter un element dans la liste chainée
void ajouter_elem(list* ListElts, list x, int pos){
    // only one item in the list
    if (*ListElts == NULL || pos==1){
        x->svt = *ListElts;
        *ListElts = x;
    }
    else{
        list p = *ListElts;
        while (p->svt!=NULL && pos>=1){
            p = p->svt;
            pos--;
        }
        x->svt= p->svt;
        p->svt = x;
    }
}
// 4- Rechercher un élément dans la liste selon le champ « Nom »
int rechercherElem(list ListElts, char x[100]){
    list p = ListElts;
    int found = 0;
    while(p!=NULL && found==0){
        if(strcmp(p->nom,x) == 0)found=1;
        p = p->svt;
    }
    return found;
}

// 5- Afficher tous les éléments de la liste
void afficherListe(list ListElts){
    list p = ListElts;
    while (p != NULL){
        printf("%s(%d)", p->nom, p->taille);
        if (p->svt != NULL) printf(" > ");
        p = p->svt;
    }
}

int main(){
    // 2- Declarer une liste chainee « ListElts »
    list ListElts;

    int n=0;
    printf("- Enter the length of the linked list: ");
    scanf("%d", &n);
    getc(stdin); // pour regler un probleme avec scanf
    if(n<=0) return 0;

    printf("- Donner le 1er element: ");
    ListElts = lire_element();
    list p = ListElts;
    for (int i=1; i <n; i++){
        printf("- Donner le %deme element: ", i+1);
        list elem = lire_element();
        p->svt = elem;
        p = p->svt;
    }

    // 3- Ajouter un element dans la liste chainée
    printf("\n- Donner l'element a inserer dans la liste (laisser vide sinon): ");
    list x = lire_element();
    if(strcmp(x->nom,"") != 0){
        int pos;
        do{
            printf("- Donner la position dans laquelle voulez vous l'inserer (1: debut, %d:fin): ", n);
            scanf("%d",&pos);
            getc(stdin); // pour regler un probleme avec scanf
        }while(pos<1 || pos>n);
        ajouter_elem(&ListElts, x, pos);
    }
    // 4- Rechercher un élément dans la liste selon le champ « Nom »
    printf("\n- Donner l'element a rechercher dans la liste: ");
    char temp[100];
    gets(temp);
    if(rechercherElem(ListElts, temp) == 1){
        printf("> Element '%s' existe dans la liste", temp);
    }else{
        printf("> Element '%s' n'existe pas dans la liste", temp);
    }

    // 5- Afficher tous les éléments de la liste
    printf("\n\nAffichage de la liste:\n");
    afficherListe(ListElts);
    printf("\n");
    return 0;
}