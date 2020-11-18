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
	p = Save::ExternalDataOpen(L"Stage500.csv", &size);//�O���f�[�^�ǂݍ���

	//int map[10][150];
	//int count = 1;
	//for (int i = 0; i < 10; i++)
	int map[10][500];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{
		//for (int j = 0; j < 150; j++)
		for (int j = 0; j < 500; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}
	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���2�j
	/*unique_ptr<wchar_t>a;//�X�e�[�W���|�C���^�[
	int size1;//�X�e�[�W���̑傫��
	//p = Save::ExternalDataOpen(L"test.csv", &size);//�O���f�[�^�ǂݍ���
	a = Save::ExternalDataOpen(L"Stage3.csv", &size1);//�O���f�[�^�ǂݍ���

	//int map[10][150];
	//int count = 1;
	//for (int i = 0; i < 10; i++)
	int map2[10][106];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 106; j++)
		{
			int w = 0;
			swscanf_s(&a.get()[count], L"%d", &w);

			map2[i][j] = w;
			count += 2;
		}
	}

	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t>b;//�X�e�[�W���|�C���^�[
	int size2;//�X�e�[�W���̑傫��
	//p = Save::ExternalDataOpen(L"test.csv", &size);//�O���f�[�^�ǂݍ���
	b = Save::ExternalDataOpen(L"Stage1.csv", &size2);//�O���f�[�^�ǂݍ���

	//int map[10][150];
	//int count = 1;
	//for (int i = 0; i < 10; i++)
	int map3[10][106];
	for (int i = 0; i < 10; i++)
	{
		//for (int j = 0; j < 150; j++)
		for (int j = 0; j < 106; j++)
		{
			int w = 0;
			swscanf_s(&b.get()[count], L"%d", &w);

			map3[i][j] = w;
			count += 2;
		}
	}*/

	////�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"�w�i.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"taitle.png", 10, TEX_SIZE_512);

	//Draw::LoadImage(L"��l��.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"��l���i�ړ��@�t�j.png", 1, TEX_SIZE_512);
	  //Draw::LoadImage(L"��l���i�ړ� �t) .png", 1, TEX_SIZE_512);
   //Draw::LoadImage(L"��l��.png", 1, TEX_SIZE_512);

	//Draw::LoadImage(L"��l���i�ړ��@�t�j.png", 1, TEX_SIZE_512);
	//Draw::LoadImage(L"��l���i�ړ��@�t�j.png", 2, TEX_SIZE_512);

	//Draw::LoadImage(L"�n��.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"�n��.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"�n�ʁi���j(1).png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"��.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"�Ńm�[�}��.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"��������.png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"��������i�ړ��j.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"�Ƃ�1.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"��2.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"�󔠁i�d�v�A�C�e���j.png", 50, TEX_SIZE_512);
	//Draw::LoadImage(L"�n��.png", 2, TEX_SIZE_512);
	//Draw::LoadImage(L"�n��.png", 0, TEX_SIZE_512);


	


	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//block�I�u�W�F�N�g�쐬
	CObjStageBlock* objb = new CObjStageBlock(map);
	Objs::InsertObj(objb, OBJ_STAGE_BLOCK, 2);

	//���I�u�W�F�N�g�쐬
	CObjToge* objt = new CObjToge(); //���I�u�W�F�N�g�쐬
	Objs::InsertObj(objt, OBJ_TOGE, 8);

	//��2�I�u�W�F�N�g�쐬
	CObjEnemyBlock* objeb = new CObjEnemyBlock();
	Objs::InsertObj(objeb, OBJ_ENEMY_BLOCK, 17);

	//��������I�u�W�F�N�g�쐬
	//CObjEnemy* obj_enemy = new CObjEnemy();
	//Objs::InsertObj(obj_enemy, OBJ_ENEMY, 6);

	
	//�^�C�g���w�i�I�u�W�F�N�g�쐬
	//CObjTitle* back = new CObjTitle();
	//Objs::InsertObj(back, OBJ_TITLE, 10);
   
}

//���s�����\�b�h
void CSceneMain::Scene()
{

}