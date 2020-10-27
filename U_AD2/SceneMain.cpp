//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include"GameL/DrawFont.h"
#include"GameL/UserData.h"


//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{
	
}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//初期化メソッド
void CSceneMain::InitScene()
{
	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t>p;//ステージ情報ポインター
	int size;//ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"stage.csv", &size);//外部データ読み込み

	int map[50][50];
	int count = 2;
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j > 50; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}


	////グラフィック読み込み
	Draw::LoadImage(L"背景.png", 0, TEX_SIZE_512);

	////Draw::LoadImage(L"主人公.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"主人公.png", 2, TEX_SIZE_512);

	//Draw::LoadImage(L"主人公（移動　逆）.png", 1, TEX_SIZE_512);
	//Draw::LoadImage(L"主人公（移動　逆）.png", 2, TEX_SIZE_512);

	//Draw::LoadImage(L"地面.png", 2, TEX_SIZE_512);
	////Draw::LoadImage(L"地面.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"地面.png", 1, TEX_SIZE_512);
	//Draw::LoadImage(L"地面.png", 0, TEX_SIZE_512);


	


	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_STAGE_BLOCK, 2);

   

}

//実行中メソッド
void CSceneMain::Scene()
{

}