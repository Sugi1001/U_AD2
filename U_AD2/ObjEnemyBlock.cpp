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
	

}

//�h���[(CObjEnemy Block�̃h���[)
void CObjEnemyBlock::Draw()
{
	//�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`���؂���ʒu
	RECT_F dst; //�`���\���ʒu
	
	////�؂���ʒu�̐ݒ�
	//src.m_top = 0.0f;
	//src.m_left = 0.0f;
	//src.m_right = 50.0f;
	//src.m_bottom = 50.0f;

	////�\���ʒu�̐ݒ�
	//dst.m_top = 0.0f;
	//dst.m_left = 50.0f;
	//dst.m_right = 0.0f;
	//dst.m_bottom = 50.0f;



	////0�Ԗڂɓo�^�����O���t�B�b�N��src.dst.c�̏������Ƃɕ`��
	//Draw::Draw(9, &src, &dst, c, 0.0f);
}