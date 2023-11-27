#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "type.h"
#include "vaisseau.h"

void dessin_plateau(){
  MLV_draw_filled_rectangle(0,0,T_FENETRE_X,T_FENETRE_Y,MLV_COLOR_BLACK);
  MLV_draw_rectangle(0,25,T_FENETRE_X,T_FENETRE_Y-125,MLV_COLOR_RED);
}

void dessin_barre_vie(int vie){
  int i;
  for(i=0;i<vie;i++){
    MLV_draw_filled_rectangle(0+i*50,T_PLAT_Y+10,50,50,MLV_COLOR_RED);
  }
}

int jeu(vaisseau v){
  while(1){
    dessin_plateau();
    dessin_barre_vie(2);
    dessin_vaisseau(v);
    deplacement_vaisseau(&v);
    MLV_actualise_window();
    MLV_clear_window(MLV_COLOR_BLACK);
    MLV_wait_milliseconds(50);
  }
  return 0;
}
