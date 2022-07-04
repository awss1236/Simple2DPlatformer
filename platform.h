#include<stdbool>
#include"structs.h"
#include"entity.h"

typedef struct Platform{
	fRect Bbox;
	SDL_Color color;
}Platform;

bool DetectCollisionEntityPlatform(Entity* ent,Platform* plat);
void PlatformInit(platform* plat, float x, float y, float w, float h, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void ShowPlatform(SDL_Renderer* renderer, platform* plat);
