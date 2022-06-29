#include"structs.h"
fVec2 VAdd(fVec2 a,fVec2 b){
	fVec2 result={0};
	result.x=a.x+b.x;
	result.y=a.y+b.y;
	return result;
}
fVec2 VSub(fVec2 a,fVec2 b){
	fVec2 result={0};
	result.x=a.x-b.x;
	result.y=a.y-b.y;
	return result;
}
fVec2 VMult(fVec2 a,float b){
	fVec2 result={0};
	result.x=a.x*b;
	result.y=a.y*b;
	return result;
}
