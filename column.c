#include <stdio.h>
#include "main.h"
#include "stdlib.h"
#include "string.h"


COLUMN * create_column(char *title) {
    COLUMN *col = (COLUMN *) malloc((sizeof(COLUMN)));
    col->taille_physique_tableau = 0;
    col->taille_logique_tableau = 0;
    col->donnees = NULL;

    col->name_column = (char *) malloc((strlen(title) + 1) * sizeof(char));
    strcpy(col->name_column, title);
    return col;
}

int inservalue (COLUMN *nom, int valeur) {
    if (nom->taille_physique_tableau == 0) {
        nom->donnees = malloc(256 * sizeof(int));
        nom->taille_physique_tableau = 256;
    } else if (nom->taille_logique_tableau == nom->taille_physique_tableau) {
        nom->donnees = realloc(nom->donnees, (nom->taille_physique_tableau + 256) * sizeof(int));
        nom->taille_physique_tableau += 256;
    }
    if (nom->donnees == NULL) { return 0; }

    nom->donnees[nom->taille_logique_tableau] = valeur;
    nom->taille_logique_tableau++;

    return 1;
}

void delete_column(COLUMN **col){
    free((*col)->donnees);
    free(*col);
    *col = NULL;
}
void print_col(COLUMN* col){
    int i;
    for (i = 0; i < col->taille_logique_tableau; i++)
    {
        printf("\n[%d] : %d", i, col->donnees[i]);
    }
}
int number_occ(COLUMN* col, int number){
    int i,n;
    n=0;
    for (i = 0; i < col->taille_logique_tableau; i++)
    {
        if (col->donnees[i]== number )
        {
            n++;
        }
    }
    return n;
}
int val_pos(COLUMN* col, int x){
    return col->donnees[x];
}
int number_sup(COLUMN* col, int number){
    int i,n;
    n=0;
    for (i = 0; i < col->taille_logique_tableau; i++)
    {
        if (col->donnees[i]> number )
        {
            n++;
        }
    }
    return n;
}
int number_inf(COLUMN* col, int number){
    int i,n;
    n=0;
    for (i = 0; i < col->taille_logique_tableau; i++)
    {
        if (col->donnees[i]< number )
        {
            n++;
        }
    }
    return n;
}
COLUMN *dataframe(){
    COLUMN *cdataframe;
    return cdataframe;
}
DATAFRAME * create_dataframe(){
    DATAFRAME* dataframe = (DATAFRAME *) malloc((sizeof(DATAFRAME )));
    dataframe->taillelogique = 0;
    dataframe->taillephysique = 0;
    dataframe->donnees=NULL;
    return dataframe;
}

int ajouter_colonne_au_dataframe(COLUMN* nom, DATAFRAME *dataframe){
    if (dataframe->taillephysique == 0) {
        dataframe->donnees = malloc(10 * sizeof(COLUMN*));
        dataframe->taillephysique = 10;
    } else if (dataframe->taillelogique == dataframe->taillephysique) {
        dataframe->donnees = realloc(dataframe->donnees, (nom->taille_physique_tableau + 10) * sizeof(COLUMN*));
        dataframe->taillephysique += 10;
    }
    if (dataframe->donnees == NULL) { return 0; }

    dataframe->donnees[dataframe->taillelogique] = nom;
    dataframe->taillelogique++;
    printf("\noui %d\n", dataframe->taillelogique);
    return 1;
}

void print_dataframe(DATAFRAME dataframe){
    int k;
    for (k = 0; k < dataframe.taillelogique; k++){
        printf("\n%s", dataframe.donnees[k]->name_column);
        print_col(dataframe.donnees[k]);
    }
    printf("\n");
}