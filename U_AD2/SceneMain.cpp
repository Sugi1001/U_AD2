//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include"GameL/DrawFont.h"
#include"GameL/UserData.h"
#include "ObjStageBlock.h"


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
	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t>p;//�X�e�[�W���|�C���^�[
	int size;//�X�e�[�W���̑傫��
	//p = Save::ExternalDataOpen(L"test.csv", &size);//�O���f�[�^�ǂݍ���
	p = Save::ExternalDataOpen(L"stag.csv", &size);//�O���f�[�^�ǂݍ���

	//int map[10][150];
	//int count = 1;
	//for (int i = 0; i < 10; i++)
	int map[10][106];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{
		//for (int j = 0; j < 150; j++)
		for (int j = 0; j < 106; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}


	////�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"�w�i.png", 0, TEX_SIZE_512);

	////Draw::LoadImage(L"��l��.png", 1, TEX_SIZE_512);
	//Draw::LoadImage(L"��l���i�ړ��@�t�j.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"��l���i�ړ��@�t�j.png", 1, TEX_SIZE_512);
	//Draw::LoadImage(L"��l��.png", 10, TEX_SIZE_512);
	Draw::LoadImage(L"�A���_�[�A�h�x���`���[", 10, TEX_SIZE_512);
	//Draw::LoadImage(L"��l���i�ړ��@�t�j.png", 1, TEX_SIZE_512);
	//Draw::LoadImage(L"��l���i�ړ��@�t�j.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"�A���_�[�A�h�x���`���[.png", 10, TEX_SIZE_512);
	//Draw::LoadImage(L"�n��.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"�n��.png", 2, TEX_SIZE_512);
	//Draw::LoadImage(L"�n��.png", 2, TEX_SIZE_512);
	//Draw::LoadImage(L"�n��.png", 0, TEX_SIZE_512);


	


	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//block�I�u�W�F�N�g�쐬
	CObjStageBlock* objb = new CObjStageBlock(map);
	Objs::InsertObj(objb, OBJ_STAGE_BLOCK, 2);

	

   

}

//���s�����\�b�h
void CSceneMain::Scene()
{

}