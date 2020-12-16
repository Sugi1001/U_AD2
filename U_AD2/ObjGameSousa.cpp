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
			Scene::SetScene(new CSceneMain());
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

	Font::StrDraw(L"���L�[�@�O�ɐi��", 150, 105, 60, c);
	Font::StrDraw(L"���L�[�@���ɐi��", 150, 145, 60, c);
	Font::StrDraw(L"X�L�[�@�W�����v", 150, 185, 60, c);
}