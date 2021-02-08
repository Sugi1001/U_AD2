//使用するヘッダーファイル
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"

#include"GameHead.h"
#include"ObjGameSousa.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameSousa::Init()
{
	//キーフラグ
	m_key_flag = false;
}

//アクション
void CObjGameSousa::Action()
{
	//エンターキーを押してシーン：ゲームTitleに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain1());
			//Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}

	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjGameSousa::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"→キー　前に進む", 150, 150, 60, c);
	Font::StrDraw(L"←キー　後ろに進む", 150, 250, 60, c);
	Font::StrDraw(L"Xキー　ジャンプ", 150, 350, 60, c);

	Font::StrDraw(L"焦らず丁寧に進むといいですよ（経験談）", 35, 460, 40, c);
	Font::StrDraw(L"エンターキーでゲームスタート", 150, 510, 40, c);
}