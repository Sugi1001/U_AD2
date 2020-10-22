#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjBlock :public CObj
{
public:
	CObjBlock() {};
	~CObjBlock() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

	//ブロックとのあたり判定
	void BlockHit(float *x, float *y, bool scroll_on, bool*up, bool* down, bool *left, bool* right, float* vx, float *vy, int* bt);
private:
	void BlockDraw(float x, float y, RECT_F* dst, float c[]);
	int m_map[10][100];

	float m_scroll;
};
