#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGameOver.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameOver::Init()
{
	m_key_flag = false;
}

//アクション
void CObjGameOver::Action()
{
	//エンターキーを押してシーン：ゲームTitleに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"GameOver　ゲ～ムオ～バ～", 120, 190 , 50, c);
	Font::StrDraw(L"あきらめていいんですか?", 215, 275, 32, c);
	Font::StrDraw(L"タイトルから出直してきてくださいまし", 150, 330, 32, c);
	Font::StrDraw(L"ENTER_KEYでタイトルに戻るよ", 100, 400, 50, c);
}