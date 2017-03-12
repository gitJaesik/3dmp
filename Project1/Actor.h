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
	// ChildeNode와 Parent노드는 private으로 설정하여 임의로 값을 변경하여 연결관계가 깨지지 않도록 한다.
	std::vector<Actor*> _ChildNode;
	Actor* _ParentNode;
	std::string _ActorName;
};

