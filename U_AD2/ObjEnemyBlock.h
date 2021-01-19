#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g : �v���W�F�N�g&�w�i
class CObjEnemyBlock : public CObj
{
public :
	CObjEnemyBlock() {};
	~CObjEnemyBlock() {};
	void Init();  //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[
	
private:
	float m_px;  //�ʒu
	float m_py;   //�ړ��x�N�g��
	float m_vx;
	float m_vy;  //�p��
	float m_posture;
	float m_x;
	float m_y;
	float m_stop_flag;
	/*int m_block_type;*/
	int GetMap(int x, int y);
	void SetMap(int x, int y, int id);

	float GetX() { return m_px; }
	float GetY() { return m_py; }

	int m_ani_time;  //�A�j���[�V�����t���[������Ԋu
	int m_ani_frame; //�`��t���[��
	int m_map[10][10] = { 0 };

	float m_speed_power; //�X�s�[�h�p���[
	float m_ani_max_time; //�A�j���[�V��������Ԋu�ő�l

	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
	int m_stop_map_y;//�����ĂȂ����̃}�b�v�ʒuX�ԍ�
	int m_stop_map_x;//�����ĂȂ����̃}�b�v�ʒuY�ԍ�


};

