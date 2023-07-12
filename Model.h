#pragma once
//必要なインクルードを書く

namespace Model
{
	struct ModelData
	{
		//FBX
		//トランスフォーム
		//ファイル名
	};
	//モデルのポインタをぶち込んでおくベクタ
}

int Model::Load(std::string fileName)
{
	//ファイル名のモデルを読み込んで、同じモデル名のものがあったらそのモデル番号（配列のインデックス-1）を返す関数
	//同じ名前のモデルがなかったら、モデルを読み込んで、ベクタに追加
}

