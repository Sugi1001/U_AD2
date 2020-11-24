#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"


#include"GameHead.h"
#include"ObjTitle.h"

//�g�p����l�[���y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	m_key_flag = false;
}

//�A�N�V����
void CObjTitle::Action()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[�����C���Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjTitle::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	
	Font::StrDraw(L"�A���_�[�A�h�x���`���[", 230, 250, 32, c);
	Font::StrDraw(L"�G���^�L�[�����Ă����������肢���܂�(*-*)", 100, 300, 32, c);


		//RECT_F src;//�`�挳�؂���
		//RECT_F dst;//�`���\���ʒu

		 //�w�i�\��
		//src.m_top = 256.0f;
		//src.m_left = 0.0f;
		//src.m_right = 512.0f;
		//src.m_bottom = 512.0f;

		//dst.m_top = 0.0f;
		//dst.m_left = 0.0f;
		//dst.m_right = 800.0f;
		//dst.m_bottom = 600.0f;



		//Draw::Draw(10, &src, &dst, c, 0.0f);

}