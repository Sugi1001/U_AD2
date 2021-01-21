#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームオーバーデス
class CSceneGameOver1 :public CScene
{
public:
	CSceneGameOver1();
	~CSceneGameOver1();
	void InitScene();
	void Scene();
private:
};
