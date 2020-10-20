//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameL\SceneManager.h"
#include "Objhero.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHero::Init()
{
	m_px = 0.0f; //位置
	m_py = 0.0f;
	m_vx = 0.0f;//移動ベクトル
	m_vy = 0.0f;
}

//アクション
void CObjHero::Action()
{
	//移動ベクトル
	m_vx = 0.0f;
	m_vy = 0.0f;

	//キーの入力方向
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx = -1.0f;
	}

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;
}

//ドロー
void CObjHero::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left - 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_top = 0.0f;
	dst.m_top = 0.0f;
	dst.m_bottom = 64.0f;

	//描画
	Draw::Draw(0.&src, &dst, c, 0.0f);
}