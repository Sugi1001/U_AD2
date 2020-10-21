#pragma once
//使用するヘッダー
#include "GameL\SceneObjManeger.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト : 棘
class CObjToge : public CObj
{
public:
	CObjToge() {};
	~CObjToge() {};
	void Init(); //イニシャライズ
	void Action(); //アクション
	void Draw();  //ドロー
private:
};
