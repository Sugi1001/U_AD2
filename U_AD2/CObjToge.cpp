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
	m_px = 100.0f;
	m_py = 0.0f;
	m_x;
	m_y;
	
	m_posture = 1.0f;

	m_ani_time = 0;
	m_ani_frame = 1;
	

	
	//マップ情報
	////当たり判定用のHitBoxの作成
	//Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_TOGE, 4);
	
	

}

//アクション
void CObjToge::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx;
	float hp;

	//オブジェクトと主人公の当たり判定
	
	//ブロックタイプ検知用の変数がないためダミー
	int d;


	
	
	//ブロックとの当たり判定実行
	CObjStageBlock* pb = (CObjStageBlock*)Objs::GetObj(OBJ_STAGE_BLOCK);
	pb->BlockHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d
	);
	/*CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();*/

	//棘と接触したら主人公のHPを減らす

	//HitBoxの内容を更新

	
}

//ドロー
void CObjToge::Draw()
{
	int AniData[4] =
	{
		1, 0 ,2 , 0,
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

	
	//ブロック情報を持ってくる
	CObjStageBlock* block = (CObjStageBlock*)Objs::GetObj(OBJ_STAGE_BLOCK);
	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f * m_posture) + m_px;
	dst.m_right = (64 - 64.0f * m_posture) + m_px;
	dst.m_bottom = 64.0f + m_py;

	//3番目に登録したグラフィックをsrc.dst.cの情報を元に描画
	//Draw::Draw(8, &src, &dst, c, 0.0f);





}

