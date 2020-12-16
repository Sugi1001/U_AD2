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
	/*Font::SetStrTex(L"クリアおめでとう！！");
	Font::SetStrTex(L"これで主人公の借金も無事に返済できるだろう");
	Font::SetStrTex(L"ただし、借金が増えないとも言ってない");
	Font::SetStrTex(L"主人公のぐ～たら生活は続いていけるのだろうか!!");
	Font::SetStrTex(L"最後に一言いうとしたらプレイしていただきありがとうございました");*/



	//クリアオブジェクト作成
	CObjGameSousa* obj = new CObjGameSousa();
	Objs::InsertObj(obj, OBJ_GAME_SOUSA, 1);
}

//実行中メソッド
void CSceneGameSousa::Scene()
{

}