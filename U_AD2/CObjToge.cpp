//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include  "GameL\WinInputs.h"
#include  "GameL\SceneManager.h"

#include "GameHead.h"
#include  "CObjToge.h"
#include  "ObjHero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjToge::Init()
{
  
	//�}�b�v���
	
	

}

//�A�N�V����
void CObjToge::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	/*HitBox�̓��e���X�V
	CHitBox* Hit = Hits::GetHitBox(this);
	Hit->;*/


	////HitBox�̈ʒu�̕ύX
	//HitBox* hit = Hits::GetHitBox(this);
 //   Hit->SetPos(m_px, m_py);

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//��l���ƞ��̓����蔻��
	if ((hx + 126.0f > x) && (hx < x + 96.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
	{
		//�������Ă����
		
	}

}

//�h���[
void CObjToge::Draw()
{
	//�`��J���[��� R=RED G=Green B=Blue A=alpha(���ߏ��)
	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 126.0f;
	src.m_right = 96.0f;
	src.m_bottom = 32.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//3�Ԗڂɓo�^�����O���t�B�b�N��src.dst.c�̏������ɕ`��
	Draw::Draw(0,&src,&dst,c,0.0f)


}

