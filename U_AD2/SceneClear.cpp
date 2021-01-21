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
	Font::SetStrTex(L"クリアおめでとう！！");
	Font::SetStrTex(L"これで主人公の借金も無事に返済できるだろう");
	Font::SetStrTex(L"ただし、借金が増えないとも言ってないがね");
	Font::SetStrTex(L"主人公のぐ～たら生活は続いていけるのだろうか!!");
	Font::SetStrTex(L"最後までプレイしていただきありがとうございました");


	//音楽情報の読み取り
	Audio::LoadAudio(1, L"BGM Gameclear.wav", BACK_MUSIC);

	//バックミュージックスタート
	float v = Audio::VolumeMaster(1); 
	v = Audio::VolumeMaster(1.0 - v);
	Audio::Start(1); //音楽スタート

	//クリアオブジェクト作成
	CObjClear* obj = new CObjClear();
	Objs::InsertObj(obj, OBJ_CLEAR, 1);
}

//実行中メソッド
void CSceneClear::Scene()
{

}