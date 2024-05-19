#include <stdio.h>
#include "main.h"
#include "stdlib.h"
#include "string.h"
#include "column.h"

int main() {
    char nom[15];
    DATAFRAME *cdataframe;
    COLUMN *colonne;
    int i;
    int créé = 0;
    int x=0;
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
            printf("\nListe des fonctions :\n[0] : sortir du programme\n[1] : Créer une colonne\n[2] : Imprimer le dataframe en entier\n[3] : Imprimer le dataframe jusqu'à une certaine ligne\n[4] : Ajouter une ligne de valeur au cdataframe\n[5] : Ajouter une valeur à une colonne\n[6] : Supprimer une ligne du dataframe\n[7] : Remplir en dur\n[8] : Renommer une colonne\n[9] : Imprimer le dataframe mieux\n[10] : Supprimer une colonne du data\n[11] : Rechercher une valeur dans le dataframe\n[12] : Accéder à une valeur avec ses coordonnées\n[13] : Afficher les noms des colonnes\n[14] : Afficher le nombre de lignes\n[15] : Afficher le nombre de colonnes\n[16] : Nombre d'occurences de x\n[17] : Nombre d'occurences de valeurs plus grandes que x\n[18] : Nombres d'occurences de valeurs plus petites que x\n");
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
                printf("Sélectionner le nombre de lignes à print ");
                scanf("%d", &i);
                print_dataframe_partiel(*cdataframe,i);
            }
            if (call==4){
                int pt[cdataframe->taillelogique];
                for (i=0;i<cdataframe->taillelogique;i++){
                    printf("Entrez la valeur à entrer dans la colonne : '%s'", cdataframe->donnees[i]->name_column);
                    scanf("%d",&pt[i]);
                }
                ajouter_ligne(*cdataframe,pt);
            }
            if (call==5){
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
            if (call==6){
                printf("Entrez le numéro de la ligne à supprimer : ");
                scanf("%d",&i);
                supprimer_ligne(*cdataframe,i);
            }
            if (call==7){
                remplir_en_dur(cdataframe);
            }
            if (call==8){
                for (i=0;i<cdataframe->taillelogique;i++){
                    printf("[%d]  %s\n",i,cdataframe->donnees[i]->name_column);
                }
                printf("Entrez le numéro de la colonne à entrer : ");
                scanf("%d",&i);
                printf("Entrez le nom par lequel vous voulez remplacer : '%s' : ",cdataframe->donnees[i]->name_column);
                scanf("%s",&nom);
                renommer_colonne(cdataframe->donnees[i],nom);
            }
            if(call==9){
                print_dataframe2(*cdataframe);
            }
            if(call==10){
                printf("Entrez le numéro de la colonne à supprimer");
                scanf("%d",&i);
                supprimer_colonne(cdataframe,i);
            }
            if(call ==11){
                printf("Entrez une valeur à rechercher : \n");
                scanf("%d",&i);
                if (chercher_valeur(*cdataframe,i)==1){
                    printf("La valeur existe bien dans le dataframe\n");
                }
                else{
                    printf("La valeur n'existe pas dans le dataframe\n");
                }
            }
            if(call==12) {
                int j;
                int k;
                printf("Entrez le numéro de la colonne : \n");
                scanf("%d", &i);
                printf("Entrez le numéro de la ligne : \n");
                scanf("%d", &j);
                acceder_valeur(*cdataframe, i, j);
                printf("Que voulez vous faire de cette valeur :\n[1] La remplacer\n[2] Rien\n");
                scanf("%d", &k);
                if (k == 1) {
                    printf("Par quelle valeur voulez vous la remplacer ?\n");
                    scanf("%d", &k);
                    changer_valeur(*cdataframe, i, j, k);
                }
            }
            if(call==13) {
                int u,t;
                for (u = 0; u < cdataframe->taillelogique; u++) {
                    printf("%s", cdataframe->donnees[u]->name_column);
                    for (t = strlen(cdataframe->donnees[u]->name_column); t < 15; t++) {
                        printf(" ");
                    }
                }
            }
            if(call==14){
                int max=0;
                for (i=0;i<cdataframe->taillelogique;i++){
                    if(max<cdataframe->donnees[i]->taille_logique_tableau){
                        max=cdataframe->donnees[i]->taille_logique_tableau;
                    }
                }
                printf("Il y a %d lignes au dataframe\n",max);
            }
            if(call==15){
                printf("Il y a %d colonnes au dataframe\n",cdataframe->taillelogique);
            }
            if(call==16){

                printf("Entrez la valeur dont on va compter les occurences : ");
                scanf("%d",&x);
                printf("Il y a %d occurences de la valeur %d dans le dataframe", nbr_occ(*cdataframe,x),x);
            }
            if (call==17){

                printf("Entrez la valeur dont on va compter les occurences de valeurs plus grandes : ");
                scanf("%d",&x);
                printf("Il y a %d occurences de valeurs plus grandes que %d dans le dataframe", nbr_plus(*cdataframe,x),x);
            }
            if(call==18){
                printf("Entrez la valeur dont on va compter les occurences de valeurs plus petites : ");
                scanf("%d",&x);
                printf("Il y a %d occurences de valeurs plus petites que %d dans le dataframe", nbr_moins(*cdataframe,x),x);
            }
            if (call==19){
                printf("Sélectionner le nombre de colonnes à print ");
                scanf("%d", &i);
                print_dataframe_partielcol(*cdataframe,i);
            }
        }
    }
    return 0;
}
