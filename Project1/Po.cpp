#include "Po.h"



Po::Po()
{
	// theta ÃÊ±âÈ­
	_theta = 90.0f * (3.141592f / 180.0f);			// degree to radian,  radian to degree
	_gun_barrel_length = 5.0f;
}


Po::~Po()
{
}

void Po::update()
{	
	actorInfo._pt.x = cosf(_theta) * _gun_barrel_length + _ParentNode->actorInfo._pt.x;
	actorInfo._pt.y = sinf(_theta) * _gun_barrel_length + _ParentNode->actorInfo._pt.y;

}