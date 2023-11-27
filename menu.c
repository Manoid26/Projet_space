#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <MLV/MLV_all.h>
#include "type.h"


void dessin_bouton(bouton b1,MLV_Font *font){
  MLV_draw_adapted_text_box_with_font(b1.c1.x,b1.c1.y,b1.message,font,10,MLV_COLOR_WHITE,MLV_COLOR_WHITE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
}

bouton creer_bouton(int y, char *message, MLV_Font*font){
  int x_mid,largeur,hauteur;
  bouton b1;
  MLV_get_size_of_adapted_text_box_with_font(message,font,10,&largeur,&hauteur);
  x_mid= (T_FENETRE_X/2)-(largeur/2);
  b1.c1.x=x_mid;
  b1.c1.y=y;
  b1.largeur=largeur;
  b1.hauteur=hauteur;
  strcpy(b1.message,message);
  return b1;
}

int verifier_bouton(bouton b1,int souris_x,int souris_y){
  if(souris_x>=b1.c1.x &&
     souris_x<=b1.c1.x+b1.largeur &&
     souris_y>=b1.c1.y &&
     souris_y<=b1.c1.y+b1.hauteur){
    printf("yes\n");
    return 1;
  }
  else{
    return 0;
  }
}

int menu(){
  int x,y,var_menu=-1;
  MLV_Font* font;
  MLV_Event type_event=MLV_NONE;
  MLV_Keyboard_button touche;
  bouton b1,b2,b3;
  font = MLV_load_font("assets/Ghibo Talk.otf",20);
  
  b1=creer_bouton(250,"START",font);
  b2=creer_bouton(300,"SAUVEGARDE",font);
  b3=creer_bouton(350,"QUITTER",font);
  
  while(var_menu == -1){
    dessin_bouton(b1,font);
    dessin_bouton(b2,font);
    dessin_bouton(b3,font);
    MLV_actualise_window();
    MLV_clear_window(MLV_COLOR_BLACK);
    
    type_event = MLV_wait_keyboard_or_mouse( &touche, NULL, NULL, &x, &y );
    if( type_event == MLV_MOUSE_BUTTON ){
      if(verifier_bouton(b1,x,y)){
	var_menu=1;
      }
      if(verifier_bouton(b2,x,y)){
	var_menu=2;
      }
      if(verifier_bouton(b3,x,y)){
	var_menu=3;
      }
    }
    if(touche==MLV_KEYBOARD_ESCAPE){
      var_menu=3;
    }
  }
  return var_menu;
}
