#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"
using namespace GameL;
//�I�u�W�F�N�g�F�Q�[���N���A
class CObjClear1 :public CObj
{
public:
	CObjClear1() {};
	~CObjClear1() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[
private:
	bool m_key_flag;//�L�[�t���O
};

