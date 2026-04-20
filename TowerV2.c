// macros de type constante pour le nombre des lignes et de colonnes
#define lin 10
#define col 10
#include<stdio.h>
#include<stdbool.h>

//definir un type de matrice avec un nombre inconnu de lignes et colonnes 
typedef int matrice[lin][col];
 
//une pemiere fonction d’attribuer des valeur de 1 à dans une matrice en deux dimensions
void attribution1(matrice a)
{
	int k=0,i,j;
	for(i=0;i<lin;i++)
	for(j=0;j<col;j++)
	{
		a[i][j]=k;
		k;
	}
}

//change une valeur de la matrice
void changerP1(matrice a, int l, int c){
  printf("\n Joueur 1");
  printf("\nOu voulez-vous jouer ? Ligne : ");
  scanf("%d", &l);
  if (l >= 1 && l <= 10){
    printf("\nColonnes : ");
    scanf("%d", &c);
    if(c >= 1 && c <= 10){
      if (a[l-1][c-1] > 0){
        printf("\nVeuillez choisir une case non prise par l'autre joueur");
        changerP1(a,l,c);
      }
      if (a[l-1][c-1] == -3){ 
        printf("\nCette case est deja a son maximum");
        changerP1(a,l,c);
      }

      else{ 
        a[l-1][c-1] -= 1;

        if (a[l-2][c-1] > -3){
        a[l-2][c-1] -= 1;
        }
        if (a[l-1][c-2] > -3){
          a[l-1][c-2] -= 1;
        }
        if (a[l][c-1] > -3){
          a[l][c-1] -= 1;
        }
        if (a[l-1][c] > -3){
          a[l-1][c] -= 1;
        }
      }
    }
    else{
      printf("\nVeuillez choisir un index de case valide");
      changerP1(a,l,c);
    }
  }
  else{
  printf("\nVeuillez choisir un index de case valide");
  changerP1(a,l,c);
  }
}


void changerP2(matrice a, int l, int c){
  printf("\n Joueur 2");
  printf("\nOu voulez-vous jouer ? Ligne : ");
  scanf("%d", &l);
  if (l >= 1 && l <= 10){
      printf("\nColonnes : ");
      scanf("%d", &c);
    if(c >= 1 && c <= 10){
      if (a[l-1][c-1] > 0){
        printf("\nVeuillez choisir une case non prise par l'autre joueur");
        changerP2(a,l,c);
      }
      if (a[l-1][c-1] == -3){ 
        printf("\nCette case est deja a son maximum");
        changerP2(a,l,c);
      }

      else{ 
        a[l-1][c-1] -= 1;

        if (a[l-2][c-1] > -3){
        a[l-2][c-1] -= 1;
        }
        if (a[l-1][c-2] > -3){
          a[l-1][c-2] -= 1;
        }
        if (a[l][c-1] > -3){
          a[l][c-1] -= 1;
        }
        if (a[l-1][c] > -3){
          a[l-1][c] -= 1;
        }
      }
    }
    else{
      printf("\nVeuillez choisir un index de case valide");
      changerP2(a,l,c);
    }
  }
  else{
  printf("\nVeuillez choisir un index de case valide");
  changerP2(a,l,c);
  }
}

//l’affichage d’une matrice en deux dimensions sous la forme d’un tableau 
void affichage(matrice a, char c)
{
	int i,j;
	printf("\n");
	printf("\nPlateau actuel %c :\n",c);
	for(i=0;i<lin;i++)
	{
		for(j=0;j<col;j++)
		printf("%4d",a[i][j]);
		printf("\n");
	}
}
/*
//Verification de victoire 		
void verification(matrice a)
{
	int i,j;
	bool plein = false;
	for(i=0; i<lin;i++)
	{
		for(j=0;j<col;j++);
		{
			if(a[i][j]!=0)
			{
				plein = true;
			
			}
		}
	}
	if(plein = true)
	{
		
	}
}*/	
//mise en place du jeu en tour par tour
void gameplay(matrice a, int l, int c, int r)
{
	bool stop = false;
	while (stop = false)
	{
		verification(a);
		affichage(a,'A');
		printf("\nVoulez vous jouer ? (1 pour oui/ 0 pour non) : ");
		scanf("%d", &r);
		if (r == 0)
		{
			stop = true;
		}
		else if (r > 1)
		{
		printf("\nMerci de saisir l'un des deux chiffres possible");
		}
		changerP1(a,l,c);
		affichage(a,'A');
		verification(a);
		printf("\nVoulez vous jouer ? (1 pour oui/ 0 pour non) : ");
		scanf("%d", &r);
		if (r == 0)
		{
			stop = true;
		}
		else if (r > 1)
		{
		printf("\nMerci de saisir l'un des deux chiffres possible");
		}
		changerP2(a,l,c);
		affichage(a,'A');
	}
}

// fonction principale d'exécuter
void main()
{
	matrice a;
  int l;
  int c;
  int r;
  gameplay(a,l,c,r);
	/*attribution1(a);
	affichage(a,'A');
  changerP1(a,l,c);
  affichage(a,'A');
  changerP1(a,l,c);
  affichage(a,'A');
  changerP1(a,l,c);
  affichage(a,'A');
  changerP1(a,l,c);
  affichage(a,'A');*/

	getchar();
	int k;
	scanf("%d", k);
}
