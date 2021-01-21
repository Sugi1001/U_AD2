//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include"GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p����w�b�_�[
#include "SceneGameOver1.h"
#include "GameHead.h"

//�R���g���N�^
CSceneGameOver1::CSceneGameOver1()
{

}

//�f�X�g���N�^
CSceneGameOver1::~CSceneGameOver1()
{

}

//���������\�b�h
void CSceneGameOver1::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"GameOver�@�Q�`���I�`�o�`");

	Font::SetStrTex(L"���߂�ȁI");
	Font::SetStrTex(L"���߂Ȃ���΂����ƃS�[���͌����Ă���");
	Font::SetStrTex(L"���x�ł��`�������W�����!");

	Font::SetStrTex(L"ENTER_KEY�Ń^�C�g���ɖ߂��");

	Font::SetStrTex(L"���x���N���A�ł��Ȃ��ꍇ�͗����������߂ɋx�e���͂��݂܂��傤");
	Font::SetStrTex(L"�̒��ʂȂǂ�������ƍl���ăv���C�𑱂��܂��傤");



	//���y���̓ǂݍ���
	Audio::LoadAudio(2, L"BGM Gameover.wav", BACK_MUSIC);

	float v = Audio::VolumeMaster(2);
	v = Audio::VolumeMaster((0.4 - v));
	Audio::Start(2); //���y�X�^�[�g

	//�Q�[���I�[�o�[�I�u�W�F�N�g�쐬
	CObjGameOver1* obj = new CObjGameOver1();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 11);
}

//���s�����\�b�h
void CSceneGameOver1::Scene()
{

}