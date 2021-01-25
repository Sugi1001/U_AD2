#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"
using namespace GameL;
//オブジェクト：ゲームクリア
class CObjClear2 :public CObj
{
public:
	CObjClear2() {};
	~CObjClear2() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
private:
	bool m_key_flag;//キーフラグ
};