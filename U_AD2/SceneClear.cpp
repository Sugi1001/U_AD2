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
#include"SceneClear.h"
#include"GameHead.h"

//コンストラクタ
CSceneClear::CSceneClear()
{

}

//デストラクタ
CSceneClear::~CSceneClear()
{

}

//初期化メソッド
void CSceneClear::InitScene()
{
	Font::SetStrTex(L"おめでとう！");

	//音楽情報の読み取り
	//Audio::LoadAudio(0, L"BGMGameClear.wav", BACK_MUSIC);

	//バックミュージックスタート
	//float v = Audio::VolumeMaster(0); //マスターボリュームを0.8下げる
	//v = Audio::VolumeMaster(1.0 - v);
	//Audio::Start(0); //音楽スタート

	//クリアオブジェクト作成
	//ObjGameClear* obj = new ObjGameClear();
	//Objs::InsertObj(obj, OBJ_CLEAR, 10);
}

//実行中メソッド
void CSceneClear::Scene()
{

}