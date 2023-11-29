#include <allegro.h>
#include <stdio.h>
#include <math.h>


#define GFX_WIDTH 800
#define GFX_HEIGHT 600
#define PI 3,1415

#define ESC 27
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4
#define DOWNLEFT 10
#define UPLEFT 8
#define DOWNRIGHT 12
#define UPRIGHT 9

#define BLACK 101
#define RED   104

void init();
void deinit();
void moveBullet(int);
void checkKeys();
void movePlayer(int,char);
void moveBullets();
void createNewBullet();
inline void drawCroshair(int);

struct vec {
	   int x;
	   int y;
	   };
	   
struct controller {
	   vec pos;
	   // future vars //
	   };

struct bullets {
	   vec pos;
	   float angle;
	   vec vector;
	   bool live;
	   };
	   
vec mousepos;
bool gameRunning = true;   
controller player;
int bulletsCount = 0;
bullets bullet[1000]; // max 1000 bullets on screen

int main() 
{
  player.pos.x = 100;
  player.pos.y = 100;
  init();
  
  while(gameRunning){				  
  
				   checkKeys();  
				   
				   drawCroshair(BLACK);
				   
				   mousepos.x = mouse_x;
				   mousepos.y = mouse_y;
				   
				   drawCroshair(RED);
				   
				   if(mouse_b & 1){createNewBullet();}
				   moveBullets();
				   
				   
				   release_screen();
				   clear_keybuf(); 
				   rest(0);
			 
  }

  
  deinit();
  return 0;
  
  
}
END_OF_MAIN()


void moveBullets()
{
 int i;
 
 for(i = 0; i <= bulletsCount - 1; i++)
 {
	   if(!bullet[i].live){break;}
	   moveBullet(i);	  
 }			
}

void moveBullet(int id)
{
 int tx,ty;
 int speed = 5;
 
 if(bullet[id].pos.x < 0 || bullet[id].pos.y < 0 || bullet[id].pos.x > GFX_WIDTH || bullet[id].pos.y > GFX_HEIGHT){bullet[id].live = false;return;}
 tx = bullet[id].pos.x + cos( bullet[id].angle ) * speed;
 ty = bullet[id].pos.y + sin( bullet[id].angle ) * speed;
 
 circlefill(screen,bullet[id].pos.x,bullet[id].pos.x,2,makecol(0,0,0));
 
 bullet[id].pos.x = tx;
 bullet[id].pos.y = ty;
 
 circlefill(screen,bullet[id].pos.x,bullet[id].pos.x,2,makecol(255,123,1239));
 
}


void createNewBullet()
{
   int i;

   bulletsCount++;
   for(i = 0;i <= bulletsCount - 1;i++){
   
   if(!bullet[i].live){
						
						bullet[i].pos.x = player.pos.x;
						bullet[i].pos.y = player.pos.y;
						
						bullet[i].vector.x = mousepos.x - bullet[i].pos.x;
						bullet[i].vector.y = mousepos.y - bullet[i].pos.y;
						
						bullet[i].angle = -atan(  (float)bullet[i].vector.y / (float)bullet[i].vector.x  ) * 180 / (float)PI;
						
						bullet[i].live = true;
						
						break;
						}					   
		 
   }	 
	   
}

inline void drawCroshair(int color)
{
	   
if(	abs(mousepos.x - player.pos.x) <= 33 && abs(mousepos.y - player.pos.y) <= 33){return;}

if(color == BLACK){  circlefill(screen,mousepos.x,mousepos.y,3,makecol(0,0,0)); }	   
if(color == RED){	circlefill(screen,mousepos.x,mousepos.y,3,makecol(255,0,0)); } 
  
}

void checkKeys()
{
	 int pkey;
	 
	 pkey = 0;
	 if(  key[KEY_LEFT] ){pkey = LEFT;}
	 if(  key[KEY_RIGHT]){pkey = RIGHT;}
	 if(  key[KEY_UP]   ){pkey = UP;}
	 if(  key[KEY_DOWN] ){pkey = DOWN;}
	 if(  key[KEY_DOWN] && key[KEY_LEFT]){pkey = DOWNLEFT;}
	 if(  key[KEY_UP] && key[KEY_LEFT]){pkey = UPLEFT;}
	 if(  key[KEY_DOWN] && key[KEY_RIGHT]){pkey = DOWNRIGHT;}
	 if(  key[KEY_UP] && key[KEY_RIGHT]){pkey = UPRIGHT;}
	 
	 if(  key[KEY_ESC]  ){pkey = ESC;}
	 
	 switch(pkey) {
		 case ESC:
			  gameRunning = false;
			  break;
			  
		 case DOWNLEFT:
			  movePlayer(-1,'c');
			  break;
		 case DOWNRIGHT:
			  movePlayer(1,'C');
			  break;
		 case UPLEFT:
			  movePlayer(-1,'C');
			  break;
		 case UPRIGHT:
			  movePlayer(1,'c');
			  break;
			  
		 case LEFT:
			  movePlayer(-1,'x');
			  break;
		 case UP:
			  movePlayer(-1,'y');
			  break;
		 case DOWN:
			  movePlayer(1,'y');
			  break;
		 case RIGHT:
			  movePlayer(1,'x');
			  break;
		 };
		 
}

void movePlayer(int Move,char kind)
{
 
			   circlefill(screen,player.pos.x,player.pos.y,30,makecol(0,0,0));
			   
			   if(kind == 'x'){player.pos.x += Move;}
			   if(kind == 'y'){player.pos.y += Move;}
			   if(kind == 'c'){player.pos.x += Move;player.pos.y += -Move;}
			   if(kind == 'C'){player.pos.x += Move;player.pos.y += Move;}
							
			   circlefill(screen,player.pos.x,player.pos.y,30,makecol(255,123,1239));
			
}


void init() 
{
  int depth, res;
  
  allegro_init();
  
  depth = desktop_color_depth();
  if (depth == 0) depth = 32;
  
  set_color_depth(depth);
  
  res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, GFX_WIDTH, GFX_HEIGHT, 0, 0);
  
  if (res != 0) {
	allegro_message(allegro_error);
	exit(-1);
  }

  install_timer();
  install_keyboard();
  install_mouse();
}

void deinit() 
{
  clear_keybuf();
}

