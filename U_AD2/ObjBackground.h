#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"ObjTitle.h"
//使用するネームスペース
using namespace GameL;

class CObjBackground:public CObj
{
public:
	CObjBackground() {};
	~CObjBackground() {};
	void Init();  //委任社ラウズ
	void Action();//悪地温
	void Draw();  //泥ー
private:

};

