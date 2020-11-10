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
	m_posture =0.0f; //右向き0.0f　左向き1.0f

	m_ani_time = 0;
	m_ani_frame = 0;//静止フレームを初期にする

	float m_speed_power = 6.0f;//通常速度
	float m_ani_max_time;//アニメーション間隔幅

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	

	m_block_type = 0;

	m_scroll = 0;

	
}

//アクション
void CObjHero::Action()
{
	//HitBoxの内容を更新
	//CHitBox* hit = Hits::GetHitBox(this);
	//hit->SetPos(m_x, m_y);

	//棘が主人公に接触したら主人公のHPを減らす
	//if (hit->CheckObjNameHit(OBJ_TOGE) != nullptr)
	//{
		//m_hp -= 2;
	//}
	//移動ベクトルの破棄
	 
	if (m_py > 1000.0f)
	{
	//場外に出たらリスタート
		Scene::SetScene((new CSceneMain()));//CSceneGameOver
	
	}

	////当たり判定を行うオブジェクト情報部
	//int data_base[3] =
	//{
	//	OBJ_HERO,
	//	OBJ_TOGE,
	//	OBJ_ENEMY_BLOCK,

	//};

	//オブジェクト情報部と当たり判定を行い当たっていれば、HPを1減らす
	//for (int i = 0; i < 3; i++)
	//{
		//if (hit->CheckObjNameHit(OBJ_TOGE) != nullptr)
		//{
			//m_hp -= 1;
		//}

	//}

	//HPが0になったら破棄
	//if (m_hp <= 0)
	//{
		//this->SetStatus(false);
		//Hits::DeleteHitBox(this);
	//}



	
	if (Input::GetVKey('X') == true)
	{
		if (m_hit_down == true)
		{
			m_vy = - 20;
		}
	}
	
	////キーの入力方向
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx=+1.5f;
		m_vx=-3.0f;
		m_posture = 1.5f;
		m_ani_time+=1;
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
		m_vx=-1.5f;
		m_vx=+3.0f;
		m_posture = 0.0f;
		m_ani_time+=1;
	}
	else
	{
		m_ani_frame = 1; //キーが入力が無い場合静止フレームにする
		m_ani_time = 1;
	}
	

	//摩擦
	m_vx += -(m_vx * 0.098);

	//自由落下運動
	m_vy += 9.8 / (16.0f);

	//ブロックとの当たり判定実行
	CObjStageBlock* pb = (CObjStageBlock*)Objs::GetObj(OBJ_STAGE_BLOCK);
	pb->BlockHit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

////棘が主人公に接触したら主人公のHPを減らす
//	if (hit->CheckObjNameHit(OBJ_TOGE) != nullptr)
//	{
//		m_hp -= 2;
//	}

	
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
	
	int AniData[4] = { 1,0,2,0 };

	////描画カラー情報
	//float  c[4] = { 1,0,2,0};
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	
	
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 320.0f;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = 32.0f;


	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 64.0;
	dst.m_bottom = 64.0;

	//描画
	Draw::Draw(1, &src, &dst, c, 1.0f);



	////表示位置の設定
	//dst.m_top = 0.0f + m_py;
	//dst.m_left = (64 * m_posture) + m_px;
	//dst.m_right = (64 + 12.0f * m_posture) + m_py;
	//dst.m_bottom = 64-0.1f + m_px;
	
	//dst.m_bottom = 64-0.1f + m_px;
	//dst.m_bottom = 64-0.1f + m_px;
	//dst.m_left = (64.0f * m_posture);64.0f +m_px;
	//dst.m_right = (64 + 64.0f * m_posture); 64.0f + m_px;
	//dst.m_bottom = 64-0.1f + m_py;
	//dst.m_left =( 64.0f*m_posture)+ m_px;
	//dst.m_right = (64-64.0f*m_posture)+64.0f+m_px;
	//dst.m_bottom = 64-0.1f + m_py;
	//dst.m_bottom = 64-0.1f + m_py;
	//dst.m_left =(     64.0f*m_posture)+ m_px;
	//dst.m_right = (64-64.0f*m_posture)+64.0f+m_px;
	//dst.m_bottom = 64-0.1f + m_py;
	//dst.m_bottom = 64-0.1f + m_py;
	//dst.m_left =/*(     64.0f*m_posture) */+ m_px;
	//dst.m_right = /*(64-64.0f*m_posture)*/64.0f+m_px;
	//dst.m_bottom = 64-0.1f + m_py;
	///*dst.m_left =(     64.0f*m_posture) + m_px;
	//dst.m_right = (64-64.0f*m_posture)+64.0f+m_px;*/
	//dst.m_left =(     64.0f*m_posture) + m_px;
	///*dst.m_right = (64 - 64.0f*m_posture)+m_px;*/
	///*dst.m_left =(     64.0f*m_posture)+ 64.0f + m_px;*/
	//dst.m_right = /*(64-64.0f*m_posture)*/64.0f+m_px;
	//dst.m_left =/*(     64.0f*m_posture)*/ + m_px;
	//dst.m_right = (64.0f*m_posture)+m_px;
	//dst.m_bottom = 64.0f + m_py;
	//dst.m_right = (64 - 64.0f * m_posture) + m_px;
	//dst.m_bottom = 64.0f + m_py;
	////dst.m_left =0.0f + m_px;
	//dst.m_right =64.0f+m_px;
	////dst.m_bottom = 64.0f + m_py;*/


	////描画
	//Draw::Draw(1, &src, &dst, c, 0.0f);
	//Draw::Draw(1, &src, &dst, c, 1.0f);
	//Draw::Draw(2, &src, &dst, c, 0.0f);
	////Draw::Draw(0, &src, &dst, c, 0.0f);
	////Draw::Draw(0, &src, &dst, c, 1.0f);
}