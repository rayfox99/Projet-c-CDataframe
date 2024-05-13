#ifndef PROJET_MAIN_H
#define PROJET_MAIN_H


typedef struct {
    char * name_column;
    int taille_physique_tableau;
    int taille_logique_tableau;
    int * donnees;
}COLUMN;

typedef struct {
    COLUMN** donnees;
    int taillelogique;
    int taillephysique;
}DATAFRAME;


#endif //PROJET_MAIN_H
