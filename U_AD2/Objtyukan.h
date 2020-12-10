#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�^�C��
class CObjTyukan : public CObj
{
public:
	CObjTyukan () {};
	~CObjTyukan () {};
	void Init(); //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw(); //�h���[
	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

	//�u���b�N�Ƃ̂����蔻��
	void BlockHit(float* x, float* y, bool scroll_on, 
		bool* up, bool* down, bool* left, bool* right,
		float* vx, float* vy, int* bt);
private:
	void Draw(float x, float y, RECT_F* dst, float c[]);
	void Draw1(float x, float y, RECT_F* dst, float c[]);
	//int m_map[10][150] = { 0 };//�}�b�v���
	int m_map[10][500] = { 0 };
	//	int m_map[10][150] = { 0 };//�}�b�v���
		//int m_map[10][106];//�}�b�v���

	float m_scroll;

};
