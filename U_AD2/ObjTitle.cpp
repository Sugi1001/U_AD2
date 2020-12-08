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

	
	Font::StrDraw(L"�A���_�[�A�h�x���`���[", 17, 150, 70, c);
	Font::StrDraw(L"�G���^�L�[��������X�^�[�g�Ȃ̂���I�I(*-*)", 28, 485, 35, c);

	Font::StrDraw(L"���炷���Ȃ̂���`", 270, 300, 32, c);
	Font::StrDraw(L"��l���̂��ƂɈŋ����I�I", 220, 350, 32, c);
	Font::StrDraw(L"�؂肽���̕ԍς̂��߂ɓ��A�ցI�I", 200, 390, 32, c);

	Font::StrDraw(L"�ȂɁH��l�����Ȃ��Ȃ��Ƃ���o�Ȃ��H", 310, 540, 15, c);
	Font::StrDraw(L"�\���@�������f�v���Ă�Ă�", 330, 558, 15, c);

}