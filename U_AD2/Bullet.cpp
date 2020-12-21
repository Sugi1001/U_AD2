//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/HitBoxManager.h"
#include"GameL/Audio.h"
#include"GameHead.h"
#include"Bullet.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjBullet::CObjBullet(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjBullet::Init()
{
	m_eff.m_top = 5;
	m_eff.m_left = 0;
	m_eff.m_right = 10;
	m_eff.m_bottom = 0;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;
	m_vx = 0.0f;

	m_vx = 1.0f;

	//当たり判定用hitbox作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_BULLET, 1);
}

//アクション
void CObjBullet::Action()
{
	//Resourcesの描画物のRECT
	m_eff = GetBulletEffec(&m_ani, &m_ani_time, m_del, 2);

	//弾丸消滅処理--------
	if (m_del == true)
	{


		//着弾アニメーション終了で本当にオブジェクトの破棄
		if (m_ani == 4)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}


		return;//終了処理は、ここでアクションメソッドを終了させる

	}

	//弾丸実行処理------

	//移動
	m_vx += 1.0f;
	m_x += m_vx;


	//m_x += 2.0f;
	//m_x += m_vx;

	//弾丸のHitBox更新用ポインター取得
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);               //hitboxの位置を弾丸の位置に更新

	//敵機拡散弾丸が完全に領域外に出たら敵機拡散弾丸を破棄する
	//bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	/*if (check == false)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		return;
	}*/
	//領域外にでたら弾丸を破棄する
	if (m_x > 800.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);//敵機弾丸が所有するHitBoxに削除する
	}

	//当たり判定を行うオブジェクト情報部
	int data_base[1] =
	{
		OBJ_HERO,
	};
	//オブジェクト情報部と当たり判定を行い、当たっていれば削除
	for (int i = 0; i < 1; i++)
	{
		if (hit->CheckObjNameHit(data_base[i]) != nullptr)
		{
	//着弾音を鳴らす
Audio::Start(3);

			m_del = true;                //消滅実行
		hit->SetInvincibility(true); //当たり判定無効
		}
	}

	//敵機オブジェクトと接触したら弾丸削除
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{		m_del = true;               //消滅実行
		hit->SetInvincibility(true);//当たり判定無効
	}
}

//ドロー
void CObjBullet::Draw()
{

	//描画カラー情報　R=RED　G=GREEN　B=BLUE　A=ALPHA（透過情報）
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F dst;//描画先表示位置
	RECT_F src; //描画元切り取り位置
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 10.0f;
	src.m_bottom = 5.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//０番目に登録したグラフィックをsrc,dst,cの情報の元に描画
	Draw::Draw(28, &src, &dst, c, 1.0f);
}