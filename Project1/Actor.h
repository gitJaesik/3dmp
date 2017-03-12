#pragma once
#include "ActorInfo.h"
#include <vector>
#include <memory>
#include <string>

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

	bool isEqualActorName(const std::string& name) {
		return _ActorName == name;
	}

	const std::string& getActorName() const { return _ActorName; }
	void setActorName(const std::string& actorName) { _ActorName = actorName; }

private:
	// ChildeNode�� Parent���� private���� �����Ͽ� ���Ƿ� ���� �����Ͽ� ������谡 ������ �ʵ��� �Ѵ�.
	std::vector<Actor*> _ChildNode;
	Actor* _ParentNode;
	std::string _ActorName;
};

