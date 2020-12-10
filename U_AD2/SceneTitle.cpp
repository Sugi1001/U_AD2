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
	Font::SetStrTex(L"エンタキー押してくださいお願いします(*-*)");

	//音楽情報の読み込み
	/*Audio::LoadAudio(3, L"BGM Gametitle.wav", SOUND_TYPE::BACK_MUSIC);

	//バックミュージックスタート
	float Volume = Audio::VolumeMaster(-0.8f); //マスターボリュームを0.8下げる
	Audio::Start(0); //音楽スタート*/

	CObjTitle*obj = new CObjTitle();//画像でんし
	Objs::InsertObj(obj, OBJ_TITLE, 1);

	//タイトル作成
	CObjTitle* objeo = new CObjTitle();
	Objs::InsertObj(objeo, OBJ_TITLE, 10);

}

//ゲームメイン実行メソッド
void CSceneTitle::Scene()
{

}

