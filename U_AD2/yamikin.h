#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�{�X�@
class CObjyamikin :public CObj
{

public:
	CObjyamikin(float x, float y);
	~CObjyamikin() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_y;//�G�@��Y�����Ɉʒu
	float m_vx;//�G�@�ړ��x�N�g����
	float m_vy;//�G�@�ړ��x�N�g����
	float m_r;//�T�C���J�[�u�p�p�x
	int m_time;//�e�ۊԊu���x
	int m_hp;//�{�X�̃q�b�g�|�C���g
};


