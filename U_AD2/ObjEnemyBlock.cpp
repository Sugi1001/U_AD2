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
	
	


}
//�A�N�V����
void CObjEnemyBlock::Action()
{

	//���C
	m_vx += -(m_vx * 0.098);

	//���R�����^��
	m_vy += 9.8 / (16.0f);


}

//�h���[(CObjEnemy Block�̃h���[)
void CObjEnemyBlock::Draw()
{
	//�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��)
	//float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//RECT_F src; //�`���؂���ʒu
	//RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	//src.m_top = 0.0f;
	//src.m_left = 0.0f;
	//src.m_right = src.m_left + 50.0f;
	//src.m_bottom = src.m_top + 50.0f;


	//�\���ʒu�̐ݒ�
	//dst.m_top = 0.0f + m_py;
	//dst.m_left = (30.0f * m_posture) + m_px;
	//dst.m_right = (50 - 50.0f * m_posture) + m_px;
	//dst.m_bottom = 64.0 + m_py;


	//�\���ʒu�̐ݒ�
	//dst.m_top = 0.0f + m_py;
	//dst.m_left = (30.0f * m_posture) + m_px;
	//dst.m_right = (50 - 50.0f * m_posture) + m_px;
	//dst.m_bottom = 64.0 + m_py;


	//0�Ԗڂɓo�^�����O���t�B�b�N��src.dst.c�̏������Ƃɕ`��
	//Draw::Draw(9, &src, &dst, c, 0.0f);
}