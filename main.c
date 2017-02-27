#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bibl.h"
#include "entree_sortie.h"
#define TMAX 41

void menu(void)
{
	printf("--------------------MENU--------------------\n");
	printf("|0: QUITTER LE MENU\n");
	printf("|1: RECHERCHER UN OUVRAGE PAR SON NUMERO\n");
	printf("|2: RECHERCHER UN OUVRAGE PAR SON TITRE\n");
	printf("|3: LISTER LES OUVRAGES D'UN AUTEUR\n");
	printf("|4: SUPPRIMER UN LIVRE\n");
	printf("|5: LISTER LES DOUBLONS\n");
	printf("|6: INSERTION D'UN NOUVEL OUVRAGE\n");
	printf("|7: AFFICHER LA BIBLIOTHEQUE\n");
	printf("|8: SUPPRIMER LA BIBLIOTHEQUE\n");
}
	 
int main(int argc,char* *argv)
{
	
	int ch;
	clock_t start,end;
	float total;
	char* nomfic=strdup(argv[1]);
	int n; //Num de l'ouvrage
	int nblignes;
	Biblio B,bis;
	initialise_biblio(&B);
	char auteur[TMAX];
	char titre[TMAX];
	if(argc!=3){
		printf("Erreur format: %s <NomFichier_Biblio.txt><nbLigneALire>",argv[0]);
		return 1;
	}
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
				start=clock();
				int bool=recherche_ouv_num(n,&B);
				end=clock();
				printf("%d\n",bool);
				total=(float)(end-start)/CLOCKS_PER_SEC;
				printf("Temps de calcul: %f\n",total);
				break;

			case 2:
				
				printf("Saisir le titre de l'ouvrage\n");
				scanf("%s",titre);
				start=clock();
				recherche_ouv_titre(titre,&B);
				end=clock();
				total=(float)(end-start)/CLOCKS_PER_SEC;
				printf("Temps de calcul: %f\n",total);
				break;
			case 3:
				
				printf("Saisir le nom de l'auteur\n");
				scanf("%s",auteur);
				start=clock();
				recherche_livre_par_auteur(auteur,&B);
				end=clock();
				total=(float)(end-start)/CLOCKS_PER_SEC;
				printf("Temps de calcul: %f\n",total);
				
				break;
			case 4:
				
				printf("Saisir le numero de l'ouvrage\n");
				scanf("%d",&n);
				start=clock();
				suppression_ouvrage(n,&B);
				end=clock();
				total=(float)(end-start)/CLOCKS_PER_SEC;
				printf("Temps de calcul: %f\n",total);
				break;
			case 5:
				start=clock();
				cherche_double(&B,&bis);
				end=clock();
				afficher_biblio(&bis);
				supprimer_biblio(&bis);
				total=(float)(end-start)/CLOCKS_PER_SEC;
				printf("Temps de calcul: %f\n",total);
				break;
			case 6:
				printf("Saisir le nom de l'auteur\n");
				scanf("%s",auteur);
				printf("Saisir le titre\n");
				scanf("%s",titre);
				start=clock();
				s_livre*li=creer_livre(B.nbliv+1,titre,auteur);
				insertion_livre(li,&B);
				end=clock();
				total=(float)(end-start)/CLOCKS_PER_SEC;
				printf("Temps de calcul: %f\n",total);
				break;
			case 7:
				start=clock();
				afficher_biblio(&B);
				end=clock();
				total=(float)(end-start)/CLOCKS_PER_SEC;
				printf("Temps de calcul: %f\n",total);
				break;
			case 8:
				start=clock();
				supprimer_biblio(&B);
				end=clock();
				total=(float)(end-start)/CLOCKS_PER_SEC;
				printf("Temps de calcul: %f\n",total);
				break;


		}




	}while(ch!=0);

	printf("FIN\n");
	return 0;
	
}
