#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"
using namespace GameL;
//�I�u�W�F�N�g�F�Q�[���N���A
class CObjClear2 :public CObj
{
public:
	CObjClear2() {};
	~CObjClear2() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[
private:
	bool m_key_flag;//�L�[�t���O
};