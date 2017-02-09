#include <stdio.h>
#include <stdlib.h>
#include "bibl.h"
#include "entree_sortie.h"
#define TMAX 41


void initialise_biblio(Biblio* bib)
{

	bib=(Biblio*)malloc(sizeof(Biblio));
	if( bib ) {
		bib->L=NULL;
		bib->nbliv=0;
	}
	else{
		printf("Biblio non initialisé\n");
		return;
	}

}

s_livre* creer_livre( int num, char* tit, char* aut ) 
{

	s_livre* li = (s_livre*)malloc(sizeof(s_livre));

	if( li ) {
		li->num = num;
		li->titre = strdup(tit);
		li->auteur = strdup(aut);
		li->suiv = NULL;
	}

	return li;
}

void insertion_livre( s_livre* liv, Biblio* bibli )
{

	liv->suiv = bibli->L;
	bibli->L = liv;
	bibli->nbliv++;
}

void lecture_n_entree(char *nomfic,int n,Biblio *B)
{

	FILE* F;
	int i;
	int num;
	char* titre= (char*) malloc(TMAX*sizeof(char));
	char* auteur= (char*) malloc(TMAX*sizeof(char));

	int test=B->nbliv;


	if(titre==NULL || auteur==NULL){
		printf("Erreur lors de l'allocation de titre ou auteur\n");
		return;
	}
	
	if(n<=0){

		printf("n trop petit\n");
		return; 


	}

	s_livre* li;


	if(((F=fopen(nomfic,"r"))==NULL)){
		printf("Le fichier %s n'existe pas.\n",nomfic);
		return;
	}

	for(i=0;i<n;i++){

		num = GetEntier(F);


		GetChaine(F, TMAX, titre);


		GetChaine(F, TMAX, auteur);

		li=creer_livre(num,titre,auteur);
		insertion_livre(li,B);





	}


	if(test+n!= B->nbliv){
		printf("Erreur dans l'insertion des livres dans la bibliothèque\n");
	}


}


int recherche_ouv_num(int n,Biblio* B){
	
	Biblio* tmp=B;
	int i;
	
	for (i = 0; i <tmp->nbliv ; i++)
	{
		
		if(tmp->L->num==n){
			printf("Livre trouvé! Titre: %s  Auteur:%s Num:%d\n",tmp->L->titre,tmp->L->auteur,tmp->L->num);
			return 1;
		}
		tmp->L=tmp->L->suiv;
		
		
		
		
	}
	printf("Le livre dont le numéro d'ouvrage est:%d n'a pas été trouvé.\n",n);
	return 0;
}
	
void recherche_ouv_titre(char* titre,Biblio* B){
	
	Biblio* tmp=B;
	int i;
	
	for (i = 0; i <tmp->nbliv ; i++)
	{
	
		
		if(strcmp(titre,tmp->L->titre)==0){
			printf("Livre trouvé! Titre: %s  Auteur:%s Num:%d\n",tmp->L->titre,tmp->L->auteur,tmp->L->num);
			return;
		}
		tmp->L=tmp->L->suiv;
		
		
		
		
	}
	printf("Le livre dont le titre est:%s n'a pas été trouvé.\n",titre);
	
}
	
void recherche_livre_par_auteur(char* auteur, Biblio* B){
	
	int cpt=0;
		
	Biblio* tmp=B;
	
	while(tmp->L)
	{
		
		if(strcmp(auteur,tmp->L->auteur)==0){
			if(cpt==0){
				printf("L'auteur %s a écrit:\n",tmp->L->auteur);
			}
			printf("- Titre: %s  Num:%d\n",tmp->L->titre,tmp->L->num);
			cpt++;
		}
		if(tmp->L->suiv==NULL){
			return;
		}
		tmp->L=tmp->L->suiv;
	}	

	if(cpt==0)
		printf("L'auteur %s n'a pas de livre écrit dans cette liste.\n",auteur);

}
	
	

void suppression_ouvrage(int n,Biblio* B){
	
	
	int i;
	Biblio* tmp=B;
	
	
	
		if(tmp->L->num==n){ //Si le livre se trouve en première position
			Biblio* s=tmp;
			tmp->L=tmp->L->suiv;
			free(s->L->auteur);
			free(s->L->titre);
			free(s);
			if(s==NULL)printf("Ouvrage %d supprimé de la bibliotheque\n",n);
			B->nbliv-=1;
			return;
		}
		
		for (i = 0; i <tmp->nbliv ; i++)
	{
		if(tmp->L->suiv->num==n){
			Biblio*s=tmp;
			s->L=s->L->suiv;
			tmp->L->suiv=s->L->suiv;
			free(s->L->auteur);
			free(s->L->titre);
			free(s);
			if(s==NULL)printf("Ouvrage %d supprimé de la bibliotheque\n",n);
			return;
			}
		tmp->L=tmp->L->suiv;
	}
	printf("Le livre dont le numéro d'ouvrage est:%d n'a pas été trouvé.\n",n);
}



Biblio* cherche_double(Biblio* B){
	
	Biblio* bis=NULL;
	initialise_biblio(bis);
	Biblio*tmp=B;
	Biblio*tempo=B;
	tempo->L=tempo->L->suiv;
	
	while(tmp){
		
		while(tempo){
			if((strcmp(tmp->L->auteur,tempo->L->auteur))==0 && (strcmp(tmp->L->titre,tempo->L->titre)==0)){
				s_livre* l=creer_livre(tmp->L->num,tmp->L->titre,tmp->L->auteur);
				insertion_livre(l,bis);
				printf("le livre %s par l'auteur %s a été trouvé en double.\n",tmp->L->titre,tmp->L->auteur);
			}
			tempo->L=tempo->L->suiv;
		}
		tmp->L=tmp->L->suiv;
				
	}
	
	return bis;
	
	
	
}
	



		



	
	
	
	
