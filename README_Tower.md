# Projet Tower — Jeu de stratégie en C

## Description

Tower est un jeu de stratégie au tour par tour développé en C, réalisé en binôme dans le cadre de la Licence Informatique (Programmation impérative) à l'Université Paris 8.

Deux joueurs s'affrontent sur une grille 6x6. Chacun construit des tours sur les cases du plateau. Une tour peut atteindre une hauteur maximale de 3 et exerce une domination sur les cases adjacentes. Le joueur qui contrôle le plus de cases à la fin de la partie remporte la victoire.

---

## Règles du jeu

- Le joueur 1 joue avec des valeurs positives (1, 2, 3)
- Le joueur 2 joue avec des valeurs négatives (-1, -2, -3)
- Chaque coup place une tour sur une case et influence les cases voisines
- Une case ne peut pas dépasser la hauteur maximale de 3
- Un joueur ne peut pas jouer sur une case occupée par l'adversaire
- La partie se déroule sur 5 tours
- Le vainqueur est désigné par le nombre de cases contrôlées en fin de partie

---

## Modes de jeu

- **Joueur contre Joueur** : deux joueurs s'affrontent en local, tour par tour
- **Joueur contre IA** : le joueur affronte une intelligence artificielle à déplacement aléatoire

---

## Technologies utilisées

| Technologie | Utilité |
|---|---|
| C (standard C99) | Langage principal |
| Tableaux 2D (matrice) | Représentation du plateau |
| Récursivité | Gestion des coups invalides |
| rand() / srand() / time() | Génération aléatoire pour l'IA |

---

## Structure du projet

```
Tower/
├── TowerV5.c                   # Version principale sans affichage des règles
└── TowerV5_avec_regles.c       # Version avec affichage des règles au démarrage
```

---

## Compilation et exécution

```bash
gcc TowerV5_avec_regles.c -o tower
./tower
```

---

## Fonctionnement

```
Démarrage
    |
Choix du mode (JcJ ou IA)
    |
Initialisation de la grille (6x6, toutes les cases à 0)
    |
Boucle de jeu (5 tours maximum)
    |
    ├── Tour Joueur 1 : saisie ligne/colonne → validation → mise à jour plateau
    ├── Tour Joueur 2 ou IA : idem (valeurs négatives)
    └── Affichage du plateau après chaque coup
    |
Fin de partie → comptage des cases → désignation du vainqueur
```

---

## Auteurs

- Samuel Etienne
- Ludovic Renault

Projet réalisé dans le cadre de la Licence Informatique — Programmation impérative  
Université Paris 8 — Vincennes à Saint-Denis  
Année : 2022

---

## Ce que j'ai appris

- Manipuler des tableaux à deux dimensions en C et comprendre leur représentation en mémoire
- Implémenter une logique de jeu complète avec gestion des cas limites (bords de grille, cases pleines, cases occupées)
- Utiliser la récursivité pour gérer les entrées invalides de l'utilisateur
- Concevoir une IA basique par génération aléatoire avec `rand()` et `srand()`
- Travailler en binôme sur un projet commun avec un rapport de rendu académique
