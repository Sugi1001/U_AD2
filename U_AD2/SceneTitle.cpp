//ＳＬＴデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GeamLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL/Audio.h"

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
	Font::SetStrTex(L"エンタキー押したらスタートなのじゃ！！(*-*)");

	Font::SetStrTex(L"あらすじなのじゃ！！");
	Font::SetStrTex(L"主人公のもとに闇金が！！");
	Font::SetStrTex(L"借りた金の返済のために洞窟へ！！");


	//音楽情報の読み込み
	Audio::LoadAudio(3, L"BGM Gametitle.wav",BACK_MUSIC);

	//バックミュージックスタート
	float Volume = Audio::VolumeMaster(0.5f); 
	Audio::Start(3); //音楽スタート

	//タイトル作成
	CObjTitle* objeo = new CObjTitle();
	Objs::InsertObj(objeo, OBJ_TITLE, 10);

}

//ゲームメイン実行メソッド
void CSceneTitle::Scene()
{

}

