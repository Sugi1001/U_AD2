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
  
	//マップ情報
	////当たり判定用のHitBoxの作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_TOGE, 4);
	
	

}

//アクション
void CObjToge::Action()
{
	//zz主人公の位置を取得
	/*CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();*/

	//HitBoxの内容を更新
	CHitBox* Hit = Hits::GetHitBox(this);
	Hit->SetPos(m_x, m_y);


	////HitBoxの位置の変更
	/*HitBox* hit = Hits::GetHitBox(this);
    Hit->SetPos(m_px, m_py);*/

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//棘と接触したら主人公のHPを減らす


}

//ドロー
void CObjToge::Draw()
{
	float  c[4] = { 1.0f , 1.0f ,1.0f ,1.0f };

	RECT_F src; //描画元切り取り位置
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

	//3番目に登録したグラフィックをsrc.dst.cの情報を元に描画
	Draw::Draw(4, &src, &dst, c, 0.0f);


}

