#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"


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
			Scene::SetScene(new CSceneMain());
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

	
	Font::StrDraw(L"アンダーアドベンチャー", 230, 250, 32, c);
	Font::StrDraw(L"エンタキー押してくださいお願いします(*-*)", 100, 300, 32, c);

	Font::StrDraw(L"あらすじ", 290, 350, 32, c);
	Font::StrDraw(L"主人公のもとに闇金が！！", 200, 390, 32, c);
	Font::StrDraw(L"借りた金の返済のために洞窟へ！！", 200, 420, 32, c);
}