#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�{�X�@
class CObjEnemy :public CObj
{

public:
	CObjEnemy(float x, float y) {};
	~CObjEnemy() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;//�G�@��X�����̈ʒu
	float m_y;//�G�@��Y�����Ɉʒu
	float m_vx;//�G�@�ړ��x�N�g����
	float m_vy;//�G�@�ړ��x�N�g����
};
