#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"

//使用するネームペース
using namespace GameL;

//オブジェクト：タイトル
class CObjTitle :public CObj
{
public:
	CObjTitle() {};
	~CObjTitle() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;//キーフラグ
};