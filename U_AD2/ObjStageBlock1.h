#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
#include "GameL/DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjStageBlock1 :public CObj
{
public:
	CObjStageBlock1(int map[10][250]);
	~CObjStageBlock1() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

	//�u���b�N�Ƃ̂����蔻��
	void BlockHit(float* x, float* y, bool scroll_on, bool* up, bool* down, bool* left, bool* right, float* vx, float* vy, int* bt);

	//��l���ƕǂ̌�������
	bool HeroBlockCrossPoint(float x, float y, float vx, float vy, float* out_px, float* out_py, float* out_len);

private:
	void BlockDraw(float x, float y, RECT_F* dst, float c[]);
	//void BlockDraw1(float x, float y, RECT_F* dst, float c[]);

	//�}�b�v���
	int m_map[10][250] = { 0 };

	float m_scroll;

	float Dot(float ax, float ay, float bx, float by);//����
	float Cross(float ax, float ay, float bx, float by);//�O��


	//���Ɛ��ƌ�������
	bool LineCrossPoint(float a1x, float a1y, float a2x, float a2y, float b1x, float b1y, float b2x, float b2y, float* out_px, float* out_py);

};

