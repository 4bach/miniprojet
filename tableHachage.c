#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bibl.h"
#include "entree_sortie.h"
#include "tableHachage.h"
#define TMAX 41
#define LMAX 100000

cell_t* creer_cell( int clef, s_livre* L ) 
{
	return NULL;
}


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
	fprintf(stderr, "4\n" );
	*(th->T) = (cell_t*)malloc( sizeof( cell_t ) * m);
	fprintf(stderr, "5\n" );
	if( *(th->T) == NULL ) {
		printf("Erreur lors de l'allocation des cases de la table de hachage\n");
		return NULL;
	}
	fprintf(stderr, "6\n" );
	for( i = 0; i < m; i++ ){
		th->T[i]->clef = 0;
		th->T[i]->L = NULL;
		th->T[i]->suivant = NULL;
	}
	fprintf(stderr, "7\n" );
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

void hach_insertion_livre( s_livre* liv, tableHachage_t* Bib )
{
	if( !liv ) return;

	int clef =  fonctionClef( liv->auteur );
	int position = fonctionHachage( clef, Bib->m );

	cell_t* tmp = Bib->T[position];
	while( tmp->suivant != NULL ){
		tmp = Bib->T[position]->suivant;
	}
	tmp->suivant = (cell_t*)malloc( sizeof( cell_t ));
	if( tmp->suivant == NULL ) {
		printf( "Erreur lors de la creation d'une cellule " );
		return;
	}

	tmp = tmp->suivant;
	tmp->clef = clef;
	tmp->suivant = NULL;
	tmp->L = liv;
	Bib->nE++;
}

void hach_lecture_n_entree(char *nomfic,int n, tableHachage_t* t)
{

	FILE* F;
	int i;
	int num;
	char* titre= (char*) malloc(TMAX*sizeof(char));
	char* auteur= (char*) malloc(TMAX*sizeof(char));

	int test=t->nE;


	if(titre==NULL || auteur==NULL){
		printf("Erreur lors de l'allocation de titre ou auteur\n");
		return;
	}
	
	if(n<=0){

		printf("n trop petit\n");
		return; 


	}

	s_livre* li=NULL;


	if(((F=fopen(nomfic,"r"))==NULL)){
		printf("Le fichier %s n'existe pas.\n",nomfic);
		return;
	}

	for(i=0;i<n;i++){

		num = GetEntier(F);


		GetChaine(F, TMAX, titre);


		GetChaine(F, TMAX, auteur);

		li=creer_livre(num,titre,auteur);
		hach_insertion_livre(li,t);
	}


	if(test+n!= t->nE){
		printf("Erreur dans l'insertion des livres dans la bibliothèque\n");
	}


}

	
	
