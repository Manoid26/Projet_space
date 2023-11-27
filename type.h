#ifndef TYPES_H
#define TYPES_H
#define T_FENETRE_X 400
#define T_FENETRE_Y 650
#define T_PLAT_DEC 25
#define T_PLAT_Y T_FENETRE_Y - 100

typedef struct{
  int x,y;
}coord;

typedef struct{
  coord c1;
  int largeur,hauteur;
  char message[50];
}bouton;

#endif
