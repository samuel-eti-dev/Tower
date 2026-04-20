// macros de type constante pour le nombre des lignes et de colonnes
#define lin 6
#define col 6
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

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
  if (l >= 1 && l <= 6){
    printf("\nColonnes : ");
    scanf("%d", &c);
    if(c >= 1 && c <= 6){
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

      else if (c == 6) { 
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
  if (l >= 1 && l <= 6){
      printf("\nColonnes : ");
      scanf("%d", &c);
    if(c >= 1 && c <= 6){
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

      else if(c == 6){ 
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

void changerIA(matrice a, int l, int c){
  srand(time(NULL));
  c = rand() %6 +1;
  l = rand() %6 +1;
  //printf("\n%d , %d\n", l,c);
  if (a[l][c] > 0){
    changerIA(a,l,c);
  }

  else if (a[l][c] == -3){
    changerIA(a,l,c);
  }

  else if(c == 6){ 
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

  else if ( c == 1){
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
    printf("\nLe Joueur 2 a gagne ! Bravo !\n");
  }
  else if (neg < pos){
    printf("\nLe joueur 1 a gagne ! Bravo !\n");
  }
  else if (neg == pos){
    printf("\nC'est une egalite, dommage\n");
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

//Verification des valeurs de la matrice 		
/*void verification(matrice a)
{
	int i,j, v, nv;
	nv = lin * col;
	v = 0;
	for(i=0; i<lin; i++)
	{
		for(j=0; j<col; j++);
		{
			if(i != 0 & j != 0)
			{
				v  = v + 1;
			}
			if(v == nv)
			{
				vainqueur(a);
			}
			
    		}
	}

}*/
//mise en place du jeu en tour par tour
void gameplay(matrice a, int l, int c, int r, int t)
{
  t = 5;
  attribution1(a);
  bool stop = false;
  affichage(a,'A');
	while (stop == false)
	{
	printf("Tours restants : %d", t);
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
    // verification(a);
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
      t = t - 1;
      if(t == 0)
      {
      	stop = true;
      }
   //   verification(a);
  	}
  printf("Fin de partie");
  vainqueur(a);

}

void gameplayIA(matrice a, int l, int c, int r, int t)
{
  t = 5;
  attribution1(a);
  bool stop = false;
  affichage(a,'A');
	while (stop == false)
	{
	printf("Tours restants : %d", t);
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
      printf("\nTour de l'ordinateur");
      changerIA(a,l,c);
      affichage(a,'A');
      t = t - 1;
      if(t == 0)
      {
      	stop = true;
      }
   //   verification(a);
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
  int t;
  int g;
  printf("\nVoulez-vous jouer seul(1) contre une IA(Work In Progress) ou a deux(2) ?");
  scanf("%d", &g);
  if (g == 1){
    gameplayIA(a,l,c,r,t);
  }
  else{
    gameplay(a,l,c,r,t);
  }
  
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
