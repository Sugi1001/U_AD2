#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"

#include"GameHead.h"
#include"ObjTitle"

//�g�p����l�[���y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{

}

//�A�N�V����
void CObjTitle::Action()
{

}

//�h���[
void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"�A���_�[�A�h�x���`���[", 230, 250, 32, c);

	Font::StrDraw(L"GameStart:PushEnterKey", 200, 400, 32, c);
}