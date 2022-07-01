#include<stdio.h>
#define SDL_MAIN_HANDLED
#include<SDL2/SDL.h>
#include"entity.h"

#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 750
#define MAX_JUMP_FRAMES 5
#define PLAYER_ID 0


SDL_Window* window=NULL;
SDL_Renderer* renderer=NULL;
int HeldJump=0;

int main(int argc, char *argv[]){
	printf("Initializing...");
	SDL_Init(SDL_INIT_VIDEO);
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
		if(!keystate[SDL_SCANCODE_W]){
			HeldJump=MAX_JUMP_FRAMES;
		}
		if(player.IsOnGnd){	
			HeldJump=0;
		}
		if(keystate[SDL_SCANCODE_W] && (player.IsOnGnd || HeldJump<MAX_JUMP_FRAMES)){
			player.vel.y-=10.0/(float)(HeldJump+1);
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
		UpdateEntity(&player, WINDOW_WIDTH, WINDOW_HEIGHT);
		//render part
		SDL_SetRenderDrawColor(renderer, 255, 21, 15, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 15, 62, 255, 255);
		ShowEntity(&player,renderer);
		SDL_RenderPresent(renderer);
		SDL_Delay(16);
	}

	SDL_Quit();
	return 0;
}
