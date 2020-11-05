//ＳＬＴデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GeamLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"

//使用するヘッダー
#include"SceneMain.h"
#include"GameHead.h"

//コントラクタ
CSceneTitle::CSceneTitle()
{

}

//デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//ゲームメイン初期化メイン
void CSceneTitle::InitScene()
{
	//出力させるグラフィックをサクセイ
	Font::SetStrTex(L"アンダーアドベンチャー");

	CObjTitle*obj = new CObjTitle();
	Objs::InsertObj(obj, OBJ_TITLE, 1);
}

//ゲームメイン実行メソッド
void CSceneTitle::Scene()
{

}
