#include"vec2.h"
iVec2 VAdd(iVec2 a,iVec2 b){
	iVec2 result={0};
	result.x=a.x+b.x;
	result.y=a.y+b.y;
	return result;
}
iVec2 VSub(iVec2 a,iVec2 b){
	iVec2 result={0};
	result.x=a.x-b.x;
	result.y=a.y-b.y;
	return result;
}
