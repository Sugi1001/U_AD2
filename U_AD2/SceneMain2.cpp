//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include"GameL/DrawFont.h"
#include"GameL/UserData.h"
#include "ObjFinalStage.h"
#include"GameL/Audio.h"
#include"ObjTime.h"


//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain2.h"
#include "GameHead.h"

//コンストラクタ
CSceneMain2::CSceneMain2()
{

}

//デストラクタ
CSceneMain2::~CSceneMain2()
{

}

//初期化メソッド
void CSceneMain2::InitScene()
{
	//音楽情報の読み込み
	Audio::LoadAudio(4, L"BGM Stage.wav", SOUND_TYPE::BACK_MUSIC);
	float v = Audio::VolumeMaster(0.5);
	Audio::Start(4); //音楽スタート

	//Font作成
	//Font::SetStrTex(L"0123456789分秒");
	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t>p;//ステージ情報ポインター
	int size;//ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"Finalstage.csv", &size);//外部データ読み込み

	//int map[10][150];
	//int count = 1;
	//for (int i = 0; i < 10; i++)
	int map[10][13];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{
		//for (int j = 0; j < 150; j++)
		for (int j = 0; j < 13; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}


	//グラフィック読み込み
	Draw::LoadImage(L"背景１.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"タイトル.png", 10, TEX_SIZE_512);
	Draw::LoadImage(L"ローラースケート.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"レンガ.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"地面（中）(1).png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"棘.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"岩2.png", 9, TEX_SIZE_512);
	Draw::LoadImage(L"闇金.png", 29, TEX_SIZE_512);
	Draw::LoadImage(L"弾丸.png", 28, TEX_SIZE_512);
	Draw::LoadImage(L"ビル入口.png", 30, TEX_SIZE_512);
	Draw::LoadImage(L"ビル.png", 31, TEX_SIZE_512);



	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//blockオブジェクト作成
	CObjFinalStage* objb = new CObjFinalStage(map);
	Objs::InsertObj(objb, OBJ_STAGE_BLOCK, 2);

	//棘オブジェクト作成
	CObjToge* objt = new CObjToge(); //棘オブジェクト作成
	Objs::InsertObj(objt, OBJ_TOGE, 8);

	//岩2オブジェクト作成
	CObjEnemyBlock* objeb = new CObjEnemyBlock();
	Objs::InsertObj(objeb, OBJ_ENEMY_BLOCK, 12);

	

	//タイムオブジェクト作成
	CObjTime* objti = new CObjTime();
	Objs::InsertObj(objti, OBJ_TIME, 11);

	
}

//実行中メソッド
void CSceneMain2::Scene()
{

}