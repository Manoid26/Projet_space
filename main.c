#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "type.h"
#include "menu.h"
#include "jeu.h"
#include "vaisseau.h"

int main(){
  int continuer=0;
  vaisseau v;
  MLV_create_window("Porjet_de_C","shoot",T_FENETRE_X,T_FENETRE_Y);

  while(continuer!=3){
    MLV_actualise_window();
    MLV_clear_window(MLV_COLOR_BLACK);
    continuer=menu();
    switch(continuer){
    case(1):
      printf("jouer\n");
      init_vaisseau(&v);
      jeu(v);
      break;
    case(2):
      printf("sauvegarder\n");
      break;
    case(3):
      printf("quitter\n");
      break;
    }
  }
  exit(0);
}
