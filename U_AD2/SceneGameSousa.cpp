//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL/SceneObjManager.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneGameSousa.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneGameSousa::CSceneGameSousa()
{

}

//�f�X�g���N�^
CSceneGameSousa::~CSceneGameSousa()
{

}

//���������\�b�h
void CSceneGameSousa::InitScene()
{
	Font::SetStrTex(L"���L�[�@�O�ɐi��");
	Font::SetStrTex(L"���L�[�@���ɐi��");
	Font::SetStrTex(L"X�L�[�@�W�����v");
	Font::SetStrTex(L"�ł炸���J�ɐi��ł������i�o���k�j");
	Font::SetStrTex(L"�A�C�e�������邩��U���ɖ𗧂ĂĂˁI");

	//�N���A�I�u�W�F�N�g�쐬
	CObjGameSousa* obj = new CObjGameSousa();
	Objs::InsertObj(obj, OBJ_GAME_SOUSA, 1);
}

//���s�����\�b�h
void CSceneGameSousa::Scene()
{

}