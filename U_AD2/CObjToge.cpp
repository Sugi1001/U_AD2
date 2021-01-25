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
	m_py = 1.0f;
	m_vx = 10.0f;//�ړ��x�N�g��
	m_vy = 10.0f;
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
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx;
	float hp;

	
	
	//�u���b�N�^�C�v���m�p�̕ϐ����Ȃ����߃_�~�[
	int d;


	
	
	

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//���R�����^��
	m_vy += 1.8 / (16.0f);

	//���C
	m_vx += -(m_vx * 0.098);
}

//�h���[
void CObjToge::Draw()
{
	int AniData[4] =
	{
		1, 2 ,2 , 0,
	};

	//�`��J���[���
	float c[4] = { 1.0f , 1.0f , 1.0f , 1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top =64.0f;
	src.m_left =0.0f + AniData[m_ani_frame]*64;
	src.m_right =64.0f + AniData[m_ani_frame]*64;
	src.m_bottom = src.m_top+64.0f;

	
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = (100.0f * m_posture) + m_px;
	dst.m_right = (100 + 100.0f * m_posture) + m_px;
	dst.m_bottom = 100.0f + m_py;

	//3�Ԗڂɓo�^�����O���t�B�b�N��src.dst.c�̏������ɕ`��
	Draw::Draw(1, &src, &dst, c, 0.0f);

}

