//�r�k�s�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GeamL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"

//�g�p����w�b�_�[
#include"SceneMain.h"
#include"GameHead.h"

//�R���g���N�^
CSceneTitle::CSceneTitle()
{

}

//�f�X�g���N�^
CSceneTitle::~CSceneTitle()
{

}

//�Q�[�����C�����������C��
void CSceneTitle::InitScene()
{
	//�o�͂�����O���t�B�b�N���T�N�Z�C
	Font::SetStrTex(L"�A���_�[�A�h�x���`���[");

	CObjTitle*obj = new CObjTitle();
	Objs::InsertObj(obj, OBJ_TITLE, 1);
}

//�Q�[�����C�����s���\�b�h
void CSceneTitle::Scene()
{

}
