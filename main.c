#include<stdio.h>
#include<stdbool.h>
#define SDL_MAIN_HANDLED
#include<SDL2/SDL.h>
#include"structs.h"

#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 750
#define PLAYER_ID 0

SDL_Window* window=NULL;
SDL_Renderer* renderer=NULL;
bool PlayerOnGnd=false;
int HeldJump=0;

typedef struct Entity{
	int id;
	fRect Bbox;
	fVec2 vel;
}Entity;

void InitEntity(Entity* ent,int id, float x, float y, float w, float h, float velx, float vely){
	ent->id=id;
	ent->Bbox.x=x;
	ent->Bbox.y=y;
	ent->Bbox.w=w;
	ent->Bbox.h=h;
	ent->vel.x=velx;
	ent->vel.y=vely;
}

void UpdateEntity(Entity* ent){
	ent->Bbox.x+=ent->vel.x;
	ent->Bbox.y+=ent->vel.y;
	ent->vel=VMult(ent->vel,0.98);
	if(ent->vel.y>0.){
		//falling
		ent->vel.y+=3;
	}else{
		//!falling
		ent->vel.y+=1;
	}
	if(ent->Bbox.x+ent->Bbox.w>=WINDOW_WIDTH){
		ent->Bbox.x=WINDOW_WIDTH-ent->Bbox.w;
	}else if(ent->Bbox.x<=0){
		ent->Bbox.x=0;
	}
	if(ent->Bbox.y+ent->Bbox.h>=WINDOW_HEIGHT){
		ent->Bbox.y=WINDOW_HEIGHT-ent->Bbox.h;
		ent->vel.y=0;
		PlayerOnGnd=true;
		HeldJump=0;
	}else if(ent->Bbox.y<=0){
		ent->Bbox.y=0;
	}

}
void ShowEntity(Entity* ent){
	SDL_Rect ibox;
	ibox.x=(int)ent->Bbox.x;
	ibox.y=(int)ent->Bbox.y;
	ibox.w=(int)ent->Bbox.w;
	ibox.h=(int)ent->Bbox.h;
	SDL_RenderDrawRect(renderer, &ibox);
	SDL_RenderFillRect(renderer, &ibox);
}
int main(int argc, char *argv[]){
	SDL_Init(SDL_INIT_VIDEO);
	printf("hello world!\n");
	window = SDL_CreateWindow("hlo",50, 50, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	if(!window){
		printf("can't create window.");
		SDL_Quit();
		return -1;
	}
	renderer=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(!renderer){
		printf("can't create renderer.");
		SDL_Quit();
		return -1;
	}
	Entity player;
	InitEntity(&player,PLAYER_ID,100,100,50,75,0,0);
	bool quit =false;
	//"frame" loop
	while(!quit){
		//event loop
		SDL_Event e;
		while(SDL_PollEvent(&e)){
			switch(e.type){
				case SDL_QUIT:
					quit=true;
					break;
				case SDL_KEYDOWN:
					if(e.key.keysym.sym==SDLK_q){
						quit=true;
						break;
					}
					
			}
		}
		//process input
		const Uint8* keystate = SDL_GetKeyboardState(NULL);
		if(keystate[SDL_SCANCODE_W] && (PlayerOnGnd || HeldJump<5)){
			player.vel.y-=10.0/(float)(HeldJump+1);
			PlayerOnGnd=false;
			HeldJump++;
		}else if(keystate[SDL_SCANCODE_S]){
			player.vel.y++;
		}

		if(keystate[SDL_SCANCODE_A]){
			player.vel.x--;
		}else if(keystate[SDL_SCANCODE_D]){
			player.vel.x++;
		}
		//update part
		UpdateEntity(&player);
		//render part
		SDL_SetRenderDrawColor(renderer, 255, 21, 15, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 15, 62, 255, 255);
		ShowEntity(&player);
		SDL_RenderPresent(renderer);
		SDL_Delay(16);
	}

	SDL_Quit();
	return 0;
}
