//SLT�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL(0)
#define _HAS_ITERATOR_DEBUGGING(0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p����w�b�_�[
#include "SceneGameOver.h"
#include "GameHead.h"

//�R���g���N�^
CSceneGameOver::CSceneGameOver()
{

}

//�f�X�g���N�^
CSceneGameOver::~CSceneGameOver()
{

}

//���������\�b�h
void CSceneGameOver::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex("L"GameOver);
	Font::(L"NEXT_CHALLENGE:????");
}

//���s�����\�b�h
void CSceneGameOver::Scene()
{

}