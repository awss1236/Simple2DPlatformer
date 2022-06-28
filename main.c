#include<stdio.h>
#include<stdbool.h>
#define SDL_MAIN_HANDLED
#include<SDL2/SDL.h>
#include"vec2.h"

#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 750

typedef struct Entity{
	SDL_Rect Bbox;
	iVec2 vel;
}Entity;

void UpdateEntity(Entity* ent){
	ent->Bbox.x+=ent->vel.x;
	ent->Bbox.y+=ent->vel.y;
	if(ent->Bbox.x+ent->Bbox.w>=WINDOW_WIDTH){
		ent->Bbox.x=WINDOW_WIDTH-ent->Bbox.w;
	}else if(ent->Bbox.x<=0){
		ent->Bbox.x=0;
	}
	if(ent->Bbox.y+ent->Bbox.h>=WINDOW_HEIGHT){
		ent->Bbox.y=WINDOW_HEIGHT-ent->Bbox.h;
	}else if(ent->Bbox.y<=0){
		ent->Bbox.y=0;
	}

}
SDL_Window* window=NULL;
SDL_Renderer* renderer=NULL;

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
	player.Bbox.x=50;
	player.Bbox.y=50;
	player.Bbox.w=50;
	player.Bbox.h=50;
	player.vel.x=0;
	player.vel.y=0;
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
		if(keystate[SDL_SCANCODE_W]){
			player.vel.y--;
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
		SDL_RenderDrawRect(renderer, &player.Bbox);
		SDL_RenderFillRect(renderer, &player.Bbox);
		SDL_RenderPresent(renderer);
		SDL_Delay(16);
	}

	SDL_Quit();
	return 0;
}
