#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGameOver1.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameOver1::Init()
{
	m_key_flag = false;
}

//アクション
void CObjGameOver1::Action()
{
	//エンターキーを押してシーン：ゲームTitleに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjGameOver1::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };


	//ゲームオーバー画面(メイン文)
	Font::StrDraw(L"GameOver　ゲ〜ムオ〜バ〜", 120, 110, 50, c);
	Font::StrDraw(L"諦めるな！", 350, 195, 32, c);
	Font::StrDraw(L"諦めなければきっとゴールは見えてくる", 170, 250, 32, c);
	Font::StrDraw(L"何度でもチャレンジするんだ!", 170, 300, 32, c);
	Font::StrDraw(L"ENTER_KEYでタイトルに戻るよ", 90, 400, 50, c);


	//注意書き
	Font::StrDraw(L"何度もクリアできない場合は落ち着くために休憩をはさみましょう", 110, 490, 20, c);
	Font::StrDraw(L"体調面などもきちんと考えてプレイを続けましょう", 165, 530, 20, c);
}