#include "Player.h"
#include "Engine/Fbx.h"


Player::Player(GameObject* parent)
{


}

Player::~Player()
{

}

void Player::Initialize()
{
	pFbx = new Fbx;
	pFbx->Load("Assets/oden.fbx");
	this->transform_.scale_.x = 0.5;
	this->transform_.scale_.y = 0.5;
	this->transform_.scale_.z = 0.5;
}

void Player::Update()
{
	transform_.rotate_.y += 0.1;
}

void Player::Draw()
{
	pFbx->Draw(transform_);
}

void Player::Release()
{
	pFbx->Release();
	delete pFbx;
}
