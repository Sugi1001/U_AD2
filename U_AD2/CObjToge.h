#pragma once
//使用するヘッダー
#include "GameL\SceneObjManeger.h"
#include  "GameHead.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト : 棘
class CobjToge : public CObj
{
public:
	CObjToge() {};
	~CObjToge() {};
	void Init(); //イニシャライズ
	void Action(); //アクション
	void Draw();  //ドロー
private:
	float m_px;   //位置
	float m_py;

	//blockとの衝突確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;


};
