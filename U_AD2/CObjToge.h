#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManeger.h"
#include  "GameHead.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g : ��
class CobjToge : public CObj
{
public:
	CObjToge() {};
	~CObjToge() {};
	void Init(); //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();  //�h���[
private:
	float m_px;   //�ʒu
	float m_py;

	//block�Ƃ̏Փˊm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;


};
