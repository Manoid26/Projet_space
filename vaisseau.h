#ifndef VAISSEAU_H
#define VAISSEAU_H
typedef struct{
  coord pos;
  int largeur,hauteur;
  int vie;
  int vitesse;
}vaisseau;
#endif
void init_vaisseau(vaisseau *v);
void dessin_vaisseau(vaisseau v);
void deplacement_vaisseau(vaisseau *v);
