#include "Po.h"



Po::Po()
{
	// theta 초기화
	_theta = -90.0f * (3.141592f / 180.0f);			// degree to radian,  radian to degree
	_gun_barrel_length = 7.0f;
}


Po::~Po()
{
}

// Hero가 준 _theta 값을 기준으로 자동으로 좌표 업데이트
void Po::update()
{	
	Actor::update();

	actorInfo._pt.x = cosf(_theta) * _gun_barrel_length + getParentNode()->actorInfo._pt.x;
	actorInfo._pt.y = sinf(_theta) * _gun_barrel_length + getParentNode()->actorInfo._pt.y;
}