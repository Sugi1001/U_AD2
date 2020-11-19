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

	Font::StrDraw(L"�N���A���߂łƂ��I�I", 160, 100, 60, c);

	Font::StrDraw(L"����Ŏ�l���̎؋����Ȃ��Ȃ邱�Ƃ��낤", 150, 195, 30, c);

	Font::StrDraw(L"�������A�؋��������Ȃ��Ƃ������ĂȂ�",150,250,30,c);

	Font::StrDraw(L"��l���̂��`���琶���͑����Ă�����̂��낤��!!", 100, 300, 30, c);
	
	Font::StrDraw(L"�Ō�Ƀv���C���Ă���Ă��肪�Ƃ��������܂���", 20, 380, 34, c);
}