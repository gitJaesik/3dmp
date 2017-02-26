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
	// ChildeNode와 Parent노드는 private으로 설정하여 임의로 값을 변경하여 연결관계가 깨지지 않도록 한다.
	std::vector<Actor*> _ChildNode;
	Actor* _ParentNode;
};

