#pragma once

//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�Q�[���N���A
class CObjGameSousa :public CObj
{
public:
	CObjGameSousa() {};
	~CObjGameSousa() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[
private:
	bool m_key_flag;//�L�[�t���O
};