//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL/SceneObjManager.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneGameSousa.h"
#include"GameHead.h"

//コンストラクタ
CSceneGameSousa::CSceneGameSousa()
{

}

//デストラクタ
CSceneGameSousa::~CSceneGameSousa()
{

}

//初期化メソッド
void CSceneGameSousa::InitScene()
{
	Font::SetStrTex(L"→キー　前に進む");
	Font::SetStrTex(L"←キー　後ろに進む");
	Font::SetStrTex(L"Xキー　ジャンプ");

	//クリアオブジェクト作成
	CObjGameSousa* obj = new CObjGameSousa();
	Objs::InsertObj(obj, OBJ_GAME_SOUSA, 1);
}

//実行中メソッド
void CSceneGameSousa::Scene()
{

}