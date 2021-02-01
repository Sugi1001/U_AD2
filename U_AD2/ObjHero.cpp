//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjHero.h"

#include "ObjStageBlock.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHero::Init()
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



	m_block_type = 0; //����ł���u���b�N�̎�ނ��m�F�p

	m_scroll -=2.0f;

}

//�A�N�V����
void CObjHero::Action()
{


	if (m_py > 1000.0f)
	{
		//��O�ɏo���烊�X�^�[�g
		Scene::SetScene((new CSceneGameOver()));//CSceneGameOver

		

	}

	

	

	

	




	if (Input::GetVKey('X') == true)
	{
		if (m_hit_down == true)
		{
			m_vy = -20;
		}
	}

	////�L�[�̓��͕���
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx = +1.5f;
		m_vx = -5.0f;
		m_posture = 1.5f;
		m_ani_time += 1;
	}
	if (m_ani_time > 4)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx = -10.5f;
		m_vx = +3.0f;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 1; //�L�[�����͂������ꍇ�Î~�t���[���ɂ���
		m_ani_time = 1;
		m_vx -= 0.22f;
	}


	//���C
	m_vx += -(m_vx * 0.098);

	//���R�����^��
	m_vy += 10.8 / (16.0f);

	//�u���b�N�Ƃ̓����蔻����s
	CObjStageBlock* pb = (CObjStageBlock*)Objs::GetObj(OBJ_STAGE_BLOCK);
	pb->BlockHit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vy, &m_vx,
	    &m_block_type);



		//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//��l���̈ʒuX�i���Q���j+��l���@�̕�����X�������ɗ̈�O��F��
	if (m_px + 20.0f > 800.0f)
	{
		m_px = 800.0f - 20.0f;
	}
}

//�h���[
void CObjHero::Draw()
{

	///�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	



	//��l���P
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = (40.0f * m_posture) + m_px;
	dst.m_right = (64 - 50.0f * m_posture) + m_px;
	dst.m_bottom = 64.0 + m_py;

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;



	//�`��
	Draw::Draw(1, &src, &dst, c, 1.0f);
}