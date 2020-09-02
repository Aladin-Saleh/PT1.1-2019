#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<graph.h>
#include "snake.h"


#define TIMER 1000000L
#define SCORE 1000000L

/*Ici je déclare toutes les variables qui sont nécessaire à ce fichier */

static  int x=400;
static int y=290;
static int test =0;
static char t[50];
static char tscrs[50];
static int nscrs = 0;
static int n = 0; 
static unsigned long suivant;
static unsigned long suivanttime;
static unsigned long suivantscore;
static int i;
static int positionSerpent[50][50];
static int on = 0;
static int off = 0;
static int dplmt;
static int j;
static int z;
static int onpomme = 1;
static int xp,yp;
static int xpmax = 780;
static int xpmin = 110;
static int ypmax = 570;
static int ypmin = 100;
static int speed = 3;
static int vitesse = 10000;
static char gameOver[50];
static char pause[50];




/*J'ai creer une fonction qui creer et affiche la fenetre dans laquelle on joue */
void creationFenetre(void)
{
 couleur couleurChoisie;
 couleur couleurFond;

 CreerFenetre(0,0,800,600);
 couleurChoisie=CouleurParNom("black");
 EffacerEcran(couleurChoisie);
 couleurFond=CouleurParComposante(90,180,79);
 ChoisirCouleurDessin(couleurFond);
 RemplirRectangle(100,100,600,400);
}






void AccelerationSerpent(void)/*Ici il s'agit de ma fonction qui dès que le joueur atteint un certaint palier la vitesse de deplacement du serpent vas changer */
{
  if (nscrs >= 100 )
  {
    vitesse = 7000;
  }

  if (nscrs >= 300 )
  {
    vitesse = 4000;
  }
  if (nscrs >= 500 )
  {
    vitesse = 2000;
  }
  if (nscrs >= 1000 )
  {
    vitesse = 1000;
  }



}


            /*Fonction que j'enleverais à la fin, il m'aide juste a verifer que tout est bien "cadriller",il me sera utile des que je commencerais les pommes*/
void grillage(void)
{
 couleur couleurTrait;
 int i;
 int x=100;
 int xx=700;
 int y=100;
 int yy=500;
 int colonne=x;
 int ligne=y;

 couleurTrait=CouleurParNom("black");
 ChoisirCouleurDessin(couleurTrait);

 for(i=1;i<60;i++)
 {
  colonne=colonne+10;
  DessinerSegment(colonne,y,colonne,yy);
}

for(i=1;i<40;i++)
{
  ligne=ligne+10;
  DessinerSegment(x,ligne,xx,ligne);
}

}

            /*Fait apparaitre le temps et le score sur la fenetre,j'ai remarquer que selon la taille de l'ecran du joueur l'affichage du score peut etre coupé*/ 

void initialiserTempsScore(void)
{
 couleur c;
 c=CouleurParNom("black");


 n++;
 sprintf(t,"time=%3d",n);
 ChoisirCouleurDessin(CouleurParNom("black"));
 RemplirRectangle(90,530,100,100);
 ChoisirCouleurDessin(CouleurParNom("white"));
 EcrireTexte(30,565,t,2);
 suivanttime=Microsecondes()+TIMER;
 printf("(%d)\n",n );





 sprintf(tscrs,"Score=%3d",nscrs);
 ChoisirCouleurDessin(CouleurParNom("black"));
 RemplirRectangle(680,530,200,200);
 ChoisirCouleurDessin(CouleurParNom("white"));
 EcrireTexte(680,565,tscrs,2);
 suivantscore=Microsecondes()+SCORE;




}





int Collision(void)
{



  if (x == 100)
  {
   test++;
   printf("test collisions :%d\n",test );
   printf("score : %d temps : %d\n",nscrs,n );
    ChoisirCouleurDessin(CouleurParNom("black"));
  RemplirRectangle(0,0,800,600);
  sprintf(gameOver,"GAME OVER !");
  ChoisirCouleurDessin(CouleurParNom("red"));
  EcrireTexte(400,300,gameOver,2);

   vitesse = 1000000000;

 }
 else if (x == 690)
 {
   test++;
   printf("test collisions :%d\n",test );
   printf("score : %d temps : %d\n",nscrs,n );
    ChoisirCouleurDessin(CouleurParNom("black"));
  RemplirRectangle(0,0,800,600);
  sprintf(gameOver,"GAME OVER !");
  ChoisirCouleurDessin(CouleurParNom("red"));
  EcrireTexte(400,300,gameOver,2);

   vitesse = 1000000000;


 }
 else if (y == 100)
 {
   test++;
   printf("test collisions :%d\n",test );
   printf("score : %d temps : %d\n",nscrs,n );
    ChoisirCouleurDessin(CouleurParNom("black"));
  RemplirRectangle(0,0,800,600);
  sprintf(gameOver,"GAME OVER !");
  ChoisirCouleurDessin(CouleurParNom("red"));
  EcrireTexte(400,300,gameOver,2);
    if (dplmt == XK_Escape)
    {
      FermerGraphique();
    }
   vitesse = 1000000000;


 }

 else if (y == 490)
 {
  test++;
  printf("test collisions : %d\n",test );
  printf("score : %d temps : %d\n",nscrs,n );
    ChoisirCouleurDessin(CouleurParNom("black"));
  RemplirRectangle(0,0,800,600);
  sprintf(gameOver,"GAME OVER !");
  ChoisirCouleurDessin(CouleurParNom("red"));
  EcrireTexte(400,300,gameOver,2);
  if (dplmt == XK_Escape)
    {
      FermerGraphique();
    }

   vitesse = 1000000000;


 





}



return test;
}


void Pommes(void)
{

  couleur couleurPommes;

  for(i =0;i < 5;++i){
    for(j = 0;j < 1; j++){
      xp = (rand()%(xpmax - xpmin ));
          yp = (rand()%(ypmax - ypmin )); /*Creer deux fonction, une pour l'affichage et l'autre pour generer les positions des pommes*/ 
      if (xp < 100 )
      {
        xp = xp + 100;
      }
      if (yp < 95 )
      {
        yp = yp + 100;
      }

    }
  }
}


void PommesAffichage(void){
  couleur couleurPommes;

  for (z = 0; z < 1; ++z)
  {

    couleurPommes=CouleurParNom("red");
    ChoisirCouleurDessin(couleurPommes);
    RemplirRectangle(xp,yp,10,10);
    /*printf("pomme pos x : %d \n",xp );*/

  }

}


/*RAPEL : TROUVEZ ALTERNATIVE CETTE FONCTION QUI SOIT UN PEUT PLUS PROPRE */
/*Cette fonction n'est pas très propre,mais c'est la seule solution que j'ai trouvé */
void TestPommeSerpent(void)
/*Cette fonction permet de detecter une "interaction" entre la pomme et le serpent afin de faire augmenter le score et de generer les nouvelles coordonnées de la pomme suivante */
{
if (x == xp  &&  y == yp)
    {
     Pommes();
     PommesAffichage();
     printf("x:%d y:%d xp:%d yp:%d \n",x,y,xp,yp );


     nscrs = nscrs + 5;
     onpomme = 1;
   }
    if (x == xp+1  &&  y == yp+1)
   {
     Pommes();
     PommesAffichage();
     printf("x:%d y:%d xp:%d yp:%d \n",x,y,xp,yp );


     nscrs = nscrs + 5;
     onpomme = 1;
   }
   if (x == xp-1  &&  y == yp-1)
   {
     Pommes();
     PommesAffichage();
     printf("x:%d y:%d xp:%d yp:%d \n",x,y,xp,yp );


     nscrs = nscrs + 5;
     onpomme = 1;
   }
   if (x == xp+2  &&  y == yp+2)
   {
     Pommes();
     PommesAffichage();
     printf("x:%d y:%d xp:%d yp:%d \n",x,y,xp,yp );


     nscrs = nscrs + 5;
     onpomme = 1;
   }
   if (x == xp-2  &&  y == yp-2)
   {
     Pommes();
     PommesAffichage();
     printf("x:%d y:%d xp:%d yp:%d \n",x,y,xp,yp );


     nscrs = nscrs + 5;
     onpomme = 1;
   }

   if (x == xp-3 &&  y == yp-3)
   {
     Pommes();
     PommesAffichage();
     printf("x:%d y:%d xp:%d yp:%d \n",x,y,xp,yp );


     nscrs = nscrs + 5;
     onpomme = 1;
   }
   if (x == xp+3  &&  y == yp+3)
   {
     Pommes();
     PommesAffichage();
     printf("x:%d y:%d xp:%d yp:%d \n",x,y,xp,yp );


     nscrs = nscrs + 5;
     onpomme = 1;
   }
   if (x == xp-4 &&  y == yp-4)
   {
     Pommes();
     PommesAffichage();
     printf("x:%d y:%d xp:%d yp:%d \n",x,y,xp,yp );


     nscrs = nscrs + 5;
     onpomme = 1;
   }
   if (x == xp+4  &&  y == yp+4)
   {
     Pommes();
     PommesAffichage();
     printf("x:%d y:%d xp:%d yp:%d \n",x,y,xp,yp );


     nscrs = nscrs + 5;
     onpomme = 1;
   }

   if (x == xp-5 &&  y == yp-5)
   {
     Pommes();
     PommesAffichage();
     printf("x:%d y:%d xp:%d yp:%d \n",x,y,xp,yp );


     nscrs = nscrs + 5;
     onpomme = 1;
   }
   if (x == xp+5  &&  y == yp+5)
   {
     Pommes();
     PommesAffichage();
     printf("x:%d y:%d xp:%d yp:%d \n",x,y,xp,yp );


     nscrs = nscrs + 5;
     onpomme = 1;
   }

}

