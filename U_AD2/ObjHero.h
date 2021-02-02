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

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }
	int GetBT() { return m_block_type; }

	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }
	void SetBT(int t) { m_block_type = t; }

	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }

	float GetScroll() {
		return m_scroll;
	}

private:
	float m_px; //位置
	float m_py;
	float m_vx; //移動ベクトル
	float m_vy;
	float m_posture; //姿勢
	int m_ani_time;
	int m_ani_frame;
	float m_x;
	float m_y;
	int m_hp;//主人公のHP //主人公のひっとぽいんと]

	float hit;
	float m_scroll;

	//int m_ani_time = 0;//アニメーションフレーム動作間隔
	//int m_ani_frame = 1;//描画フレーム  //静止フレームを初期にする。
	int m_map[10][500] = { 0 };
	
	float m_ani_max_time;//アニメーション動作間隔最大値

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//踏んでいるblockの種類確認用
	int m_block_type;
};