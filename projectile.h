#include "type.h"
#include "vaisseau.h"
#ifndef PROJECTILE_H
#define PROJECTILE_H
#define PI 3.141592653
typedef struct{
  int degat;
  int vitesse;
  coord pos;
  int direction;
  float angle;
  int rebond;
}projectile;

typedef struct{
  projectile p_tab[50];
  int acc;
}projectiles;
#endif
void dessin_projectile(projectiles p);
void creer_projectile_vaisseau(float angle,vaisseau v,projectiles *p);
void deplacement_projectile(projectiles *p);
float calcule_angle(int sx, int sy,int vx, int vy);
void verif_collision(projectiles *p);
void capture_piou_piou(vaisseau v,projectiles *p );
