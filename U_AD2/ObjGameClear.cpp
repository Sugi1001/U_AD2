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
void CObjClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"�N���A���߂łƂ��I�I", 120, 110, 50, c);

	Font::StrDraw(L"����Ŏ�l���̎؋����Ȃ��Ȃ邱�Ƃ��낤", 180, 200, 44, c);

	Font::StrDraw(L"�������A�؋��������Ȃ��Ƃ������ĂȂ�",160,300,32,c);

	Font::StrDraw(L"��l���̂��`���琶���͑����Ă�����̂��낤��!!", 150, 350, 30, c);
	
	Font::StrDraw(L"�Ō�Ɉꌾ�����Ƃ�����v���C���Ă���Ă��肪�Ƃ��������܂���", 60, 400, 34, c);
}