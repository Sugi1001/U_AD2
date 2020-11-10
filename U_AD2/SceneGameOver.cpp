//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用するヘッダー
#include "SceneGameOver.h"
#include "GameHead.h"

//コントラクタ
CSceneGameOver::CSceneGameOver()
{

}

//デストラクタ
CSceneGameOver::~CSceneGameOver()
{

}

//初期化メソッド
void CSceneGameOver::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"GameOver");
	Font::SetStrTex(L"がんばれ");
	Font::SetStrTex(L"NEXT_CHALLENGE:ENTER_KEY");

	//ゲームオーバーオブジェクト作成
	CObjGameOver*obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 11);
}

//実行中メソッド
void CSceneGameOver::Scene()
{

}