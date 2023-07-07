#pragma once

#include <list>
#include <string>
#include "Transform.h"

using std::string;
using std::list;
class GameObject
{
protected:
	list<GameObject *>	childList_;
	Transform			transform_;
	GameObject*			pParent_;
	string				objectName_;

public:
	GameObject();
	GameObject(GameObject* parent, const std::string& name);
	~GameObject();

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Release() = 0;
	void DrawSub();
};