#pragma once
//�g�p����w�b�_�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�A�C�e��
class CObjItem :public CObj
{
public:
	CObjItem() {};
	~CObjItem() {};
	void Init();
	void Action();
	void action();
	void Draw();

	void SetTimeFlag(bool b) { m_flag_time = b; }
private:
	int m_time;
	bool m_flag_time;
};

