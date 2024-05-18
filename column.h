#ifndef PROJET_COLUMN_H
#define PROJET_COLUMN_H


COLUMN ** create_dataframe();
COLUMN * create_column(char*);
void inservalue (COLUMN*, int );
void delete_column(COLUMN **);
void print_col(COLUMN* );
void dataframe();
int number_inf(COLUMN* , int );
int val_pos(COLUMN* , int );
int number_sup(COLUMN* , int );
int number_occ(COLUMN* , int );
int ajouter_colonne_au_dataframe(COLUMN* , DATAFRAME* );
void print_dataframe(DATAFRAME);
void print_dataframe2(DATAFRAME);
void print_dataframe_partiel(DATAFRAME,int);
void print_col_partiel (COLUMN*, int);
void ajouter_ligne(DATAFRAME,int*);
void remplir_en_dur(DATAFRAME*);
void supprimer_ligne(DATAFRAME, int);
void renommer_colonne(COLUMN*,char*);
void supprimer_colonne(DATAFRAME*,int);
#endif //PROJET_COLUMN_H

