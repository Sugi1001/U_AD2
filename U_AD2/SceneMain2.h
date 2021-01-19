#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン : メイン
class CSceneMain2 :public CScene
{
public:
	CSceneMain2();
	~CSceneMain2();
	void InitScene(); //初期化メソッド
	void Scene();    //実行中メソッド
private:
};

