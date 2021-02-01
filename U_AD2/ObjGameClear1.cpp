//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"

#include"GameHead.h"
#include"ObjGameClear1.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjClear3::Init()
{
	//�L�[�t���O
	m_key_flag = false;
}

//�A�N�V����
void CObjClear3::Action()
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
void CObjClear3::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"���̊K�w�ցI�I", 150, 125, 60, c);

	Font::StrDraw(L"���͂����Ɠ���Ȃ邯��Ǐł炸�s����", 90, 305, 30, c);

	Font::StrDraw(L"���m������", 80, 405, 30, c);
	Font::StrDraw(L"���{�ň�ԑ傫�����A�͈��Ɠ�(�������ǂ�)����", 80, 455, 30, c);
	Font::StrDraw(L"��茧�ɂ����đ�������23,702m����", 80, 505, 30, c);
}