//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include  "ObjEnemyBlock.h"

//使用するヘッダーファイル
using namespace GameL;

//イニシャライズ
void CObjEnemyBlock::Init()
{
	m_px = 100.0f;  //位置
	m_py = 0.0f;    //移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;  //右向き0.0f　左向き　1.0f

	m_ani_time = 0;  //静止フレームを初期にする。
	m_ani_frame = 1;

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4; //アニメーション間隔幅

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

}
//アクション
void CObjEnemyBlock::Action()
{
	//落下
	m_vy += 9.8 / (16.0f);

	//通常速度
	m_speed_power = 0.5f;
	m_ani_max_time = 4;

	//方向
	if (false)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (false)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 1;
		m_ani_time = 0;  //静止フレーム
	}

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//摩擦
	m_vx += -(m_vx * 0.098);

	//自由落下運動
	m_vy += 9.8 / (16.0f);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

}

//ドロー(CObjEnemy Blockのドロー)
void CObjEnemyBlock::Draw()
{
	//描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画先切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 126.0f;
	src.m_right = 96.0f;
	src.m_bottom = 32.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;


	//0番目に登録したグラフィックをsrc.dst.cの情報をもとに描画
	Draw::Draw(0,&src, &dst, c, 0.0f);
