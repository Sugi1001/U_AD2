//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjHero.h"

#include "ObjStageBlock.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHero::Init()
{

	m_px = 1.0f; //位置
	m_py = 0.0f;
	m_vx = 1.0f;//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f; //右向き0.0f　左向き1.0f

	m_ani_time = 0;
	m_ani_frame = 1;//静止フレームを初期にする

	float m_speed_power = 1.0f;//通常速度
	float m_ani_max_time;//アニメーション間隔幅


	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;



	m_block_type = 0; //踏んでいるブロックの種類を確認用

	m_scroll -=2.0f;

}

//アクション
void CObjHero::Action()
{


	if (m_py > 1000.0f)
	{
		//場外に出たらリスタート
		Scene::SetScene((new CSceneGameOver()));//CSceneGameOver

		

	}

	

	

	

	




	if (Input::GetVKey('X') == true)
	{
		if (m_hit_down == true)
		{
			m_vy = -20;
		}
	}

	////キーの入力方向
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx = +1.5f;
		m_vx = -5.0f;
		m_posture = 1.5f;
		m_ani_time += 1;
	}
	if (m_ani_time > 4)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx = -10.5f;
		m_vx = +3.0f;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 1; //キーが入力が無い場合静止フレームにする
		m_ani_time = 1;
		m_vx -= 0.22f;
	}


	//摩擦
	m_vx += -(m_vx * 0.098);

	//自由落下運動
	m_vy += 10.8 / (16.0f);

	//ブロックとの当たり判定実行
	CObjStageBlock* pb = (CObjStageBlock*)Objs::GetObj(OBJ_STAGE_BLOCK);
	pb->BlockHit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vy, &m_vx,
	    &m_block_type);



		//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//主人公の位置X（ｍ＿ｘ）+主人公機の幅分がX軸方向に領域外を認識
	if (m_px + 20.0f > 800.0f)
	{
		m_px = 800.0f - 20.0f;
	}
}

//ドロー
void CObjHero::Draw()
{

	///描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	



	//主人公１
	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (40.0f * m_posture) + m_px;
	dst.m_right = (64 - 50.0f * m_posture) + m_px;
	dst.m_bottom = 64.0 + m_py;

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;



	//描画
	Draw::Draw(1, &src, &dst, c, 1.0f);
}