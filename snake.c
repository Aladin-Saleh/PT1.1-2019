#include <stdlib.h>
#include <graph.h>
#include <stdio.h>
#include <time.h>
#include "snake.h"


/*Ici je déclare toutes les variables qui sont nécessaire à ce fichier pour ne pas à avoir à les rappeller à chaque fois et cela est plus pratique pour le makefile dans mon cas */
static int x=400;
static int y=290;
static int test =0;
static char t[50];
static char tscrs[50];/*affiche le score*/
static int nscrs = 0;
static int n = 0; 
static unsigned long suivant;
static unsigned long suivanttime;
static unsigned long suivantscore;
static int i;
static int positionSerpent[50][50];/*tableau ou je stock les coordonnées du serpent*/
static int on = 0;
static int off = 0;
static int dplmt;
static int j;
static int z;
static int onpomme = 1;/*variable qui m'a permis de tester plusieur chose avec les pommes*/
static int xp,yp;
static int xpmax = 780;
static int xpmin = 110;
static int ypmax = 570;
static int ypmin = 100;
static int vitesse = 10000;/*sert au rafraichissement et a la vitesse du serpent*/
static char gameOver[50];/*affiche le game over*/
static char pause[50];


int main(int argc, char const *argv[])
{

 couleur couleurChoisie;
 couleur couleurFond;
 couleur c;
 srand(time(NULL));



 InitialiserGraphique();

 creationFenetre();


 sprintf(t,"time=%3d",n);
 EffacerEcran(CouleurParNom("black"));
 EcrireTexte(30,565,t,2);




 while(on = 1)
 {


              /*ici je re-affiche le rectangle vert pour effacer les bandes rouges laisser par le serpent,c'est pas trop pratique parce que sa sacade :/ */
  couleurFond=CouleurParComposante(90,180,79);
  ChoisirCouleurDessin(couleurFond);
  RemplirRectangle(100,100,600,400);
                /*Ici je crée le serpent et je "sauvegarde" ses position x et y dans un tableau appeler positionSerpent*/
  if (on == 0 )
  {
    couleurChoisie=CouleurParNom("yellow");
    ChoisirCouleurDessin(couleurChoisie);

    for(i=0;i<10;i++)
    {
     y=y-10;
     RemplirRectangle(x,y,10,10);
     positionSerpent[i][0]=x;
     positionSerpent[i][1]=y;
     on=1;

   }
 }




 
 Pommes();
 PommesAffichage();

 
 printf("XP + 1 =>(%d)\n",xp+1 );


 while(1){


  PommesAffichage();  

  

  if (Microsecondes()>suivant){

    TestPommeSerpent();
   

   if (Microsecondes()>suivanttime)
   {
    initialiserTempsScore();  
    AccelerationSerpent();     

  }

       Collision();/*Appelle de la fonction Collision qui verfie que les coordonnees x ou y ne soit pas en bordure */


       if (ToucheEnAttente())/*Dans le cas ou une touche est actionné */
  {
   dplmt = Touche();
   couleurFond=CouleurParComposante(90,180,79);
   ChoisirCouleurDessin(couleurFond);
   RemplirRectangle(100,100,600,400);

 }

       if (dplmt == XK_Up)/*Ce morceau de code me permet de deplacer le serpent principalement et accesoirement de quitter le jeux avec Echap */
 {
  couleurChoisie=CouleurParNom("yellow");
  ChoisirCouleurDessin(couleurChoisie);
  y=y-1;
  RemplirRectangle(x,y,10,10);
  positionSerpent[i][0]=x;
  positionSerpent[i][1]=y;

}
if (dplmt == XK_Down)
{ 
  couleurChoisie=CouleurParNom("yellow");
  ChoisirCouleurDessin(couleurChoisie);

  y=y+1;

  RemplirRectangle(x,y,10,10);
  positionSerpent[i][0]=x;
  positionSerpent[i][1]=y;

}
if (dplmt == XK_Left)
{ 
  couleurChoisie=CouleurParNom("yellow");
  ChoisirCouleurDessin(couleurChoisie);


  x=x-1;


  RemplirRectangle(x,y,10,10);
  positionSerpent[i][0]=x;
  positionSerpent[i][1]=y;

}
if (dplmt == XK_Right)
{ 
  couleurChoisie=CouleurParNom("yellow");
  ChoisirCouleurDessin(couleurChoisie);
  x=x+1;

  RemplirRectangle(x,y,10,10);
  positionSerpent[i][0]=x;
  positionSerpent[i][1]=y;

}

          /*Permet de fermer la fenetre de jeu avec la touche Echap */
if (dplmt == XK_Escape)
{
  FermerGraphique();
}


if (dplmt == XK_space)
{
  ChoisirCouleurDessin(CouleurParNom("black"));
  RemplirRectangle(0,0,800,600);
  sprintf(pause,"PAUSE");
  ChoisirCouleurDessin(CouleurParNom("red"));
  EcrireTexte(400,300,pause,2);
  n = n;
}
printf("XP + 1    YP =>(%d) (%d)\n",xp+1,yp );


printf("x : %d\n",x);/*Affiche les positions x et y du serpent */
suivant= Microsecondes()+vitesse;
}


}

}




return 0;
}
