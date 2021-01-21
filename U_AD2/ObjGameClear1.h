#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ゲームクリア
class CObjClear3 :public CObj
{
public:
	CObjClear3() {};
	~CObjClear3() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
private:
	bool m_key_flag;//キーフラグ
};


