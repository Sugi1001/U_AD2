//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/HitBoxManager.h"
#include"GameL/Audio.h"
#include"GameHead.h"
#include"Bullet.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBullet::CObjBullet(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjBullet::Init()
{
	m_eff.m_top = 5;
	m_eff.m_left = 0;
	m_eff.m_right = 10;
	m_eff.m_bottom = 0;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;
	m_vx = 0.0f;

	m_vx = 1.0f;

	//�����蔻��phitbox�쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_BULLET, 1);
}

//�A�N�V����
void CObjBullet::Action()
{
	//Resources�̕`�敨��RECT
	m_eff = GetBulletEffec(&m_ani, &m_ani_time, m_del, 2);

	//�e�ۏ��ŏ���--------
	if (m_del == true)
	{


		//���e�A�j���[�V�����I���Ŗ{���ɃI�u�W�F�N�g�̔j��
		if (m_ani == 4)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}


		return;//�I�������́A�����ŃA�N�V�������\�b�h���I��������

	}

	//�e�ێ��s����------

	//�ړ�
	m_vx += 1.0f;
	m_x += m_vx;


	//m_x += 2.0f;
	//m_x += m_vx;

	//�e�ۂ�HitBox�X�V�p�|�C���^�[�擾
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);               //hitbox�̈ʒu��e�ۂ̈ʒu�ɍX�V

	//�G�@�g�U�e�ۂ����S�ɗ̈�O�ɏo����G�@�g�U�e�ۂ�j������
	//bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	/*if (check == false)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		return;
	}*/
	//�̈�O�ɂł���e�ۂ�j������
	if (m_x > 800.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);//�G�@�e�ۂ����L����HitBox�ɍ폜����
	}

	//�����蔻����s���I�u�W�F�N�g���
	int data_base[1] =
	{
		OBJ_HERO,
	};
	//�I�u�W�F�N�g��񕔂Ɠ����蔻����s���A�������Ă���΍폜
	for (int i = 0; i < 1; i++)
	{
		if (hit->CheckObjNameHit(data_base[i]) != nullptr)
		{
	//���e����炷
Audio::Start(3);

			m_del = true;                //���Ŏ��s
		hit->SetInvincibility(true); //�����蔻�薳��
		}
	}

	//�G�@�I�u�W�F�N�g�ƐڐG������e�ۍ폜
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{		m_del = true;               //���Ŏ��s
		hit->SetInvincibility(true);//�����蔻�薳��
	}
}

//�h���[
void CObjBullet::Draw()
{

	//�`��J���[���@R=RED�@G=GREEN�@B=BLUE�@A=ALPHA�i���ߏ��j
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F dst;//�`���\���ʒu
	RECT_F src; //�`�挳�؂���ʒu
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 10.0f;
	src.m_bottom = 5.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//�O�Ԗڂɓo�^�����O���t�B�b�N��src,dst,c�̏��̌��ɕ`��
	Draw::Draw(28, &src, &dst, c, 1.0f);
}