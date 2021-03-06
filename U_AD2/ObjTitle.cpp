#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include "GameL\DrawTexture.h"


#include"GameHead.h"
#include"ObjTitle.h"

//使用するネームペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	m_key_flag = false;
}

//アクション
void CObjTitle::Action()
{
	//エンターキーを押してシーン：ゲームメインに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			//Scene::SetScene(new CSceneMain1());
			Scene::SetScene(new CSceneGameSousa());
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjTitle::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);


	//タイトル文
	Font::StrDraw(L"アンダーアドベンチャー", 17, 150, 70, c);
	
	//あらすじ文
	Font::StrDraw(L"あらすじ", 325, 300, 32, c);
	Font::StrDraw(L"主人公のもとに闇金が!?", 215, 345, 32, c);
	Font::StrDraw(L"借りた金の返済のために洞窟へ!!", 150, 390, 32, c);

	//誘導文
	Font::StrDraw(L"エンタキー押したら操作説明なのじゃ!!(*-*)", 28, 465, 35, c);

	//小ネタ文
	Font::StrDraw(L"なに？主人公がなかなか家から出ない?", 250, 510, 15, c);
	Font::StrDraw(L"構わん　今すぐ連れてけやーー!", 275, 528, 15, c);

	


}