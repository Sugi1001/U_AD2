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
private:
};


