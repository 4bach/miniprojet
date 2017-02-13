#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bibl.h"
#include "entree_sortie.h"
#define TMAX 41
#define LMAX 100000

tableHachage_t* initTableHachage( int m ) 
{
	tableHachage_t* th = (tableHachage_t*)malloc(sizeof( tableHachage_t) );

	if( th == NULL ) {
		printf("Erreur lors de l'allocation de la table de hachage\n");
		return NULL;
	}

	int i;
	th->nE = 0;
	th->m = m;
	*(th->T) = (cell_t*)malloc( sizeof( cell_t ) * m);

	if( *(th->T) == NULL ) {
		printf("Erreur lors de l'allocation des cases de la table de hachage\n");
		return NULL;
	}

	for( i = 0; i < m; i++ ){
		th->T[i]->clef = 0;
		th->T[i]->L = NULL;
		th->T[i]->suivant = NULL;
	}

	return th;
}

//On pourrait aussi additionner le nom et le titre pour etre plus specifique
int fonctionClef( char* nom ) 
{

	int val = 0;
	char* tmp = nom;
	while( tmp != '\0' ) {
		val += (int)tmp;
		tmp++;
	}
	return val;
}

int fonctionHachage( int clef, int m ) 
{	
	int tmp;
	double A = (sqrt(5) - 1)/2;
	tmp = (int)(clef * A);
	tmp = (int)(m * ( clef * A - tmp ));
	return tmp;
}

void hach_insertion_livre( s_livre* liv, tableHachage_t* Biblio )
{
	if( !liv ) return;

	int clef =  fonctionClef( liv->auteur );
	int position = fonctionHachage( clef, Biblio->m );

	


}

	
	
