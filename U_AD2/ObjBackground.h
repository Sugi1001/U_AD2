#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"ObjTitle.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjBackground:public CObj
{
public:
	CObjBackground() {};
	~CObjBackground() {};
	void Init();  //�ϔC�Ѓ��E�Y
	void Action();//���n��
	void Draw();  //�D�[
private:

};

