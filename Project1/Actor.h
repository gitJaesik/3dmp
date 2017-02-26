#pragma once
#include "ActorInfo.h"
#include <vector>
#include <memory>

class Actor
{
public:
	Actor();
	~Actor();
	ActorInfo actorInfo;

	virtual void update();

	const std::vector<Actor*>& getChildNodes();
	void addChildNode(Actor* child_node);

	const Actor* getParentNode();
	void setParentNode(Actor* parent_node);

private:
	// ChildeNode�� Parent���� private���� �����Ͽ� ���Ƿ� ���� �����Ͽ� ������谡 ������ �ʵ��� �Ѵ�.
	std::vector<Actor*> _ChildNode;
	Actor* _ParentNode;
};

