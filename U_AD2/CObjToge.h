#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト : 棘
class CObjToge : public CObj
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
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	float m_posture;  //姿勢
    float GetX() { return m_px; }
	float GetY() { return m_py; }
	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }


	int m_ani_time;
	int m_ani_frame;

	


	//blockとの衝突確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
	bool m_block_type;



};
