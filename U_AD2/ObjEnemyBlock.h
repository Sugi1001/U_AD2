#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト : プロジェクト&背景
class CObjEnemyBlock : public CObj
{
public :
	CObjEnemyBlock() {};
	~CObjEnemyBlock() {};
	void Init();  //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
	
private:
	float m_px;  //位置
	float m_py;   //移動ベクトル
	float m_vx;
	float m_vy;  //姿勢
	float m_posture;
	float m_x;
	float m_y;
	float m_stop_flag;
	/*int m_block_type;*/
	int GetMap(int x, int y);
	void SetMap(int x, int y, int id);

	float GetX() { return m_px; }
	float GetY() { return m_py; }

	int m_ani_time;  //アニメーションフレーム動作間隔
	int m_ani_frame; //描画フレーム
	int m_map[10][10] = { 0 };

	float m_speed_power; //スピードパワー
	float m_ani_max_time; //アニメーション動作間隔最大値

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
	int m_stop_map_y;//動いてない時のマップ位置X番号
	int m_stop_map_x;//動いてない時のマップ位置Y番号


};

