#pragma once

#include <DirectXMath.h>
#include "Direct3D.h"
#include "Texture.h"

using namespace DirectX;

//コンスタントバッファー
struct CONSTANT_BUFFER
{
	XMMATRIX	matWVP;
	XMMATRIX	matW;
};

struct VERTEX
{
	XMVECTOR postion;
	XMVECTOR uv;
	XMVECTOR normal;

};

class Quad
{
	ID3D11Buffer* pVertexBuffer_;	//頂点バッファ
	ID3D11Buffer* pIndexBuffer_;
	ID3D11Buffer* pConstantBuffer_;	//コンスタントバッファ
	Texture* pTextue_;
public:
	Quad();
	~Quad();
	HRESULT Initialize();
	void Draw(XMMATRIX& worldMatrix);
	void Release();
};