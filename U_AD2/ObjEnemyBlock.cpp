//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include  "ObjEnemyBlock.h"

//使用するヘッダーファイル
using namespace GameL;

//イニシャライズ
void CObjEnemyBlock::Init()
{
	
	


}
//アクション
void CObjEnemyBlock::Action()
{

	//摩擦
	m_vx += -(m_vx * 0.098);

	//自由落下運動
	m_vy += 9.8 / (16.0f);


}

//ドロー(CObjEnemy Blockのドロー)
void CObjEnemyBlock::Draw()
{
	//描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報)
	//float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//RECT_F src; //描画先切り取り位置
	//RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	//src.m_top = 0.0f;
	//src.m_left = 0.0f;
	//src.m_right = src.m_left + 50.0f;
	//src.m_bottom = src.m_top + 50.0f;


	//表示位置の設定
	//dst.m_top = 0.0f + m_py;
	//dst.m_left = (30.0f * m_posture) + m_px;
	//dst.m_right = (50 - 50.0f * m_posture) + m_px;
	//dst.m_bottom = 64.0 + m_py;


	//表示位置の設定
	//dst.m_top = 0.0f + m_py;
	//dst.m_left = (30.0f * m_posture) + m_px;
	//dst.m_right = (50 - 50.0f * m_posture) + m_px;
	//dst.m_bottom = 64.0 + m_py;


	//0番目に登録したグラフィックをsrc.dst.cの情報をもとに描画
	//Draw::Draw(9, &src, &dst, c, 0.0f);
}