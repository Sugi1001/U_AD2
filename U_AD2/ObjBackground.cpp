//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"GameL\SceneManager.h"
#include"ObjTitle.h"
#include"ObjBackground.h"

//�g�p���Ă���Ζ�̃l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBackground::Init()
{

}

//�A�N�V����
void CObjBackground::Action()
{

}

//�h���[
void CObjBackground::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top    = 264.0f;
	src.m_left   = 0.0f;
	src.m_right  = 512.0f;
	src.m_bottom = 448.0f;
		
	dst.m_top    = 0.0f;
	dst.m_left   = 0.0f;
	dst.m_right  = 80.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(10, &src, &dst, c, 0.0f);
}