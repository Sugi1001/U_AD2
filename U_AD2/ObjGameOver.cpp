#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGameOver.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameOver::Init()
{
	m_key_flag = false;
}

//�A�N�V����
void CObjGameOver::Action()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[��Title�Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };


	//�Q�[���I�[�o�[���(���C����)
	Font::StrDraw(L"GameOver�@�Q�`���I�`�o�`", 120, 110, 50, c);
	Font::StrDraw(L"���߂�̂͑����ł�", 250, 195, 32, c);
	Font::StrDraw(L"���߂Ȃ���΂����ƃS�[���͌����ė��܂�", 90, 250, 32, c);
	Font::StrDraw(L"���x�ł��`�������W���܂��傤!", 160, 300, 32, c);
	Font::StrDraw(L"ENTER_KEY�Ń^�C�g���ɖ߂�܂�", 40, 400, 50, c);


	//���ӏ���
	Font::StrDraw(L"���x���N���A�ł��Ȃ��ꍇ�͗����������߂ɋx�e���͂��݂܂��傤", 110, 490, 20, c);
	Font::StrDraw(L"�̒��ʂȂǂ�������ƍl���ăv���C�𑱂��܂��傤", 165, 530, 20, c);
}