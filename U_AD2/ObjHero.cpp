//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "Objhero.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHero::Init()
{

	m_px = 100.0f; //位置
	m_py = 0.0f;
	m_vx = 0.0f;//移動ベクトル
	m_vy = 0.0f;
	m_posture = 3.0f; //右向き0.0f　左向き1.0f

	m_ani_time = 0;
	m_ani_frame = 1;//静止フレームを初期にする

	float m_speed_power = 0.5f;//通常速度
	float m_ani_max_time;//アニメーション間隔幅

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = 0;
}

//アクション
void CObjHero::Action()
{
	 
	if (m_py > 1000.0f)
	{
	//場外に出たらリスタート
		Scene::SetScene(new CSceneMain());//CSceneGameOver
	
	}

	//
	if (Input::GetVKey('X') == true)
	{
		if (m_hit_down == true)
		{
			m_vy = - 20;
		}
	}
	//
	////キーの入力方向
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx=-1.5f;
		m_posture = 1.5f;
		m_ani_time+=1;
	}
    else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx=+1.5f;
		m_posture = 0.0f;
		m_ani_time+=2;
	}
	else
	{
		m_ani_frame = 1; //キーが入力が無い場合静止フレームにする
		m_ani_time = 1;
	}
	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame+=1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 1)
	{
		m_ani_frame = 0;
	}
	

	//摩擦
	m_vx += -(m_vx * 0.098);

	//自由落下運動
	m_vy += 9.8 / (16.0f);



	//ブロックとの当たり判定実行
	//CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//pb->BlockHit(&m_px, &m_py, true,
		//&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		//&m_block_type
	//);


	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//主人公の位置X（ｍ＿ｘ）+主人公機の幅分がX軸方向に領域外を認識
	/*if (m_px + 32.0f > 800.0f)
	{
		m_px = 800.0f - 32.0f;
	}*/
}

//ドロー
void CObjHero::Draw()
{
	
	//int AniData[4] = { 1,0,2,0 };

	////描画カラー情報
	//float  c[4] = { 1,0,2,0};
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	////切り取り位置の設定

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;









	//src.m_top = 0.0f;
	//src.m_left = 0.0f; //+ AniData[m_ani_frame] * 64;
	//src.m_right = 64.0f + AniData[m_ani_frame] * 64;
	//src.m_bottom = 64.0f;
//	src.m_top = 64.0f;
//	src.m_left = 64.0f+ AniData[m_ani_frame] * 64;
//	src.m_right = 64.0f+AniData[m_ani_frame] * 64;
//	src.m_left = 64.0f+ AniData[m_ani_frame] * 64
//	src.m_top = 1.0f;
//	src.m_left = 50.0f+ AniData[m_ani_frame] * 50;
//	src.m_right = 64.0f+AniData[m_ani_frame] * 30;
//	src.m_left = 64.0f;//+ AniData[m_ani_frame] * 64;
	//	src.m_right = 64.0f;//+AniData[m_ani_frame] * 64;
	//	src.m_left = 0.0f;//+ AniData[m_ani_frame] * 64;
	//	src.m_right = 64.0f;//+AniData[m_ani_frame] * 64;
	//src.m_bottom = 64.0f;
		//src.m_right = 64.0f;//+AniData[m_ani_frame] * 64;
		//src.m_left = 0.0f;//+ AniData[m_ani_frame] * 64;
		//src.m_right = 64.0f;//+AniData[m_ani_frame] * 64;
	//src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (23 * m_posture) + m_px;
	dst.m_right = (89 - 45.0f * m_posture) + m_px;
	dst.m_bottom = 56-0.1f + m_py;
	dst.m_left =/*(     64.0f*m_posture)*/0.0f + m_px;
	dst.m_right = /*(64-64.0f*m_posture)*/64.0f+m_px;
	dst.m_bottom = 64.0f + m_py;









	//dst.m_top = 0.0f + m_py;
	//dst.m_left = (64 * m_posture) + m_px;
	//dst.m_right = (64 - 64.0f * m_posture) + m_px;
	//dst.m_bottom = 64.0f + m_py;
	//dst.m_top = 1.0f + m_py;
	/*dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f * m_posture) + m_px;
	dst.m_right =  (64 + 64.0f * m_posture) + m_py;
	dst.m_bottom = 64.0f +m_py;
	dst.m_top = 40.0f + m_py;
	dst.m_left = (30.0f * m_posture) + m_px;
	dst.m_right = (40 + 64.0f * m_posture) + m_py;
	dst.m_bottom = 30.0f + m_py;*/

	////描画
	Draw::Draw(1, &src, &dst, c, 0.0f);
	Draw::Draw(10, &src, &dst, c, 1.0f);
	//Draw::Draw(2, &src, &dst, c, 0.0f);
	////Draw::Draw(0, &src, &dst, c, 0.0f);
	////Draw::Draw(0, &src, &dst, c, 1.0f);
}