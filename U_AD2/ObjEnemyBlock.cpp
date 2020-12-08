//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include  "ObjEnemyBlock.h"
#include "Objtyukan.h"

//�g�p����w�b�_�[�t�@�C��
using namespace GameL;

//�C�j�V�����C�Y
void CObjEnemyBlock::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_px = 400.0f;
	m_py = 64.0f;
	
	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;



}
//�A�N�V����
void CObjEnemyBlock::Action()
{
	//��̈ʒu���擾
	CObjEnemyBlock* enemyblock = (CObjEnemyBlock*)Objs::GetObj(OBJ_ENEMY_BLOCK);
	float hx = enemyblock->GetX();
	float hy = enemyblock->GetY();

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (m_map[i][j] > 0)
			{
				//�v�f�ԍ������W�ɕύX
				float x = j * 64.0f;
				float y = i * 64.0f;
			}
		}
	}

	//��̈ʒuX�i���Q���j+��l���@�̕�����X�������ɗ̈�O��F��
	if (m_px + 20.0f > 800.0f)
	{
		m_px = 50.0f - 50.0f;
	}

	//�ړ��x�N�g���̏�����
	m_vx = 0.0f;
	m_vy = 2.0f;

	//�|�C���^�����
	//CObjEnemyBlock* obj = (CObjEnemyBlock)Objs::GetObj(OBJ_ENEMY_BLOCK)
	
	//���C
	m_vx += -(m_vx * 0.098);

	//���R�����^��
	m_vy += 9.8 / (16.0f);

	//�ړ����Ă��Ȃ���Ԃ�64pixel�P�ʂɌ덷������ꍇ
	int w = ((int)m_px) % 64;
	if (w != 0)
	{

		//�����I�ɓ��͂���Ă��������Ɉړ��Ɉړ�
		if (m_vx > 0)
		{
			//�덷��0�ɋ߂Â���悤�Ɉړ�
			m_vx = (64 - w) / 5.0f;
		}
		if (m_vx < 0)
		{
			//�덷��0�ɋ߂Â���悤�Ɉړ�
			m_vx = (OBJ_ENEMY_BLOCK - w) / OBJ_STAGE_BLOCK;
		}
		else
		{
			//�덷�����Ȃ�ړ�����
			m_vx = w / OBJ_STAGE_BLOCK;
		}
	}

	//�ړ��~�܂�����A�����Ȃ��t���O�𗧂Ă�
	if (m_vy == OBJ_ENEMY_BLOCK && abs(m_vx) <= OBJ_ENEMY_BLOCK)
	{
		m_stop_flag = false;
		//obj->SetMap(m_stop_map_x, m_stop_map_y, 99);
	}

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
	src.m_right = src.m_left + 50.0f;
	src.m_bottom = src.m_top + 50.0f;


	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = (30.0f * m_posture) + m_px;
	dst.m_right = (50 - 50.0f * m_posture) + m_px;
	dst.m_bottom = 64.0 + m_py;


	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = (30.0f * m_posture) + m_px;
	dst.m_right = (50 - 50.0f * m_posture) + m_px;
	dst.m_bottom = 64.0 + m_py;


	//0�Ԗڂɓo�^�����O���t�B�b�N��src.dst.c�̏������Ƃɕ`��
	Draw::Draw(9, &src, &dst, c, 0.0f);
}