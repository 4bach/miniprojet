#ifndef TABLE_HACHAGE_H
#define TABLE_HACHAGE_H


typedef struct cell{
	int clef;
	//int num;
	// Pointeur sur un livre ? ou Les infos du livre dans la cellule
	s_livre *L;
	struct cell *suivant;
} cell_t;

typedef struct {
	int nE;
	int m;
	cell_t **T;
} tableHachage_t;

tableHachage_t* initTableHachage( int m );

int fonctionClef( char* nom );

int fonctionHachage( int clef, int m );

void hach_insertion_livre( s_livre* liv, tableHachage_t* Biblio );

void hach_lecture_n_entree(char *nomfic,int n, tableHachage_t* t);


#endif