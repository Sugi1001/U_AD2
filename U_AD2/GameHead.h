#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_ENEMY_BLOCK,
	OBJ_ENEMY,
	OBJ_TOGE,
	OBJ_HERO,
	//OBJ_HP,
	//OBJ_BLOCK,
	OBJ_STAGE_BLOCK,
	OBJ_BLOCK,

	OBJ_TITLE,
	OBJ_GAME_OVER,
	OBJ_CLEAR,
	OBJ_NUKALMI,
	OBJ_TIME,
	//OBJ_BACKGROUND,
};
//------------------------------------------------

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int mSeveData;	//�T���v���Z�[�u�f�[�^
	
};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--



//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
#include "ObjHero.h"
#include"ObjStageBlock.h"
#include "ObjEnemyBlock.h"

#include  "CObjToge.h"
#include  "ObjNukalmi.h"
#include   "ObjTime.h"
//#include "GameL/Audio.h"
//#include "ObjItem.h"
//#include"ObjEnemy.h"


#include "ObjTitle.h"
#include"ObjGameOver.h"
#include"ObjGameClear.h"

//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include"SceneTitle.h"
#include "SceneMain.h"
#include"SceneGameOver.h"
#include"SceneClear.h"
//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START  CSceneTitle
//-----------------------------------------------