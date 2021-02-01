//使用するヘッダーファイル
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"

#include"GameHead.h"
#include"ObjGameClear1.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjClear3::Init()
{
	//キーフラグ
	m_key_flag = false;
}

//アクション
void CObjClear3::Action()
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
void CObjClear3::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"次の階層へ！！", 150, 125, 60, c);

	Font::StrDraw(L"次はもっと難しくなるけれど焦らず行こう", 90, 305, 30, c);

	Font::StrDraw(L"豆知識だお", 80, 405, 30, c);
	Font::StrDraw(L"日本で一番大きい洞窟は安家洞(あっかどう)だよ", 80, 455, 30, c);
	Font::StrDraw(L"岩手県にあって総延長約23,702mだよ", 80, 505, 30, c);
}