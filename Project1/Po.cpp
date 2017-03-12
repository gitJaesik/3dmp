#include "Po.h"



Po::Po()
{
	// theta �ʱ�ȭ
	_theta = -90.0f * (3.141592f / 180.0f);			// degree to radian,  radian to degree
	_gun_barrel_length = 7.0f;
}


Po::~Po()
{
}

// Hero�� �� _theta ���� �������� �ڵ����� ��ǥ ������Ʈ
void Po::update()
{	
	Actor::update();

	actorInfo._pt.x = cosf(_theta) * _gun_barrel_length + getParentNode()->actorInfo._pt.x;
	actorInfo._pt.y = sinf(_theta) * _gun_barrel_length + getParentNode()->actorInfo._pt.y;
}