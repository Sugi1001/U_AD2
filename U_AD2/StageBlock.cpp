//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"

#include"GameHead.h"
#include"StageBlock.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBlock::Init()
{
	//�}�b�v���
	int block_date[10][10] =
	{
		{1,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
	    {0,0,0,0,0,0,0,0,0,0},
	    {0,0,0,0,0,0,0,0,0,0},
	    {0,0,0,0,0,0,0,0,0,0},
	    {0,0,0,0,0,0,0,0,0,0},
	    {1,1,1,1,1,1,1,1,1,1},

	};
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, block_date, sizeof(int)*(10 * 10));
}
//�A�N�V����
void CObjBlock::Action()
{

}
//�h���[
void CObjBlock::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���
}