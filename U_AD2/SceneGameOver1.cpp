//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include"GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//使用するヘッダー
#include "SceneGameOver1.h"
#include "GameHead.h"

//コントラクタ
CSceneGameOver1::CSceneGameOver1()
{

}

//デストラクタ
CSceneGameOver1::~CSceneGameOver1()
{

}

//初期化メソッド
void CSceneGameOver1::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"GameOver　ゲ～ムオ～バ～");

	Font::SetStrTex(L"諦めるな！");
	Font::SetStrTex(L"諦めなければきっとゴールは見えてくる");
	Font::SetStrTex(L"何度でもチャレンジするんだ!");

	Font::SetStrTex(L"ENTER_KEYでタイトルに戻るよ");

	Font::SetStrTex(L"何度もクリアできない場合は落ち着くために休憩をはさみましょう");
	Font::SetStrTex(L"体調面などもきちんと考えてプレイを続けましょう");



	//音楽情報の読み込み
	Audio::LoadAudio(2, L"BGM Gameover.wav", BACK_MUSIC);

	float v = Audio::VolumeMaster(2);
	v = Audio::VolumeMaster((0.4 - v));
	Audio::Start(2); //音楽スタート

	//ゲームオーバーオブジェクト作成
	CObjGameOver1* obj = new CObjGameOver1();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 11);
}

//実行中メソッド
void CSceneGameOver1::Scene()
{

}