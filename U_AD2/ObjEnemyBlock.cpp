//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include  "ObjEnemyBlock.h"
#include "Objtyukan.h"

//使用するヘッダーファイル
using namespace GameL;

//イニシャライズ
void CObjEnemyBlock::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_px = 400.0f;
	m_py = 64.0f;
	
	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;



}
//アクション
void CObjEnemyBlock::Action()
{
	//岩の位置を取得
	CObjEnemyBlock* enemyblock = (CObjEnemyBlock*)Objs::GetObj(OBJ_ENEMY_BLOCK);
	float hx = enemyblock->GetX();
	float hy = enemyblock->GetY();

	//m_mapの全要素にアクセス
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (m_map[i][j] > 0)
			{
				//要素番号を座標に変更
				float x = j * 64.0f;
				float y = i * 64.0f;
			}
		}
	}

	//岩の位置X（ｍ＿ｘ）+主人公機の幅分がX軸方向に領域外を認識
	if (m_px + 20.0f > 800.0f)
	{
		m_px = 50.0f - 50.0f;
	}

	//移動ベクトルの初期化
	m_vx = 0.0f;
	m_vy = 2.0f;

	//ポインタを取る
	//CObjEnemyBlock* obj = (CObjEnemyBlock)Objs::GetObj(OBJ_ENEMY_BLOCK)
	
	//摩擦
	m_vx += -(m_vx * 0.098);

	//自由落下運動
	m_vy += 9.8 / (16.0f);

	//移動していない状態で64pixel単位に誤差がある場合
	int w = ((int)m_px) % 64;
	if (w != 0)
	{

		//自動的に入力されていた方向に移動に移動
		if (m_vx > 0)
		{
			//誤差を0に近づけるように移動
			m_vx = (64 - w) / 5.0f;
		}
		if (m_vx < 0)
		{
			//誤差を0に近づけるように移動
			m_vx = (OBJ_ENEMY_BLOCK - w) / OBJ_STAGE_BLOCK;
		}
		else
		{
			//誤差無しなら移動無し
			m_vx = w / OBJ_STAGE_BLOCK;
		}
	}

	//移動止まったら、動かないフラグを立てる
	if (m_vy == OBJ_ENEMY_BLOCK && abs(m_vx) <= OBJ_ENEMY_BLOCK)
	{
		m_stop_flag = false;
		//obj->SetMap(m_stop_map_x, m_stop_map_y, 99);
	}

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
	src.m_left = 0.0f;
	src.m_right = src.m_left + 50.0f;
	src.m_bottom = src.m_top + 50.0f;


	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (30.0f * m_posture) + m_px;
	dst.m_right = (50 - 50.0f * m_posture) + m_px;
	dst.m_bottom = 64.0 + m_py;


	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (30.0f * m_posture) + m_px;
	dst.m_right = (50 - 50.0f * m_posture) + m_px;
	dst.m_bottom = 64.0 + m_py;


	//0番目に登録したグラフィックをsrc.dst.cの情報をもとに描画
	Draw::Draw(9, &src, &dst, c, 0.0f);
}