#pragma once

#include œœœœœ
#include œœœœœ
#include œœœœœ

class GameObject
{
	œœœœœœœœ childList_;
	Transform		transform_;
	œœœœœœ	pParent_;
	œœœœœœ	objectName_;

public:
	GameObject();
	GameObject(GameObject* parent, const std::string& name);
	~GameObject();

	œœœœ void Initialize() œœœ;
	œœœœ void Update() œœœ;
	œœœœ void Draw() œœœ;
	œœœœ void Release() œœœ;
};