// macros de type constante pour le nombre des lignes et de colonnes
#define lin 4
#define col 4
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
      if (a[l-1][c-1] < 0){
        printf("\nVeuillez choisir une case non prise par l'autre joueur");
        changerP1(a,l,c);
      }
      else if (a[l-1][c-1] == -3){ 
        printf("\nCette case est deja a son maximum");
        changerP1(a,l,c);
      }

      else if (c == 1){
        a[l-1][c-1] += 1;

        if (a[l-2][c-1] < 3){
        a[l-2][c-1] += 1;
        }
        if (a[l][c-1] < 3){
          a[l][c-1] += 1;
        }
        if (a[l-1][c] < 3){
          a[l-1][c] += 1;
        }
      }

      else if (c == 4) { 
        a[l-1][c-1] += 1;

        if (a[l-2][c-1] < 3){
        a[l-2][c-1] += 1;
        }
        if (a[l-1][c-2] < 3){
          a[l-1][c-2] += 1;
        }
        if (a[l][c-1] < 3){
          a[l][c-1] += 1;
        }
      }

      else{ 
        a[l-1][c-1] += 1;

        if (a[l-2][c-1] < 3){
        a[l-2][c-1] += 1;
        }
        if (a[l-1][c-2] < 3){
          a[l-1][c-2] += 1;
        }
        if (a[l][c-1] < 3){
          a[l][c-1] += 1;
        }
        if (a[l-1][c] < 3){
          a[l-1][c] += 1;
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
      else if (a[l-1][c-1] == -3){ 
        printf("\nCette case est deja a son maximum");
        changerP2(a,l,c);
      }

      else if ( c == 1)
      { 
        a[l-1][c-1] -= 1;

        if (a[l-2][c-1] > -3){
        a[l-2][c-1] -= 1;
        }

        if (a[l][c-1] > -3){
          a[l][c-1] -= 1;
        }
        if (a[l-1][c] > -3){
          a[l-1][c] -= 1;
        }
      }

      else if(c == 4){ 
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

//determine le vainqueur en comptant son nombre de cases

void vainqueur(matrice a){
  int neg = 0;
  int pos = 0;
  int i,j;
  for(i = 0;i<lin;i++){
    for(j = 0; j<col; j++){
      if (a[i][j] <= -1){
        neg += 1;
      }
      if (a[i][j] >= 1){
        pos += 1;
      }
    }
  }
  if (neg > pos){
    printf("\nLe Joueur 2 a gagne ! Bravo !");
  }
  else if (neg < pos){
    printf("\nLe joueur 1 a gagne ! Bravo !");
  }
  else if (neg == pos){
    printf("\nC'est une egalite, dommage");
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

//Verification de victoire 		
bool verification(matrice a)
{
	int i,j;
	for(i=0; i<lin; i++)
	{
		for(j=0; j<col; j++);
		{
			if(a[i][j] == 0)
			{
				return false;
			}
    }
	}

}
//mise en place du jeu en tour par tour
void gameplay(matrice a, int l, int c, int r)
{
  attribution1(a);
  bool stop = verification(a);
  affichage(a,'A');
	while (stop == false)
	{
      printf("\nVoulez vous jouer ? (1 pour oui/ 0 pour non) : ");
      scanf("%d", &r);
      if (r == 0)
      {
        stop = true;
        break;
      }
      else if (r > 1)
      {
      printf("\nMerci de saisir l'un des deux chiffres possible");
      }
      changerP1(a,l,c);
      affichage(a,'A');
      printf("\nVoulez vous jouer ? (1 pour oui/ 0 pour non) : ");
      scanf("%d", &r);
      if (r == 0)
      {
        stop = true;
        break;
      }
      else if (r > 1)
      {
      printf("\nMerci de saisir l'un des deux chiffres possible");
      }
      changerP2(a,l,c);
      affichage(a,'A');
      stop = verification(a);
  }
  printf("Fin de partie");
  vainqueur(a);

}

// fonction principale d'exécuter
void main()
{
	matrice a;
  int l;
  int c;
  int r;
  gameplay(a,l,c,r);
	/*
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