//�r�k�s�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GeamL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL/Audio.h"

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
	Font::SetStrTex(L"�G���^�L�[��������X�^�[�g�Ȃ̂���I�I(*-*)");

	Font::SetStrTex(L"���炷���Ȃ̂���I�I");
	Font::SetStrTex(L"��l���̂��ƂɈŋ����I�I");
	Font::SetStrTex(L"�؂肽���̕ԍς̂��߂ɓ��A�ցI�I");


	//���y���̓ǂݍ���
	Audio::LoadAudio(3, L"BGM Gametitle.wav",BACK_MUSIC);

	//�o�b�N�~���[�W�b�N�X�^�[�g
	float Volume = Audio::VolumeMaster(0.5f); 
	Audio::Start(3); //���y�X�^�[�g

	//�^�C�g���쐬
	CObjTitle* objeo = new CObjTitle();
	Objs::InsertObj(objeo, OBJ_TITLE, 10);

}

//�Q�[�����C�����s���\�b�h
void CSceneTitle::Scene()
{

}

