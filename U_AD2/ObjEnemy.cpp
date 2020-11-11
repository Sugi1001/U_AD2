//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/HitBoxManager.h"

#include"GameHead.h"
#include"ObjEnemy.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjEnemy::CObjEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}


//イニシャライズ
void CObjEnemy::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_ENEMY, 1);
}

//アクション
void CObjEnemy::Action()
{
	//移動方向
	m_vx = -1.0f;
	m_vy = 0.0f;

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
		m_vx = 1.0f / r * m_vx;
		m_vy = 1.0f / r * m_vy;
	}
	//速度を付ける
	m_vx *= 1.5f;
	m_vy *= 1.5f;

	//移動ベクトルの正規化
	//UnitVec(&m_vy, &m_vx);

	//移動ベクトルを座標に加算する
	m_x += m_vx;
	m_y += m_vy;

	//HitBoxの内容更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);



	//敵が完全に領域外に出たら敵を破棄する
	/*bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		return;
	}*/

	//完全に領域外に出たら敵を破棄する
	if (m_x < -32.0f)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//敵が所有するHitBoxに削除する
	}
	
}

//ドロー
void CObjEnemy::Draw()
{
	//描画カラー情報　R=RED　G=GREEN　B=BLUE　A=ALPHA（透過情報）
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_right = 64.0f;
	src.m_left = 64.0f;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_right = 64.0f + m_x;
	dst.m_left = 0.0f + m_x;
	dst.m_bottom = 64.0f + m_y;

	//０番目に登録したグラフィックをsrc,dst,cの情報の元に描画
	Draw::Draw(6, &src, &dst, c, 0.0f);
}