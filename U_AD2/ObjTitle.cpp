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

}

//アクション
void CObjTitle::Action()
{
	//エンターキーを押してシーン：ゲームメインに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneMain());
	}
}

//ドロー
void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"アンダーアドベンチャー", 230, 250, 32, c);

	Font::StrDraw(L"GameStart:PushEnterKey", 200, 400, 32, c);
}