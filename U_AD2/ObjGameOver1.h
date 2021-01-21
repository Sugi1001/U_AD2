#pragma once
//使用するヘッダー
#include"GameL\SceneManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ゲームオーバー
class CObjGameOver1 :public CObj
{
public:
	CObjGameOver1() {};
	~CObjGameOver1() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;
};
