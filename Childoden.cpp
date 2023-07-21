#include "Childoden.h"
#include "Engine/Fbx.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Childoden::Childoden(GameObject* parent)
	:GameObject(parent, "ChildOden"),hModel_(-1)
{
}

Childoden::~Childoden()
{
}

void Childoden::Initialize()
{
    hModel_ = Model::Load("Assets/oden.fbx");
    assert(hModel_ >= 0);//ƒ‚ƒfƒ‹”Ô†‚ª-1‚Ì‚Ü‚Ü‚¾‚Á‚½‚ç‚ ‚³[‚Æ‚Éˆø‚Á‚©‚©‚é

    transform_.scale_.x = 0.2f;
    transform_.scale_.y = 0.2f;
    transform_.scale_.z = 0.2f;
    //transform_.position_.x = 2.0f;
    //transform_.position_.y = 1.0f;
    SphereCollider* col = new SphereCollider(1.0);
    AddCollider(col);
}

void Childoden::Update()
{
    transform_.rotate_.y++;
    transform_.position_.z += 0.5f;
    if (transform_.position_.z > 50)
    {
        KillMe();
    }
}

void Childoden::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void Childoden::Release()
{

}
