//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include"GameL/DrawFont.h"
#include"GameL/UserData.h"
#include "ObjStageBlock.h"


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
	//p = Save::ExternalDataOpen(L"test.csv", &size);//外部データ読み込み
	p = Save::ExternalDataOpen(L"Stage500.csv", &size);//外部データ読み込み

	//int map[10][150];
	//int count = 1;
	//for (int i = 0; i < 10; i++)
	int map[10][500];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{
		//for (int j = 0; j < 150; j++)
		for (int j = 0; j < 500; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}
	//外部データの読み込み（ステージ情報2）
	/*unique_ptr<wchar_t>a;//ステージ情報ポインター
	int size1;//ステージ情報の大きさ
	//p = Save::ExternalDataOpen(L"test.csv", &size);//外部データ読み込み
	a = Save::ExternalDataOpen(L"Stage3.csv", &size1);//外部データ読み込み

	//int map[10][150];
	//int count = 1;
	//for (int i = 0; i < 10; i++)
	int map2[10][106];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 106; j++)
		{
			int w = 0;
			swscanf_s(&a.get()[count], L"%d", &w);

			map2[i][j] = w;
			count += 2;
		}
	}

	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t>b;//ステージ情報ポインター
	int size2;//ステージ情報の大きさ
	//p = Save::ExternalDataOpen(L"test.csv", &size);//外部データ読み込み
	b = Save::ExternalDataOpen(L"Stage1.csv", &size2);//外部データ読み込み

	//int map[10][150];
	//int count = 1;
	//for (int i = 0; i < 10; i++)
	int map3[10][106];
	for (int i = 0; i < 10; i++)
	{
		//for (int j = 0; j < 150; j++)
		for (int j = 0; j < 106; j++)
		{
			int w = 0;
			swscanf_s(&b.get()[count], L"%d", &w);

			map3[i][j] = w;
			count += 2;
		}
	}*/

	////グラフィック読み込み
	Draw::LoadImage(L"背景.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"taitle.png", 10, TEX_SIZE_512);

	//Draw::LoadImage(L"主人公.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"主人公（移動　逆）.png", 1, TEX_SIZE_512);
	  //Draw::LoadImage(L"主人公（移動 逆) .png", 1, TEX_SIZE_512);
   //Draw::LoadImage(L"主人公.png", 1, TEX_SIZE_512);

	//Draw::LoadImage(L"主人公（移動　逆）.png", 1, TEX_SIZE_512);
	//Draw::LoadImage(L"主人公（移動　逆）.png", 2, TEX_SIZE_512);

	//Draw::LoadImage(L"地面.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"地面.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"地面（中）(1).png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"毒.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"毒ノーマル.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"こうもり.png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"こうもり（移動）.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"とげ1.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"岩2.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"宝箱（重要アイテム）.png", 50, TEX_SIZE_512);
	//Draw::LoadImage(L"地面.png", 2, TEX_SIZE_512);
	//Draw::LoadImage(L"地面.png", 0, TEX_SIZE_512);


	


	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//blockオブジェクト作成
	CObjStageBlock* objb = new CObjStageBlock(map);
	Objs::InsertObj(objb, OBJ_STAGE_BLOCK, 2);

	//棘オブジェクト作成
	CObjToge* objt = new CObjToge(); //棘オブジェクト作成
	Objs::InsertObj(objt, OBJ_TOGE, 8);

	//岩2オブジェクト作成
	CObjEnemyBlock* objeb = new CObjEnemyBlock();
	Objs::InsertObj(objeb, OBJ_ENEMY_BLOCK, 17);

	//こうもりオブジェクト作成
	//CObjEnemy* obj_enemy = new CObjEnemy();
	//Objs::InsertObj(obj_enemy, OBJ_ENEMY, 6);

	
	//タイトル背景オブジェクト作成
	//CObjTitle* back = new CObjTitle();
	//Objs::InsertObj(back, OBJ_TITLE, 10);
   
}

//実行中メソッド
void CSceneMain::Scene()
{

}