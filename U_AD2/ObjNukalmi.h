#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:ぬかるみブロック&背景
class CObjNukalmi : public CObj
{
public:
	CObjNukalmi() {};
	~CObjNukalmi() {};
	void Init();
	void Action();
	void Draw();
private:
};
