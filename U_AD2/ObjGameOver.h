#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�Q�[���I�[�o�[
class CObjGameOver :public CObj
{
public:
	CObjGameOver() {};
	~CObjGameOver() {};
	void Init();
	void Action();
	void Draw();
private:
};