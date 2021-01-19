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
#include"SceneStageClea1.h"
#include"GameHead.h"

//コンストラクタ
CSceneClear1::CSceneClear1()
{

}

//デストラクタ
CSceneClear1::~CSceneClear1()
{

}

//初期化メソッド
void CSceneClear1::InitScene()
{
	Font::SetStrTex(L"次の階層へ！！");
	Font::SetStrTex(L"次は難しくなるけれど焦らず行こう");


	//音楽情報の読み取り
	Audio::LoadAudio(1, L"BGM Gameclear.wav", BACK_MUSIC);

	//バックミュージックスタート
	float v = Audio::VolumeMaster(1);
	v = Audio::VolumeMaster(1.0 - v);
	Audio::Start(1); //音楽スタート

	//クリアオブジェクト作成
	CObjClear1* obj = new CObjClear1();
	Objs::InsertObj(obj, OBJ_CLEAR, 1);
}

//実行中メソッド
void CSceneClear1::Scene()
{

}