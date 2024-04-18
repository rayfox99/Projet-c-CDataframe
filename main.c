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

int inservalue (COLUMN *nom, int valeur){
    if (nom->donnees == NULL){
        nom->donnees = malloc(256*sizeof(int));
    }
    nom->donnees = &valeur;
}

int main() {
    COLUMN * colonne1;
    char * nom;
    nom="colonne1";
    colonne1= create_column(nom);

    return 0;
}
