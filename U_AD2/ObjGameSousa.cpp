//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"

#include"GameHead.h"
#include"ObjGameSousa.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameSousa::Init()
{
	//�L�[�t���O
	m_key_flag = false;
}

//�A�N�V����
void CObjGameSousa::Action()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[��Title�Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain1());
			//Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}

	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjGameSousa::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"���L�[�@�O�ɐi��", 150, 150, 60, c);
	Font::StrDraw(L"���L�[�@���ɐi��", 150, 250, 60, c);
	Font::StrDraw(L"X�L�[�@�W�����v", 150, 350, 60, c);

	Font::StrDraw(L"�ł炸���J�ɐi�ނƂ����ł���i�o���k�j", 35, 460, 40, c);
	Font::StrDraw(L"�G���^�[�L�[�ŃQ�[���X�^�[�g", 150, 510, 40, c);
}