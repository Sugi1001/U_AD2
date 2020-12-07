#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクトタイム
class CObjTyukan : public CObj
{
public:
	CObjTyukan () {};
	~CObjTyukan () {};
	void Init(); //イニシャライズ
	void Action(); //アクション
	void Draw(); //ドロー
private:


};
