#include "PlayScene.h"
#include "Engine/Fbx.h"
#include "Player.h"
//class Player;

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{

}

void PlayScene::Initialize()
{
	Player* pPlayer;
	pPlayer = new Player(this);
	pPlayer->Initialize();
	childList_.push_back(pPlayer);
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
