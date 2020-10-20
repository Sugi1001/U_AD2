#pragma once
//使用するヘッダー
#include "GameL\SceneObjManaer.h" 
//使用するネームスペース
using namespace GameL;

//オブジェクト
class CObjHero : public CObj
{
public:
	CObjHero() {};
	~CObjHero() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_px; //位置
	float m_py;
	float m_vx; //移動ベクトル
	float m_vy;
};