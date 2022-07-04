#include"platform.h"

typedef struct Platform{
	fRect Bbox;
	SDL_Color color;
};

void PlatformInit(platform* plat, float x, float y, float w, float h, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
	plat->Bbox.x=x;
	plat->Bbox.y=y;
	plat->Bbox.w=w;
	plat->Bbox.h=h;
	SDL_Color col;
	col.r=r;
	col.g=g;
	col.b=b;
	col.a=a;
	plat.color=col;
}

void ShowPlatform(SDL_Renderer* renderer, platform* plat){
	SDL_Rect ibox;
	ibox.x=(int)plat->Bbox.x;
	ibox.y=(int)plat->Bbox.y;
	ibox.w=(int)plat->Bbox.w;
	ibox.h=(int)plat->Bbox.h;

	//SDL_SetRenderDrawColor(renderer, ..Hex(ent->color));
}

bool DetectCollisionEntityPlatform(Entity* ent,Platform* plat){
	return !(ent->Bbox.x+ent->Bbox.w<plat->Bbox.x || ent->Bbox.x>plat->Bbox.x+plat->Bbox.w || ent->Bbox.y+ent->Bbox.h<plat->Bbox.y || ent->Bbox.y>plat->Bbox.y+plat->Bbox.h)
}
