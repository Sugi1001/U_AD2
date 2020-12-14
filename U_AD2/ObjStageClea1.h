#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"
using namespace GameL;
//オブジェクト：ゲームクリア
class CObjClear1 :public CObj
{
public:
	CObjClear1() {};
	~CObjClear1() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
private:
	bool m_key_flag;//キーフラグ
};

