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
	float VK_RIGHT;
	float VK_LEFT;
	float m_posture; //姿勢

	int m_ani_time;//アニメーションフレーム動作間隔
	int m_ani_frame;//描画フレーム

	
	float m_ani_max_time;//アニメーション動作間隔最大値

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};