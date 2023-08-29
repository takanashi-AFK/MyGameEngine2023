#include "Controller.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"

//コンストラクタ
Controller::Controller(GameObject* parent)
    :GameObject(parent, "Controller")
{
    transform_.position_.x = 7.0f;
    transform_.position_.z = 7.0f;
}

//デストラクタ
Controller::~Controller()
{
}

//初期化
void Controller::Initialize()
{
}

//更新
void Controller::Update()
{
    //左回転
    if (Input::IsKey(DIK_LEFT))
    {
        transform_.rotate_.y -= 1.0f;
    }

    //右回転
    if (Input::IsKey(DIK_RIGHT))
    {
        transform_.rotate_.y += 1.0f;
    }

    //transform_.rotate_.yの値に合わせてＹ軸回転させる行列
    XMMATRIX mRotate = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));

    //現在位置をベクトルにしておく
    XMVECTOR vPos = XMLoadFloat3(&transform_.position_);

    //前後移動ベクトル
    XMFLOAT3 frontMove = { 0, 0, 0.1f };                //奥向きのXMFLOAT3構造体を用意し
    XMVECTOR vMove = XMLoadFloat3(&frontMove);               //それをベクトルにする
    vMove = XMVector3TransformCoord(vMove, mRotate);    //戦車の向きに合わせて回転


    if (Input::IsKey(DIK_W))
    {
        vPos += vMove;
        XMStoreFloat3(&transform_.position_, vPos);
    }
    if (Input::IsKey(DIK_S))
    {
        vPos -= vMove;
        XMStoreFloat3(&transform_.position_, vPos);
    }

    //左右移動ベクトル
    XMFLOAT3 rightMove = { 0.1f, 0, 0 };                //右向きのXMFLOAT3構造体を用意し
    vMove = XMLoadFloat3(&rightMove);               //それをベクトルにする
    vMove = XMVector3TransformCoord(vMove, mRotate);    //戦車の向きに合わせて回転


    if (Input::IsKey(DIK_D))
    {
        vPos += vMove;
        XMStoreFloat3(&transform_.position_, vPos);
    }
    if (Input::IsKey(DIK_A))
    {
        vPos -= vMove;
        XMStoreFloat3(&transform_.position_, vPos);
    }


    //カメラ
    XMVECTOR vCam = XMVectorSet(0, 10, -10, 0);
    vCam = XMVector3TransformCoord(vCam, mRotate);
    XMFLOAT3 camPos;
    XMStoreFloat3(&camPos, vPos + vCam);
    Camera::SetPosition(XMLoadFloat3(&camPos));
    Camera::SetTarget(XMLoadFloat3(&transform_.position_));        //カメラの焦点はプレイヤーの位置
}

//描画
void Controller::Draw()
{
}

//開放
void Controller::Release()
{
}