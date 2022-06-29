typedef struct fVec2{
	float x,y;
}fVec2;

typedef struct fRect{
	float x,y,w,h;
}fRect;

fVec2 VAdd(fVec2 a, fVec2 b);
fVec2 VSub(fVec2 a, fVec2 b);
fVec2 VMult(fVec2 a, float s);
