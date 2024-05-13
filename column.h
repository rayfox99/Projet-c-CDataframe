//
// Created by gaspa on 26/04/2024.
//
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

#endif //PROJET_COLUMN_H

