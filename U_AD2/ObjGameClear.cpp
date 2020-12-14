//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"

#include"GameHead.h"
#include"ObjGameClear.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjClear::Init()
{
	//�L�[�t���O
	m_key_flag = false;
}

//�A�N�V����
void CObjClear::Action()
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
void CObjClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"���̊K�w�ցI�I", 150, 105, 60, c);

//	Font::StrDraw(L"����Ŏ�l���̎؋��������ɕԍςł��邾�낤", 140, 210, 30, c);

	//Font::StrDraw(L"�������A�؋��������Ȃ��Ƃ������ĂȂ�",150,265,30,c);

	//Font::StrDraw(L"��l���̂��`���琶���͑����Ă�����̂��낤��!!", 85, 315, 30, c);
	
	//Font::StrDraw(L"�Ō�Ƀv���C���Ă����������肪�Ƃ��������܂���", 18, 400, 34, c);
}