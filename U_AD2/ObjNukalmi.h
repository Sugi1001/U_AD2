#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�ʂ���݃u���b�N&�w�i
class CObjNukalmi : public CObj
{
public:
	CObjNukalmi() {};
	~CObjNukalmi() {};
	void Init();
	void Action();
	void Draw();
private:
	//��l���Ƃ̓����蔻��
	void BlockHit(
		float* x, float* y, bool  scrooll_on,
		bool* up, bool* down, bool* left, bool* right,
		float* vx, float* vy, int* bt
	);
private:
	void BlockDraw(float x, float y, RECT_F* dst, float c[]);
	int m_map[10][500];

	float m_scroll;  //���E�X�N���[���p

};
