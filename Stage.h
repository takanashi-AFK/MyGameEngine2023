#pragma once
#include "Engine/GameObject.h"
#include "windows.h"

namespace {
    const int MODEL_NUM{ 5 };
    const int XSIZE{ 15 };
    const int ZSIZE{ 15 };
    enum BLOCKTYPE
    {
        DEFAULT, BRICK, GRASS, SAND, WATER
    };
}

//���������Ǘ�����N���X
class Stage : public GameObject
{
    int hModel_[MODEL_NUM];    //���f���ԍ�
    //int table_[XSIZE][ZSIZE];
    struct BlockData
    {
        int type;
        int height;
    } table_[15][15];

    int mode_;      //0:�グ��@1�F������@2�F��ނ�ς���
    int select_;    //���


public:
    void SetBlockType(int _x, int _z, BLOCKTYPE _type);
    void SetBlockHeight(int _x, int _z, int _height);
    //�R���X�g���N�^
    Stage(GameObject* parent);

    //�f�X�g���N�^
    ~Stage();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
    BOOL DialogProc(HWND hDlg, UINT msg, WPARAM wp, LPARAM lp);
    
    /// <summary>
    /// �e�L�X�g�ł̃Z�[�u
    /// </summary>
    void SaveTXT();
    /// <summary>
    /// �e�L�X�g�ł̃��[�h
    /// </summary>
    void LoadTXT();


    /// <summary>
    /// �o�C�i���ł̃Z�[�u
    /// </summary>
    void SaveBIN();
    /// <summary>
    /// �o�C�i���ł̃��[�h
    /// </summary>
    void LoadBIN();

    void ExChangeType(int bX, int bZ);
};