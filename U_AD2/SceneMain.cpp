//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{
	
}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//���������\�b�h
void CSceneMain::InitScene()
{
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"�w�i.png",0,TEX_SIZE_512);
	//�O���f�[�^�̓ǂݍ���(�X�e�[�W���)
	unique_ptr<wcha_t>_tp; //�X�e�[�W���|�C���^�[
	int size;   //�X�e�[�W���̑傫��
	p = save::ExternalDataOpen(L"", &size); //�O���f�[�^�ǂݍ���

	//block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 9);
}

//���s�����\�b�h
void CSceneMain::Scene()
{

}