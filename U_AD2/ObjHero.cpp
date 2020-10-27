//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "Objhero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_px = 3.0f; //�ʒu
	m_py = 3.0f;
	m_vx = 3.0f;//�ړ��x�N�g��
	m_vy = 3.0f;
	m_posture = 3.0f; //�E����0.0f�@������1.0f

	m_ani_time = 0;
	m_ani_frame = 1;//�Î~�t���[���������ɂ���

	float m_speed_power = 0.5f;//�ʏ푬�x
	float m_ani_max_time;//�A�j���[�V�����Ԋu��

	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

}

//�A�N�V����
void CObjHero::Action()
{
	
      
	//if (m_py > 1000.0f)
	//{
	//	//��O�ɏo���烊�X�^�[�g
	//	Scene::SetScene(new CSceneMain());
	//}

	
	if (Input::GetVKey('X') == true)
	{
		if (m_hit_down == true)
		{
			m_vy = - 20;
		}
	}
	
	//�L�[�̓��͕���
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx=-1.5f;
		m_posture = 1.0f;
		m_ani_time+=1;
	}
    else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx=+1.5f;
		m_posture = 0.0f;
		m_ani_time+=1;
	}
	else
	{
		m_ani_frame = 0; //�L�[�����͂������ꍇ�Î~�t���[���ɂ���
		m_ani_time = 0;
	}
	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame+=1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 1)
	{
		m_ani_frame = 0;
	}
	

	//���C
	m_vx += -(m_vx * 0.098);

	//���R�����^��
	m_vy += 9.8 / (16.0f);



	//�u���b�N�Ƃ̓����蔻����s
	/*CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);*/


	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;
}

//�h���[
void CObjHero::Draw()
{
	int AniData[4] = { 1,0,2,0 };

	//�`��J���[���
	float  c[4] = { 1,0,2,0};

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 1.0f;
	src.m_left = 0.0f + AniData[m_ani_frame] * 30;
	src.m_right = 64.0f + AniData[m_ani_frame] * 30;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 1.0f + m_py;
	dst.m_left = (64.0f * m_posture) + m_px;
	dst.m_right = (64 + 64.0f * m_posture) + m_py;
	dst.m_bottom = 64.0f + m_py;
	dst.m_top = 40.0f + m_py;
	dst.m_left = (30.0f * m_posture) + m_px;
	dst.m_right = (40 + 64.0f * m_posture) + m_py;
	dst.m_bottom = 30.0f + m_py;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}