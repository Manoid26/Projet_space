#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include "type.h"
#include "vaisseau.h"


void init_vaisseau(vaisseau *v){
  v->largeur=50;
  v->hauteur=50;
  v->vitesse=10;
  v->vie=3;
  v->pos.x=(T_FENETRE_X/2)-(v->largeur/2);
  v->pos.y=(T_PLAT_Y)-(v->hauteur);
}

void dessin_vaisseau(vaisseau v){
  MLV_draw_rectangle(v.pos.x,v.pos.y,v.largeur,v.hauteur,MLV_COLOR_GREEN);
}

void deplacement_vaisseau(vaisseau *v){
    if( MLV_get_keyboard_state( MLV_KEYBOARD_q ) == MLV_PRESSED){
      v->pos.x-=v->vitesse;
    }
    if( MLV_get_keyboard_state( MLV_KEYBOARD_d ) == MLV_PRESSED){
      v->pos.x+=v->vitesse;
    }
    if( MLV_get_keyboard_state( MLV_KEYBOARD_z ) == MLV_PRESSED){
      v->pos.y-=v->vitesse;
    }
    if( MLV_get_keyboard_state( MLV_KEYBOARD_s ) == MLV_PRESSED){
      v->pos.y+=v->vitesse;
    }

    if(v->pos.x <0){
      v->pos.x=0;
    }
     if(v->pos.x >T_FENETRE_X-v->largeur){
      v->pos.x=T_FENETRE_X-v->largeur;
    }
     if(v->pos.y < T_PLAT_DEC){
       v->pos.y = T_PLAT_DEC;
     }
     if(v->pos.y> T_PLAT_Y -v->hauteur){
       v->pos.y=T_PLAT_Y -v->hauteur;
     }
     
}
