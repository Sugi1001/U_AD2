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
	m_px = 100.0f;
	m_py = 0.0f;
	m_x;
	m_y;
	
	m_posture = 1.0f;

	m_ani_time = 0;
	m_ani_frame = 1;
	

	
	//�}�b�v���
	////�����蔻��p��HitBox�̍쐬
	//Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_TOGE, 4);
	
	

}

//�A�N�V����
void CObjToge::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx;
	float hp;

	//�I�u�W�F�N�g�Ǝ�l���̓����蔻��
	
	//�u���b�N�^�C�v���m�p�̕ϐ����Ȃ����߃_�~�[
	int d;


	
	
	//�u���b�N�Ƃ̓����蔻����s
	CObjStageBlock* pb = (CObjStageBlock*)Objs::GetObj(OBJ_STAGE_BLOCK);
	pb->BlockHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d
	);
	/*CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();*/

	//���ƐڐG�������l����HP�����炷

	//HitBox�̓��e���X�V

	
}

//�h���[
void CObjToge::Draw()
{
	int AniData[4] =
	{
		1, 0 ,2 , 0,
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

	
	//�u���b�N���������Ă���
	CObjStageBlock* block = (CObjStageBlock*)Objs::GetObj(OBJ_STAGE_BLOCK);
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f * m_posture) + m_px;
	dst.m_right = (64 - 64.0f * m_posture) + m_px;
	dst.m_bottom = 64.0f + m_py;

	//3�Ԗڂɓo�^�����O���t�B�b�N��src.dst.c�̏������ɕ`��
	//Draw::Draw(8, &src, &dst, c, 0.0f);





}

