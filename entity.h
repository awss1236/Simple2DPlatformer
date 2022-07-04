#include<SDL2/SDL.h>
#include<stdbool.h>
#include"structs.h"

typedef struct Entity{
	int type;
	fRect Bbox;
	fVec2 vel;
	Uint32 color;
	bool IsOnGnd;
}Entity;

void InitEntity(Entity* ent,int type, float x, float y, float w, float h, float velx, float vely, Uint32 col);

void UpdateEntity(Entity* ent, int width, int height);

void ShowEntity(SDL_Renderer* renderer, Entity* ent);
