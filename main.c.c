#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// Structure ruban
typedef struct Ruban Ruban;

struct Ruban {
    int noteDepart;
    int tableau[100];
    int tailleRuban;
};

// Prototypes des fonctions et procédures
void trouver_note(int note_proposee);
void trouver_hauteur(char note_proposee[]);
int trouver_hauteur_fonct(char note_proposee[]);
void initialisation_ruban(Ruban* r);
void affichage_ruban(Ruban r);
void affichage_morceau(Ruban r);
void recherche_nb_note(Ruban r);


// Algorithme principal
int main()
{
  // Lexique
  int choix = -1;
  char prenom[50];
  struct Ruban r;

  printf("---------------RUBAN-PERFORE--------------- \n");

  printf("Bonjour et bienvenue ! Merci de saisir votre prenom \n");
  scanf(" %s",prenom);

  printf("\nAvant toute chose, %s, merci de saisir votre ruban. ",prenom);



  initialisation_ruban(&r);

  while(choix != 0){

    printf("\n\nQue souhaitez vous faire %s ?",prenom);

    printf("\n\n------------------------- MENU ------------------------- ");
    printf("\n1- Generer un nouveau ruban ");
    printf("\n2- Afficher mon ruban ");
    printf("\n3- Afficher le morceau correspondant a mon ruban");
    printf("\n4- Rechercher l'occurence d'une note dans mon ruban");
    printf("\n----------------");
    printf("\n0- Quitter");
    printf("\n-------------------------------------------------------- \n");

    scanf(" %d",&choix);

    switch(choix){

      case 1:
        initialisation_ruban(&r);
      break;

      case 2:
        affichage_ruban(r);
      break;

      case 3:
        affichage_morceau(r);
      break;

      case 4:
        recherche_nb_note(r);
      break;

      case 0:
        printf("Merci de votre visite %s ! A tres bientot !", prenom);
        break;

      default:
        printf("Aucune fonctionnalite n'est associée a votre saisie, merci de saisir une numero valide.");
      break;

    }

  }

  return 0;
}

// Fonctions et procédures

// Procédure qui retourne le nom en français d'une note repérée par son numéro donné en paramètre
void trouver_note(int note_proposee)
{
  switch (note_proposee) {
    case 1:
      printf("Do " );
    break;

    case 2:
      printf("Re " );
    break;

    case 3:
      printf("Mi " );
    break;

    case 4:
      printf("Fa " );
    break;

    case 5:
      printf("Sol ");
    break;

    case 6:
      printf("La " );
    break;

    case 7:
      printf("Si " );
    break;

    default:
      printf("Note trop haute ou trop basse. ");
    break;
  }
}

// Procédure qui retourne le numéro d'une note repérée par son nom en français
// Ici on utilise la fonction strcmp pour comparer deux chaines de caractères (la fonction retourne 0 si les chaines sont identiques)
void trouver_hauteur(char note_proposee[])
{
    if (strcmp(note_proposee, "Do") == 0) {
      printf("1");
    } else if (strcmp(note_proposee, "Re") == 0) {
      printf("2");
    } else if (strcmp(note_proposee, "Mi") == 0){
      printf ("3");
    } else if (strcmp(note_proposee, "Fa") == 0) {
      printf("4");
    } else if (strcmp(note_proposee, "Sol") == 0) {
      printf("5");
    } else if (strcmp(note_proposee, "La") == 0) {
      printf("6");
    } else if (strcmp(note_proposee, "Si") == 0) {
      printf("7");
    } else {
      printf("Note trop haute ou trop basse. ");
    }
}

// Fonction qui permet de retourner la valeur numérique d'une note afin que l'on puisse la comparer dans la procédure recherche_nb_note qui calcule le nombre d'occurence d'une note dans un morceau
// si la note n'existe pas la fonction retourne -1
int trouver_hauteur_fonct(char note_proposee[])
{

    int resultat = -1;

    if (strcmp(note_proposee, "Do") == 0) {
      resultat= 1;
    } else if (strcmp(note_proposee, "Re") == 0) {
      resultat= 2;
    } else if (strcmp(note_proposee, "Mi") == 0){
      resultat= 3;
    } else if (strcmp(note_proposee, "Fa") == 0) {
      resultat= 4;
    } else if (strcmp(note_proposee, "Sol") == 0) {
      resultat= 5;
    } else if (strcmp(note_proposee, "La") == 0) {
      resultat= 6;
    } else if (strcmp(note_proposee, "Si") == 0) {
      resultat= 7;
    }

    return resultat;
}

// Procédure qui permet à l'utilisateur de créer un ruban en donnant sa note de départ et les différents positions constituant le ruban
void initialisation_ruban(Ruban * r)
{

  do {
    printf("\nVeuillez renseigner sa taille. (Elle doit etre comprise entre 1 et 100)\n");
      scanf(" %d",&r->tailleRuban);
  } while(r->tailleRuban>100 || r->tailleRuban<1);


  printf("Entrer la premiere note (comprise entre 1 et 7)\n");
  scanf(" %d", &r->noteDepart);

  for (int i = 0; i < r->tailleRuban; i++ ) {
      do {
        printf("Entrer la position de la note note numero %d (comprise entre -2 et 2)\n",i+2);
        scanf(" %d", &r->tableau[i]);
      } while(r->tableau[i]<-2 || r->tableau[i]>2);

  }

}

// Procédure qui permet d'afficher la suite des positions constituant le ruban de l'utilisateur
void affichage_ruban(Ruban r)
{

  printf("\nVoici votre ruban actuel : ");

    for (int i = 0; i < r.tailleRuban; i++) {
        printf("%d ",r.tableau[i]);
    }
}

// Procédure qui permet d'afficher le morceau de musique de l'utilisateur
void affichage_morceau(Ruban r)
{
    int dernierenote = r.noteDepart;
    printf("\nVoici le morceau correspondant a votre ruban : ");
    trouver_note(dernierenote);
    for (int i = 0; i < r.tailleRuban   ; i++) {
        dernierenote = dernierenote + r.tableau[i];
        trouver_note(dernierenote);
    }
}

// Procédure qui permet de rechercher l'occurence d'une note dans le morceau
// Ici on utilise la fonction trouver_hauteur_fonct qui permet de retourner la valeur d'une note et de la comparer
void recherche_nb_note(Ruban r)
{

    char note_saisie[3];
    int note_recherche;
    int nb_fois = 0;


    printf("Entrer la note afin de calculer le nombre de fois ou elle est presente dans le ruban actuel\n" );
    scanf("%s", note_saisie);

    note_recherche = trouver_hauteur_fonct(note_saisie);

    if(note_recherche < 1){
      printf("Desole, cette note est inconnue. ");
    } else {

       int dernierenote = r.noteDepart; // La valeur de la dernière note prend la valeur de la note de départ

       if(dernierenote == note_recherche){
         nb_fois ++; // Incrémentation du compteur lorsqu'il y a correspondance
       }

       for (int i = 0; i < r.tailleRuban; i++) {
        dernierenote = dernierenote + r.tableau[i]; // La valeur de la dernière nore prend la valeur de la précédente plus la valeur des cases suivantes du tableau (ce sont des positions)

        if(dernierenote == note_recherche){
          nb_fois ++; // Incrémentation du compteur lorsqu'il y a correspondance
       }
      }

      printf("\nLa note %s est presente %d fois dans le ruban",note_saisie,nb_fois); // Affichage de l'occurence

    }

}
