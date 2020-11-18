#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ボス機
class CObjEnemy :public CObj
{

public:
	CObjEnemy(float x, float y) {};
	~CObjEnemy() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;//敵機のX方向の位置
	float m_y;//敵機のY方向に位置
	float m_vx;//敵機移動ベクトルｘ
	float m_vy;//敵機移動ベクトルｙ
};
