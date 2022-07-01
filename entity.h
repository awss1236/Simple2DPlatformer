#include<SDL2/SDL.h>
#include<stdbool.h>
#include"structs.h"

typedef struct Entity{
	int type;
	fRect Bbox;
	fVec2 vel;
	bool IsOnGnd;
}Entity;

void InitEntity(Entity* ent,int type, float x, float y, float w, float h, float velx, float vely);

void UpdateEntity(Entity* ent, int width, int height);

void ShowEntity(Entity* ent, SDL_Renderer* renderer);
