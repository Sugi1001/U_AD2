#pragma once

//使用するヘッダーファイル
#include"GameL/SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：クリア
class CSceneGameSousa :public CScene
{
public:
	CSceneGameSousa();
	~CSceneGameSousa();
	void InitScene();
	void Scene();
};
