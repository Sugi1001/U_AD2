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
	Font::SetStrTex(L"���߂łƂ��I");

	//���y���̓ǂݎ��
	//Audio::LoadAudio(0, L"BGMGameClear.wav", BACK_MUSIC);

	//�o�b�N�~���[�W�b�N�X�^�[�g
	//float v = Audio::VolumeMaster(0); //�}�X�^�[�{�����[����0.8������
	//v = Audio::VolumeMaster(1.0 - v);
	//Audio::Start(0); //���y�X�^�[�g

	//�N���A�I�u�W�F�N�g�쐬
	//ObjGameClear* obj = new ObjGameClear();
	//Objs::InsertObj(obj, OBJ_CLEAR, 10);
}

//���s�����\�b�h
void CSceneClear::Scene()
{

}