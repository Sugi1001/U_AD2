#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g : ��
class CObjToge : public CObj
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
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	float m_posture;  //�p��
    float GetX() { return m_px; }
	float GetY() { return m_py; }
	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }


	int m_ani_time;
	int m_ani_frame;

	


	//block�Ƃ̏Փˊm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
	bool m_block_type;



};
