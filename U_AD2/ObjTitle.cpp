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

	
	Font::StrDraw(L"アンダーアドベンチャー", 150, 200, 50, c);
	Font::StrDraw(L"エンタキー押してくださいお願いします(*-*)", 120, 270, 30, c);

	Font::StrDraw(L"あらすじなのじゃ～", 270, 400, 32, c);
	Font::StrDraw(L"主人公のもとに闇金が！！", 220, 450, 32, c);
	Font::StrDraw(L"借りた金の返済のために洞窟へ！！", 200, 490, 32, c);

	Font::StrDraw(L"なに？主人公がなかなか家から出ない？", 310, 530, 15, c);
	Font::StrDraw(L"構わん　今すぐ拉致ってつれてけ", 330, 542, 15, c);
}