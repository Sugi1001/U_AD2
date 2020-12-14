//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/HitBoxManager.h"

#include"GameHead.h"
#include"yamikin.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjyamikin::CObjyamikin(float x, float y)
{

	m_y = y;
}


//イニシャライズ
void CObjyamikin::Init()
{
	m_hp = 45;
	m_time = 0;
	m_r = 0.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;

	//当たり判定用HitBox作成
	//Hits::SetHitBox(this, m_y + 50, 250, 200, ELEMENT_YAMIKIN, OBJ_ENEMY, 1);
}

//アクション
void CObjyamikin::Action()
{

	m_time++;
	//通常弾発射
	if (m_time % 50 == 0)
	{
		
	}
	//m_timeの初期化
	if (m_time > 1000)
	{
		m_time = 0;
	}

	//角度加算
	m_r += 2.0f;

	//360度　で初期値に戻す
	if (m_r > 360.0f)
		m_r = 0.0f;

	//移動方向
	m_vy = sin(3.14 / 180 * m_r);//sinθを求めてm_xyにいれる

	//速度を付け
	m_vy *= 1.5f;



	//移動ベクトルを座標に加算する
	m_y += m_vy;



	//ベクトルの長さを求める（三平方の定理）
	float  r = 0.0f;
	r = m_vx * +m_vy * m_vy;
	r = sqrt(r);//rをルートを求める
	//長さが０かどうか求める
	if (r == 0.0f)
	{
		;//０なら何もしない
	}
	else
	{
		//正規化を行う
		m_vy = 1.0f / r * m_vy;
	}




	//敵機が完全に領域外に出たら敵機を破棄する
	if (m_y < -32.0f)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//敵機弾丸が所有するHitBoxに削除する
	}

	//弾丸と接触するとHPが減る
	/*if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
	}*/

	//HPが０になると破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		Scene::SetScene(new CSceneClear());
	}



}

//ドロー
void CObjyamikin::Draw()
{
	//描画カラー情報　R=RED　G=GREEN　B=BLUE　A=ALPHA（透過情報）
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_right = 0.0f;
	src.m_left = 64.0f;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_right = 0.0f;
	dst.m_left = 64.0f;
	dst.m_bottom = 64.0f + m_y;

	//1番目に登録したグラフィックをsrc,dst,cの情報の元に描画
	Draw::Draw(1, &src, &dst, c, 0.0f);
}