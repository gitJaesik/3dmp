#include "Actor.h"

Actor::Actor()
{
	_ChildNode.clear();
	_ParentNode = nullptr;
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

const Actor* Actor::getParentNode()
{
	return _ParentNode;
}

void Actor::setParentNode(Actor* parent_node)
{
	_ParentNode = parent_node;
}