#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�Q�[���I�[�o�[
class CObjGameOver1 :public CObj
{
public:
	CObjGameOver1() {};
	~CObjGameOver1() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;
};
