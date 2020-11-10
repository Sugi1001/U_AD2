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
	m_posture =0.0f; //�E����0.0f�@������1.0f

	m_ani_time = 0;
	m_ani_frame = 0;//�Î~�t���[���������ɂ���

	float m_speed_power = 6.0f;//�ʏ푬�x
	float m_ani_max_time;//�A�j���[�V�����Ԋu��

	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	

	m_block_type = 0;

	m_scroll = 0;

	
}

//�A�N�V����
void CObjHero::Action()
{
	//HitBox�̓��e���X�V
	//CHitBox* hit = Hits::GetHitBox(this);
	//hit->SetPos(m_x, m_y);

	//������l���ɐڐG�������l����HP�����炷
	//if (hit->CheckObjNameHit(OBJ_TOGE) != nullptr)
	//{
		//m_hp -= 2;
	//}
	//�ړ��x�N�g���̔j��
	 
	if (m_py > 1000.0f)
	{
	//��O�ɏo���烊�X�^�[�g
		Scene::SetScene((new CSceneMain()));//CSceneGameOver
	
	}

	////�����蔻����s���I�u�W�F�N�g���
	//int data_base[3] =
	//{
	//	OBJ_HERO,
	//	OBJ_TOGE,
	//	OBJ_ENEMY_BLOCK,

	//};

	//�I�u�W�F�N�g��񕔂Ɠ����蔻����s���������Ă���΁AHP��1���炷
	//for (int i = 0; i < 3; i++)
	//{
		//if (hit->CheckObjNameHit(OBJ_TOGE) != nullptr)
		//{
			//m_hp -= 1;
		//}

	//}

	//HP��0�ɂȂ�����j��
	//if (m_hp <= 0)
	//{
		//this->SetStatus(false);
		//Hits::DeleteHitBox(this);
	//}



	
	if (Input::GetVKey('X') == true)
	{
		if (m_hit_down == true)
		{
			m_vy = - 20;
		}
	}
	
	////�L�[�̓��͕���
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx=+1.5f;
		m_vx=-3.0f;
		m_posture = 1.5f;
		m_ani_time+=1;
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
		m_vx=-1.5f;
		m_vx=+3.0f;
		m_posture = 0.0f;
		m_ani_time+=1;
	}
	else
	{
		m_ani_frame = 1; //�L�[�����͂������ꍇ�Î~�t���[���ɂ���
		m_ani_time = 1;
	}
	

	//���C
	m_vx += -(m_vx * 0.098);

	//���R�����^��
	m_vy += 9.8 / (16.0f);

	//�u���b�N�Ƃ̓����蔻����s
	CObjStageBlock* pb = (CObjStageBlock*)Objs::GetObj(OBJ_STAGE_BLOCK);
	pb->BlockHit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

////������l���ɐڐG�������l����HP�����炷
//	if (hit->CheckObjNameHit(OBJ_TOGE) != nullptr)
//	{
//		m_hp -= 2;
//	}

	
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
	
	int AniData[4] = { 1,0,2,0 };

	////�`��J���[���
	//float  c[4] = { 1,0,2,0};
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	
	
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 320.0f;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = 32.0f;


	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 64.0;
	dst.m_bottom = 64.0;

	//�`��
	Draw::Draw(1, &src, &dst, c, 1.0f);



	////�\���ʒu�̐ݒ�
	//dst.m_top = 0.0f + m_py;
	//dst.m_left = (64 * m_posture) + m_px;
	//dst.m_right = (64 + 12.0f * m_posture) + m_py;
	//dst.m_bottom = 64-0.1f + m_px;
	
	//dst.m_bottom = 64-0.1f + m_px;
	//dst.m_bottom = 64-0.1f + m_px;
	//dst.m_left = (64.0f * m_posture);64.0f +m_px;
	//dst.m_right = (64 + 64.0f * m_posture); 64.0f + m_px;
	//dst.m_bottom = 64-0.1f + m_py;
	//dst.m_left =( 64.0f*m_posture)+ m_px;
	//dst.m_right = (64-64.0f*m_posture)+64.0f+m_px;
	//dst.m_bottom = 64-0.1f + m_py;
	//dst.m_bottom = 64-0.1f + m_py;
	//dst.m_left =(     64.0f*m_posture)+ m_px;
	//dst.m_right = (64-64.0f*m_posture)+64.0f+m_px;
	//dst.m_bottom = 64-0.1f + m_py;
	//dst.m_bottom = 64-0.1f + m_py;
	//dst.m_left =/*(     64.0f*m_posture) */+ m_px;
	//dst.m_right = /*(64-64.0f*m_posture)*/64.0f+m_px;
	//dst.m_bottom = 64-0.1f + m_py;
	///*dst.m_left =(     64.0f*m_posture) + m_px;
	//dst.m_right = (64-64.0f*m_posture)+64.0f+m_px;*/
	//dst.m_left =(     64.0f*m_posture) + m_px;
	///*dst.m_right = (64 - 64.0f*m_posture)+m_px;*/
	///*dst.m_left =(     64.0f*m_posture)+ 64.0f + m_px;*/
	//dst.m_right = /*(64-64.0f*m_posture)*/64.0f+m_px;
	//dst.m_left =/*(     64.0f*m_posture)*/ + m_px;
	//dst.m_right = (64.0f*m_posture)+m_px;
	//dst.m_bottom = 64.0f + m_py;
	//dst.m_right = (64 - 64.0f * m_posture) + m_px;
	//dst.m_bottom = 64.0f + m_py;
	////dst.m_left =0.0f + m_px;
	//dst.m_right =64.0f+m_px;
	////dst.m_bottom = 64.0f + m_py;*/


	////�`��
	//Draw::Draw(1, &src, &dst, c, 0.0f);
	//Draw::Draw(1, &src, &dst, c, 1.0f);
	//Draw::Draw(2, &src, &dst, c, 0.0f);
	////Draw::Draw(0, &src, &dst, c, 0.0f);
	////Draw::Draw(0, &src, &dst, c, 1.0f);
}