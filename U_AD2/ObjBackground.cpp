//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"GameL\SceneManager.h"
#include"ObjTitle.h"
#include"ObjBackground.h"

//使用してる加茂野のネームスペース
using namespace GameL;

//イニシャライズ
void CObjBackground::Init()
{

}

//アクション
void CObjBackground::Action()
{

}

//ドロー
void CObjBackground::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top    = 264.0f;
	src.m_left   = 0.0f;
	src.m_right  = 512.0f;
	src.m_bottom = 448.0f;
		
	dst.m_top    = 0.0f;
	dst.m_left   = 0.0f;
	dst.m_right  = 80.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(10, &src, &dst, c, 0.0f);
}