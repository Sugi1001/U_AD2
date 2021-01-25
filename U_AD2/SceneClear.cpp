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
#include"SceneClear.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneClear::CSceneClear()
{

}

//�f�X�g���N�^
CSceneClear::~CSceneClear()
{

}

//���������\�b�h
void CSceneClear::InitScene()
{
	Font::SetStrTex(L"�N���A���߂łƂ��I�I");
	Font::SetStrTex(L"����Ŏ�l���̎؋��������ɕԍςł��邾�낤");
	Font::SetStrTex(L"�������A�؋��������Ȃ��Ƃ������ĂȂ�����");
	Font::SetStrTex(L"��l���̂��`���琶���͑����Ă�����̂��낤��!!");
	Font::SetStrTex(L"�Ō�܂Ńv���C���Ă����������肪�Ƃ��������܂���");


	//���y���̓ǂݎ��
	Audio::LoadAudio(1, L"BGM Gameclear.wav", BACK_MUSIC);

	//�o�b�N�~���[�W�b�N�X�^�[�g
	float v = Audio::VolumeMaster(1); 
	v = Audio::VolumeMaster(1.0 - v);
	Audio::Start(1); //���y�X�^�[�g

	//�N���A�I�u�W�F�N�g�쐬
	CObjClear* obj = new CObjClear();
	Objs::InsertObj(obj, OBJ_CLEAR, 1);
}

//���s�����\�b�h
void CSceneClear::Scene()
{

}