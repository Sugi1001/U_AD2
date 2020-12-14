//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/HitBoxManager.h"

#include"GameHead.h"
#include"yamikin.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjyamikin::CObjyamikin(float x, float y)
{

	m_y = y;
}


//�C�j�V�����C�Y
void CObjyamikin::Init()
{
	m_hp = 45;
	m_time = 0;
	m_r = 0.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�����蔻��pHitBox�쐬
	//Hits::SetHitBox(this, m_y + 50, 250, 200, ELEMENT_YAMIKIN, OBJ_ENEMY, 1);
}

//�A�N�V����
void CObjyamikin::Action()
{

	m_time++;
	//�ʏ�e����
	if (m_time % 50 == 0)
	{
		
	}
	//m_time�̏�����
	if (m_time > 1000)
	{
		m_time = 0;
	}

	//�p�x���Z
	m_r += 2.0f;

	//360�x�@�ŏ����l�ɖ߂�
	if (m_r > 360.0f)
		m_r = 0.0f;

	//�ړ�����
	m_vy = sin(3.14 / 180 * m_r);//sin�Ƃ����߂�m_xy�ɂ����

	//���x��t��
	m_vy *= 1.5f;



	//�ړ��x�N�g�������W�ɉ��Z����
	m_y += m_vy;



	//�x�N�g���̒��������߂�i�O�����̒藝�j
	float  r = 0.0f;
	r = m_vx * +m_vy * m_vy;
	r = sqrt(r);//r�����[�g�����߂�
	//�������O���ǂ������߂�
	if (r == 0.0f)
	{
		;//�O�Ȃ牽�����Ȃ�
	}
	else
	{
		//���K�����s��
		m_vy = 1.0f / r * m_vy;
	}




	//�G�@�����S�ɗ̈�O�ɏo����G�@��j������
	if (m_y < -32.0f)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�G�@�e�ۂ����L����HitBox�ɍ폜����
	}

	//�e�ۂƐڐG�����HP������
	/*if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
	}*/

	//HP���O�ɂȂ�Ɣj��
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		Scene::SetScene(new CSceneClear());
	}



}

//�h���[
void CObjyamikin::Draw()
{
	//�`��J���[���@R=RED�@G=GREEN�@B=BLUE�@A=ALPHA�i���ߏ��j
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_right = 0.0f;
	src.m_left = 64.0f;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_right = 0.0f;
	dst.m_left = 64.0f;
	dst.m_bottom = 64.0f + m_y;

	//1�Ԗڂɓo�^�����O���t�B�b�N��src,dst,c�̏��̌��ɕ`��
	Draw::Draw(1, &src, &dst, c, 0.0f);
}