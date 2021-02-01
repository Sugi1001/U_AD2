//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include  "GameL\WinInputs.h"
#include  "GameL\SceneManager.h"
#include  "GameL\HitBoxManager.h"

#include "GameHead.h"
#include  "CObjToge.h"
#include  "ObjHero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjToge::Init()
{
	m_px = 1.0f; //�ʒu
	m_py = 0.0f;
	m_vx = 1.0f;//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f; //�E����0.0f�@������1.0f


	m_ani_time = 0;
	m_ani_frame = 1;//�Î~�t���[���������ɂ���

	float m_speed_power = 1.0f;//�ʏ푬�x
	float m_ani_max_time;//�A�j���[�V�����Ԋu��

	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;


}

//�A�N�V����
void CObjToge::Action()
{
	

	
	
	

	//�h�̈ʒu���擾
	CObjToge* Toge = (CObjToge*)Objs::GetObj(OBJ_TOGE);
	float hx = Toge->GetX();
	float hy = Toge->GetY();
	//�h�Փ˔���
	Toge->SetUp(false);
	Toge->SetLeft(false);
	Toge->SetRight(false);

	//�ʒu�̍X�V
	m_px += m_vy;
	m_py += m_vy;

	//���C
	m_vx += -(m_vx * 0.098);

	//���R�����^��
	m_vy += 0.4 / (16.0f);


	
}

//�h���[
void CObjToge::Draw()
{
	int AniData[4] =
	{
		2,2,2,2
	};

	//�`��J���[���
	float c[4] = { 1.0f , 1.0f , 1.0f , 1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = (40.0f * m_posture) + m_px;
	dst.m_right = (30 - 50.0f * m_posture) + m_px;
	dst.m_bottom = 64.0 + m_py;

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 100.0f;
	src.m_bottom = 100.0f;



	//3�Ԗڂɓo�^�����O���t�B�b�N��src.dst.c�̏������ɕ`��
	Draw::Draw(6, &src, &dst, c, 0.0f);
	

}

