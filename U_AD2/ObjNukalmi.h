#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:ぬかるみブロック&背景
class CObjNukalmi : public CObj
{
public:
	CObjNukalmi() {};
	~CObjNukalmi() {};
	void Init();
	void Action();
	void Draw();
private:
	//主人公との当たり判定
	void BlockHit(
		float* x, float* y, bool  scrooll_on,
		bool* up, bool* down, bool* left, bool* right,
		float* vx, float* vy, int* bt
	);
private:
	void BlockDraw(float x, float y, RECT_F* dst, float c[]);
	int m_map[10][500];

	float m_scroll;  //左右スクロール用

};
