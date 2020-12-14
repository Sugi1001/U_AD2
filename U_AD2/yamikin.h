#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ボス機
class CObjyamikin :public CObj
{

public:
	CObjyamikin(float x, float y);
	~CObjyamikin() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_y;//敵機のY方向に位置
	float m_vx;//敵機移動ベクトルｘ
	float m_vy;//敵機移動ベクトルｙ
	float m_r;//サインカーブ用角度
	int m_time;//弾丸間隔速度
	int m_hp;//ボスのヒットポイント
};


