#include "Actor.h"

Actor::Actor()
{
	_ChildNode.clear();
	_ParentNode = nullptr;
}

Actor::Actor(const std::string& actorName)
{
	_ActorName = actorName;
}

Actor::~Actor()
{
}




void Actor::update()
{
	for (auto pChildNode : _ChildNode)
	{
		pChildNode->update();
	}
}

const std::vector<Actor*>& Actor::getChildNodes()
{
	return _ChildNode;
}

void Actor::addChildNode(Actor* child_node)
{
	child_node->setParentNode(this);
	_ChildNode.emplace_back(child_node);
}

void Actor::detachChildNode(const std::string& actorName)
{
	//_ChildNode
	for (auto it = _ChildNode.begin(); it != _ChildNode.end(); ++it) {
		auto child_node = *it;
		if (child_node->getActorName().compare(actorName) == 0) {
			child_node->setParentNode(nullptr);
			_ChildNode.erase(it);
			return;
		}
	}
}

const Actor* Actor::getParentNode()
{
	return _ParentNode;
}

void Actor::setParentNode(Actor* parent_node)
{
	_ParentNode = parent_node;
}