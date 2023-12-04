#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <MLV/MLV_all.h>
#include "projectile.h"
#include "vaisseau.h"

void dessin_projectile(projectiles p){
  int i;
  for(i=0;i<p.acc;i++){
    MLV_draw_rectangle(p.p_tab[i].pos.x,p.p_tab[i].pos.y,20,20,MLV_COLOR_GREEN);
  }
}

void creer_projectile_vaisseau(float angle,vaisseau v,projectiles *p){
  p->p_tab[p->acc].degat=1;
  p->p_tab[p->acc].vitesse=5;
  p->p_tab[p->acc].pos.x=v.pos.x+(v.largeur/2);
  p->p_tab[p->acc].pos.y=v.pos.y;
  p->p_tab[p->acc].angle=angle;
  p->p_tab[p->acc].rebond=2;
}

void deplacement_projectile(projectiles *p){
  int i;
  float dep_x,dep_y;
  for(i=0;i<p->acc;i++){
    dep_x=cos(p->p_tab[i].angle);
    dep_y=sin(p->p_tab[i].angle);
  
    p->p_tab[i].pos.x+=p->p_tab[i].vitesse*dep_x;
    p->p_tab[i].pos.y-=p->p_tab[i].vitesse*dep_y;
  }
}

float calcule_angle(int sx, int sy,int vx, int vy){
  return atan2(vy-sy,sx-vx);
}

void verif_collision(projectiles *p){
  int i=0;
  for(i=0;i<p->acc;i++){
    if(p->p_tab[i].rebond>0 && (p->p_tab[i].pos.x <= 0
				 || p->p_tab[i].pos.x >= T_FENETRE_X-20)){
      p->p_tab[i].rebond--;
      if(p->p_tab[i].angle<PI){
	p->p_tab[i].angle=acos(cos(p->p_tab[i].angle)*-1);
      }
      else{
	printf("angle avant changement %f \n",p->p_tab[i].angle);
	p->p_tab[i].angle=acos(cos(p->p_tab[i].angle)*-1);
	printf("angle apres changement %f \n",p->p_tab[i].angle);
	
	printf("Angle theorique apres changement %f\n", (PI/4)*7);
      }
    }
  }
}
void capture_piou_piou(vaisseau v,projectiles *p ){
  int x,y;
  float angle;
  angle=(PI/2);
  if( MLV_get_keyboard_state( MLV_KEYBOARD_SPACE) == MLV_PRESSED){
    creer_projectile_vaisseau(angle,v,p);
    p->acc++;
  }
  if( MLV_get_keyboard_state( MLV_KEYBOARD_r) == MLV_PRESSED){
    angle=(PI/4)*5;
    creer_projectile_vaisseau(angle,v,p);

    p->acc++;
  }
  else if( MLV_get_mouse_button_state( MLV_BUTTON_LEFT ) == MLV_PRESSED ){
     MLV_get_mouse_position(&x,&y); 	
     creer_projectile_vaisseau(calcule_angle(x,y,v.pos.x,v.pos.y),v,p);
     p->acc++;
  }
}
