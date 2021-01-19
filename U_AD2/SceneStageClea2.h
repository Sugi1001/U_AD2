#pragma once
//使用するヘッダーファイル
#include"GameL/SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：クリア
class CSceneClear2 :public CScene
{
public:
	CSceneClear2();
	~CSceneClear2();
	void InitScene();
	void Scene();
};

