#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン : メイン
class CSceneMain1 :public CScene
{
public:
	CSceneMain1();
	~CSceneMain1();
	void InitScene(); //初期化メソッド
	void Scene();    //実行中メソッド
private:
};
