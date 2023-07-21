#include "PlayScene.h"
#include "Engine/Fbx.h"
#include "Player.h"
#include "Enemy.h"

PlayScene::PlayScene(GameObject* parent)
{
}

void PlayScene::Initialize()
{
	//Player* pPlayer;
	//pPlayer = new Player(this);//プレイヤーの親は、自分（PlayScene)
	//pPlayer->Initialize();
	//childList_.push_back(pPlayer);//PlaySceneの子として、プレイヤーを登録
	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
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
