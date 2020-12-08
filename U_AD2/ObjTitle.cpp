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

	
	Font::StrDraw(L"アンダーアドベンチャー", 17, 150, 70, c);
	Font::StrDraw(L"エンタキー押したらスタートなのじゃ！！(*-*)", 28, 485, 35, c);

	Font::StrDraw(L"あらすじなのじゃ～", 270, 300, 32, c);
	Font::StrDraw(L"主人公のもとに闇金が！！", 220, 350, 32, c);
	Font::StrDraw(L"借りた金の返済のために洞窟へ！！", 200, 390, 32, c);

	Font::StrDraw(L"なに？主人公がなかなか家から出ない？", 310, 540, 15, c);
	Font::StrDraw(L"構わん　今すぐ拉致ってつれてけ", 330, 558, 15, c);

}