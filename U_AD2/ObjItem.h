#pragma once
//使用するヘッダファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：アイテム
class CObjItem :public CObj
{
public:
	CObjItem() {};
	~CObjItem() {};
	void Init();
	void Action();
	void action();
	void Draw();

	void SetTimeFlag(bool b) { m_flag_time = b; }
private:
	int m_time;
	bool m_flag_time;
};

