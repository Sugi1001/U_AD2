//使用するヘッダーファイル
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"ObjStageClea1.h"
#include"GameHead.h"
//#include"ObjGameClear.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjClear1::Init()
{
	//キーフラグka
	m_key_flag = false;
}

//アクション
void CObjClear1::Action()
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
void CObjClear1::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"クリアおめでとう！！", 150, 105, 60, c);

	Font::StrDraw(L"これで主人公の借金も無事に返済できるだろう", 140, 210, 30, c);

	Font::StrDraw(L"ただし、借金が増えないとも言ってないがね", 150, 265, 30, c);

	Font::StrDraw(L"主人公のぐ～たら生活は続いていけるのだろうか!!", 85, 315, 30, c);

	Font::StrDraw(L"最後にプレイしていただきありがとうございました", 18, 400, 34, c);
}