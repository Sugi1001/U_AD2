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

	
	Font::StrDraw(L"�A���_�[�A�h�x���`���[", 150, 200, 50, c);
	Font::StrDraw(L"�G���^�L�[�����Ă����������肢���܂�(*-*)", 120, 270, 30, c);

	Font::StrDraw(L"���炷���Ȃ̂���`", 270, 400, 32, c);
	Font::StrDraw(L"��l���̂��ƂɈŋ����I�I", 220, 450, 32, c);
	Font::StrDraw(L"�؂肽���̕ԍς̂��߂ɓ��A�ցI�I", 200, 490, 32, c);

	Font::StrDraw(L"�ȂɁH��l�����Ȃ��Ȃ��Ƃ���o�Ȃ��H", 310, 530, 15, c);
	Font::StrDraw(L"�\���@�������f�v���Ă�Ă�", 330, 542, 15, c);
}