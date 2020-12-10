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
	

}

//ドロー(CObjEnemy Blockのドロー)
void CObjEnemyBlock::Draw()
{
	//描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画先切り取り位置
	RECT_F dst; //描画先表示位置
	
	////切り取り位置の設定
	//src.m_top = 0.0f;
	//src.m_left = 0.0f;
	//src.m_right = 50.0f;
	//src.m_bottom = 50.0f;

	////表示位置の設定
	//dst.m_top = 0.0f;
	//dst.m_left = 50.0f;
	//dst.m_right = 0.0f;
	//dst.m_bottom = 50.0f;



	////0番目に登録したグラフィックをsrc.dst.cの情報をもとに描画
	//Draw::Draw(9, &src, &dst, c, 0.0f);
}