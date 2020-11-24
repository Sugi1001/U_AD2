//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

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
	Font::SetStrTex(L"GameOver�@�Q�`���I�`�o�`");
	Font::SetStrTex(L"������߂Ă��܂��̂ł��ˁ`www");
	Font::SetStrTex(L"�R���s�������Ă܂��̂ˁ`?w");
	Font::SetStrTex(L"�^�C�g������o�����Ă��Ă��������܂���!");
	Font::SetStrTex(L"ENTER_KEY�Ń^�C�g���ɖ߂��");
	Font::SetStrTex(L"���x���N���A�ł��Ȃ��ꍇ�͗����������߂ɋx�e���͂��݂܂��傤");
	Font::SetStrTex(L"�̒��ʂȂǂ�������ƍl���ăv���C�𑱂��܂��傤");

	//�Q�[���I�[�o�[�I�u�W�F�N�g�쐬
	CObjGameOver*obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 11);
}

//���s�����\�b�h
void CSceneGameOver::Scene()
{

}