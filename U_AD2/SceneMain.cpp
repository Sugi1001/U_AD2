//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"

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
	//グラフィック読み込み
	Draw::LoadImageW(L"背景.png",0,TEX_SIZE_512);
	//外部データの読み込み(ステージ情報)
	unique_ptr<wcha_t>_tp; //ステージ情報ポインター
	int size;   //ステージ情報の大きさ
	p = save::ExternalDataOpen(L"", &size); //外部データ読み込み

	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 9);
}

//実行中メソッド
void CSceneMain::Scene()
{

}