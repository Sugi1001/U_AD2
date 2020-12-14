#pragma once
//使用するヘッダーファイル
#include"GameL/SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：クリア
class CSceneClear1 :public CScene
{
public:
	CSceneClear1();
	~CSceneClear1();
	void InitScene();
	void Scene();
};
