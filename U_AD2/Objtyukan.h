#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクトタイム
class CObjTyukan : public CObj
{
public:
	CObjTyukan () {};
	~CObjTyukan () {};
	void Init(); //イニシャライズ
	void Action(); //アクション
	void Draw(); //ドロー
	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

	//ブロックとのあたり判定
	void BlockHit(float* x, float* y, bool scroll_on, 
		bool* up, bool* down, bool* left, bool* right,
		float* vx, float* vy, int* bt);
private:
	void Draw(float x, float y, RECT_F* dst, float c[]);
	void Draw1(float x, float y, RECT_F* dst, float c[]);
	//int m_map[10][150] = { 0 };//マップ情報
	int m_map[10][500] = { 0 };
	//	int m_map[10][150] = { 0 };//マップ情報
		//int m_map[10][106];//マップ情報

	float m_scroll;

};
