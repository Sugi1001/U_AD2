#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h" 
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
	float m_posture; //姿勢

	int m_ani_time;//アニメーションフレーム動作間隔
	int m_ani_frame;//描画フレーム

	float m_speed_power = 0.5f;//通常速度
	float m_ani_max_time;//アニメーション間隔幅
};