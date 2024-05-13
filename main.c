#include <stdio.h>
#include "main.h"
#include "stdlib.h"
#include "string.h"
#include "column.h"

int main() {
    char nom[20];
    DATAFRAME *cdataframe;
    COLUMN *colonne;
    int créé = 0;
    int menu = 1;
    int call;
    while (menu == 1) {
        while (créé == 0) {
            printf("Liste des fonctions :\n[0] Créer un dataframe\n[1] : sortir du programme\n");
            scanf("%d", &call);
            if (call == 0) {
                cdataframe = create_dataframe();
                créé = 1;
            }
            if (call == 1) {
                menu = 0;
                créé = 1;
            }
        }
        while(menu == 1) {
            printf("\nListe des fonctions :\n[0] : sortir du programme\n[1] : Créer une colonne\n[2] : Imprimer le dataframe\n[3] : Ajouter une valeur à une colonne\n");
            scanf("%d", &call);
            if (call == 0) {
                menu = 0;
            }
            if (call == 1) {
                printf("Entrez le nom de votre colonne : ");
                scanf("%s", &nom);
                colonne=create_column(nom);
                ajouter_colonne_au_dataframe(colonne,cdataframe);
                printf("\n%d",cdataframe->taillelogique);
            }
            if (call==2){
                print_dataframe(*cdataframe);
            }
            if (call==3){
                int i;
                int value;
                printf("sélectionner une colonne : \n");
                for (i=0; i < cdataframe->taillelogique; i++){
                    printf("[%d] : %s\n", i, cdataframe->donnees[i]->name_column);
                }
                scanf("%d", &i);
                printf("Tapez la valeur à ajouter à la colonne '%s' : ", cdataframe->donnees[i]->name_column);
                scanf("%d", &value);
                inservalue(cdataframe->donnees[i], value);
            }
        }
    }
    return 0;
}

/*
    char * nom;
    int o;
    scanf("%d", &o);
    nom="colonne1";
    colonne = create_column(nom);
    printf("%s", colonne->name_column);
    cdataframe->donnees[0] = colonne;
    inservalue(colonne, o);
    print_col(colonne);
    return 0;
}
*/
