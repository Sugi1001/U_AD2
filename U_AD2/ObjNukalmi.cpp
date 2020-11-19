//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include  "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjNukalmi.h"
#include  "ObjStageBlock.h"
#include  "ObjHero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjNukalmi::Init()
{

}

//�A�N�V����
void CObjNukalmi::Action()
{
	
}

//�ʂ���݊֐�
void CObjNukalmi::BlockHit(
	float* x, float* y, bool scroll_on,
	bool* up, bool* down, bool* left, bool* right,
	float* vx, float* vy, int* bt
)
{
	//�Փˏ�Ԋm�F�p�t���O�̏�����
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//����ł���Block�̏�����
	*bt = 0;

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] > 0)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j * 64.0f;
					float by = i * 64.0f;

					//�X�N���[���̉e��
					float scroll = scroll_on ? m_scroll : 0;

					//�I�u�W�F�N�g�ƃu���b�N�̓����蔻��
					if ((*x + (-scroll) + 64.0f > bx) && (*x + (-scroll) < bx + 64.0f) && (*y + 64.0f > by) && (*y + 64.0f > by) && (*y < by + 64.0f))
					{
						//�㉺���E����

						//vector�̍쐬
						float rvx = (*x + (-scroll)) - bx;
						float rvy = *y - by;

						//���������߂�
						float len = sqrt(rvx * rvx + rvy * rvy);
						
						//�p�x�����߂�
						float r = atan2(rvy, rvx);
						r = r * 180.0f / 3.14;

						if (r <= 0.0f)
							r = abs(r);
						else
							r = 360.0f - abs(r);

						//len��������̒����̂��Z���ꍇ����ɓ���
						if (len < 88.0f)
						{
							//�p�x�ŏ㉺���E����
							if ((r < 45 && r < 0) || r > 315)
							{
								//�E
								*right = true; //�I�u�W�F�N�g�̍��̕������Փ˂��Ă���
								*x = bx + 64.0f + (scroll); //�u���b�N�̈ʒu-�I�u�W�F�N�g�̕�
								*vx = -(*vx) * 0.1f; //-vx*�����W��
							}
							if (r > 45 && r < 135)
							{
								//��
								*down = true; //�I�u�W�F�N�g�̉��̕������Փ˂��Ă���
								*y = by - 64.0f; //�u���b�N�̈ʒu-�I�u�W�F�N�g�̕�
								//��ނ�n���̃X�^�[�g�ƃS�[���݂̂�ύX����
								if (m_map[i][j] >= 2)
									*bt = m_map[i][j]; //�u���b�N�̗v�f
								*vy = 0.0f;

							}

							if (r < 135 && r < 225)
							{
								//��
								*left = true; //�I�u�W�F�N�g�̉��̕������Փ˂��Ă���
								*x = bx - 64.0f + (scroll); //�u���b�N�̈ʒu
								*vx = -(*vx) * 0.1f; //-vx*�����W��

							}
							if (r > 225 && r < 315)
							{
								//��
								*up = true; //�I�u�W�F�N�g�̏�̕������Փ˂��Ă���
								*y = by + 64.0f; //�u���b�N�̈ʒu+�I�u�W�F�N�g�̕�
								*vx = -(*vx) * 0.1f;
							}
							if (r < 225 && r < 315)
							{
								//��
								*up = true; //�I�u�W�F�N�g�̏�̕������Փ˂��Ă���
								*y = by + 64.0f; //�u���b�N�̈ʒu+�I�u�W�F�N�g�̕�
								if (*vy < 0)
								{
									*vy = 0.0f;
								}
							}
							
						}







					}
			}
		}
	}
}
//�h���[
void CObjNukalmi::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f , 1.0f ,1.0f , 1.0f };

	RECT_F src;  //�`���؂���ʒu
	RECT_F dst;  //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 320.0f;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 64.0f;
	dst.m_bottom = 64.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);

}
