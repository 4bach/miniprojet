#include <stdio.h>
#include <stdlib.h>
#include "bibl.h"
#include "entree_sortie.h"
#define TMAX 41

void menu(void){
	printf("		--------------------MENU--------------------\n");
	printf("0: 			QUITTER LE MENU\n");
	printf("1: 			RECHERCHER UN OUVRAGE PAR SON NUMERO\n");
	printf("2: 			RECHERCHER UN OUVRAGE PAR SON TITRE\n");
	printf("3: 			LISTER LES OUVRAGES D'UN AUTEUR\n");
	printf("4: 			SUPPRIMER UN LIVRE\n");
	printf("5: 			LISTER LES DOUBLONS\n");
}
	
	
	




int main(int argc,char* *argv){

	int ch;
	char* nomfic;
	int n;
	int nblignes;
	Biblio B;
	initialise_biblio(&B);
	Biblio* Double=NULL;
	char auteur[TMAX];
	char titre[TMAX];
	if(argc!=3){
		printf("Erreur format: %s <NomFichier_Biblio.txt><nbLigneALire>",argv[0]);
		return 1;
	}

	nomfic = strdup(argv[1]);
	nblignes=atoi(argv[2]);
	printf("Lecture \n");
	lecture_n_entree(nomfic,nblignes,&B);

	do{

		menu();
		scanf("%d",&ch);

		switch(ch){

			case 1:
				printf("Saisir le numero de l'ouvrage\n");
				scanf("%d",&n);
				int bool=recherche_ouv_num(n,&B);
				printf("%d",bool);
				break;

			case 2:
				
				printf("Saisir le titre de l'ouvrage\n");
				scanf("%s",titre);
				recherche_ouv_titre(titre,&B);
				break;
			case 3:
				
				printf("Saisir le nom de l'auteur\n");
				scanf("%s",auteur);
				recherche_livre_par_auteur(auteur,&B);
				break;
			case 4:
				printf("Saisir le numero de l'ouvrage\n");
				scanf("%d",&n);
				suppression_ouvrage(n,&B);
				break;
			case 5:
				
				cherche_double(&B);
				while(Double){
					printf("num: %d auteur: %s titre: %s\n",Double->L->num,Double->L->auteur,Double->L->titre);
					Double->L=Double->L->suiv;
				}


		}




	}while(ch!=0);

	printf("Au revoir\n");
	return 0;
	
}
