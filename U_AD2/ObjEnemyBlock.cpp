//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include  "ObjEnemyBlock.h"

//�g�p����w�b�_�[�t�@�C��
using namespace GameL;

//�C�j�V�����C�Y
void CObjEnemyBlock::Init()
{
	

	m_px = 1.0f;  //�ʒu
	m_py = 0.0f;    //�ړ��x�N�g��
	m_vy = 1.0f;
	m_posture = 1.0f;  //�E����0.0f�@�������@1.0f

	m_ani_time = 0;  //�Î~�t���[���������ɂ���B
	m_ani_frame = 1;

	float m_speed_power = 6.0f;//�ʏ푬�x
	float m_ani_max_time;//�A�j���[�V�����Ԋu��


	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;



}
//�A�N�V����
void CObjEnemyBlock::Action()
{


	//����
	if (false)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (false)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 1;
		m_ani_time = 0;  //�Î~�t���[��
	}

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}


	//���R�����^��
	m_vy += 9.8 / (16.0f);

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;



}

//�h���[(CObjEnemy Block�̃h���[)
void CObjEnemyBlock::Draw()
{
	//�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`���؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 50.0f;
	src.m_bottom = 50.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 50.0f + m_x;
	dst.m_bottom = 50.0f + m_y;


	//0�Ԗڂɓo�^�����O���t�B�b�N��src.dst.c�̏������Ƃɕ`��
	Draw::Draw(10, &src, &dst, c, 0.0f);
}