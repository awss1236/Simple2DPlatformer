#include"entity.h"

void InitEntity(Entity* ent,int type, float x, float y, float w, float h, float velx, float vely){
	ent->type=type;
	ent->Bbox.x=x;
	ent->Bbox.y=y;
	ent->Bbox.w=w;
	ent->Bbox.h=h;
	ent->vel.x=velx;
	ent->vel.y=vely;
}

void UpdateEntity(Entity* ent, int width, int height){
	ent->Bbox.x+=ent->vel.x;
	ent->Bbox.y+=ent->vel.y;
	ent->vel=VMult(ent->vel,0.98);
	if(ent->vel.y>0.){
		//falling
		ent->vel.y+=1.5;
	}else{
		//!falling
		ent->vel.y+=1;
	}
	if(ent->Bbox.x+ent->Bbox.w>=width){
		ent->Bbox.x=width-ent->Bbox.w;
	}else if(ent->Bbox.x<=0){
		ent->Bbox.x=0;
	}
	ent->IsOnGnd=false;
	if(ent->Bbox.y+ent->Bbox.h>=height){
		ent->Bbox.y=height-ent->Bbox.h;
		ent->vel.y=0;
		ent->IsOnGnd=true;
	}else if(ent->Bbox.y<=0){
		ent->Bbox.y=0;
	}

}
void ShowEntity(Entity* ent, SDL_Renderer* renderer){
	SDL_Rect ibox;
	ibox.x=(int)ent->Bbox.x;
	ibox.y=(int)ent->Bbox.y;
	ibox.w=(int)ent->Bbox.w;
	ibox.h=(int)ent->Bbox.h;
	SDL_RenderDrawRect(renderer, &ibox);
	SDL_RenderFillRect(renderer, &ibox);
}
