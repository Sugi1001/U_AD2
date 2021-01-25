//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include  "GameL\WinInputs.h"
#include  "GameL\SceneManager.h"
#include  "GameL\HitBoxManager.h"

#include "GameHead.h"
#include  "CObjToge.h"
#include  "ObjHero.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjToge::Init()
{
	m_px = 1.0f; //位置
	m_py = 1.0f;
	m_vx = 10.0f;//移動ベクトル
	m_vy = 10.0f;
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


}

//アクション
void CObjToge::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx;
	float hp;

	
	
	//ブロックタイプ検知用の変数がないためダミー
	int d;


	
	
	

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//自由落下運動
	m_vy += 1.8 / (16.0f);

	//摩擦
	m_vx += -(m_vx * 0.098);
}

//ドロー
void CObjToge::Draw()
{
	int AniData[4] =
	{
		1, 2 ,2 , 0,
	};

	//描画カラー情報
	float c[4] = { 1.0f , 1.0f , 1.0f , 1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top =64.0f;
	src.m_left =0.0f + AniData[m_ani_frame]*64;
	src.m_right =64.0f + AniData[m_ani_frame]*64;
	src.m_bottom = src.m_top+64.0f;

	
	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (100.0f * m_posture) + m_px;
	dst.m_right = (100 + 100.0f * m_posture) + m_px;
	dst.m_bottom = 100.0f + m_py;

	//3番目に登録したグラフィックをsrc.dst.cの情報を元に描画
	Draw::Draw(1, &src, &dst, c, 0.0f);

}

