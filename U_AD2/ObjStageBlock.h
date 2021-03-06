#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
#include "GameL/DrawTexture.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjStageBlock :public CObj
{
public:
	CObjStageBlock(int map[10][500]);
	~CObjStageBlock() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

	//ブロックとのあたり判定
	void BlockHit(float *x, float *y, bool scroll_on, bool*up, bool* down, bool *left, bool* right, float* vx, float *vy, int* bt);

	//主人公と壁の交差判定
	bool HeroBlockCrossPoint(float x, float y, float vx, float vy, float *out_px, float *out_py, float *out_len);

private:
	void BlockDraw(float x, float y, RECT_F* dst, float c[]);
	void BlockDraw1(float x, float y, RECT_F* dst, float c[]);
	int m_map[10][500] = { 0 };  //マップ情報

	float m_scroll;

	float Dot(float ax, float ay, float bx, float by);//内積
	float Cross(float ax, float ay, float bx, float by);//外積


	//線と線と交差判定
	bool LineCrossPoint(float a1x, float a1y, float a2x, float a2y, float b1x, float b1y, float b2x, float b2y, float* out_px, float* out_py);

};
