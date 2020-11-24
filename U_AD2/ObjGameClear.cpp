//使用するヘッダーファイル
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"

#include"GameHead.h"
#include"ObjGameClear.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjClear::Init()
{
	//キーフラグ
	m_key_flag = false;
}

//アクション
void CObjClear::Action()
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
void CObjClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"クリアおめでとう！！", 160, 105, 60, c);

	Font::StrDraw(L"これで主人公の借金もなくなることだろう", 150, 210, 30, c);

	Font::StrDraw(L"ただし、借金が増えないとも言ってない",150,265,30,c);

	Font::StrDraw(L"主人公のぐ～たら生活は続いていけるのだろうか!!", 85, 315, 30, c);
	
	Font::StrDraw(L"最後にプレイしてくれてありがとうございました", 20, 400, 34, c);
}