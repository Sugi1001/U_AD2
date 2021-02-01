//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"ObjStageClea1.h"
#include"GameHead.h"
//#include"ObjGameClear.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjClear1::Init()
{
	//�L�[�t���Oka
	m_key_flag = false;
}

//�A�N�V����
void CObjClear1::Action()
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
void CObjClear1::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"�N���A���߂łƂ��I�I", 150, 105, 60, c);

	Font::StrDraw(L"����Ŏ�l���̎؋��������ɕԍςł��邾�낤", 140, 210, 30, c);

	Font::StrDraw(L"�������A�؋��������Ȃ��Ƃ������ĂȂ�����", 150, 265, 30, c);

	Font::StrDraw(L"��l���̂��`���琶���͑����Ă�����̂��낤��!!", 85, 315, 30, c);

	Font::StrDraw(L"�Ō�Ƀv���C���Ă����������肪�Ƃ��������܂���", 18, 400, 34, c);
}