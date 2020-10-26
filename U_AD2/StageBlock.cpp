//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"

#include"GameHead.h"
#include"StageBlock.h"
#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBlock::Init()
{
	m_scroll = 0.0f;

	//�}�b�v���
	int block_date[10][100] =
	{
	 {1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	 {1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	 {1,2,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1},
	 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	 {1,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1},
	};
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, block_date, sizeof(int) = (10 * 100));
}
//�A�N�V����
void CObjBlock::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//����X�N���[�����C��
	if (hx < 80)
	{
		hero->SetX(80);//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= hero->GetVX();//��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}
	//�O���X�N���[�����C��
	if (hx > 300)
	{
		hero->SetX(300);//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= hero->GetVX();//��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}
	//�e�X�g�@�����擾
	//float a, b;
	//LineCrossPoint(0, 0, 10, 10, 0, 5, 10, 5, &a, &b);
	//int aa = 0;
	//aa++;
}
	

//�h���[
void CObjBlock::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���
	RECT_F dst;//�`���\���ʒu

	 //�w�i�\��
	src.m_top = 256.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);
	//�}�b�v�`�b�v�ɂ��block�ݒu

//�؂���ʒu�̐ݒ�
//src.m_top =0.0f;
//src.m_left=320.0f;
//src.m_right=src.m_left+64.0f;
//src.m_bottom=64.0f;

//m_scroll-=3.0f;//�X�N���[�������p

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j, 100; j++)
		{
			if (m_map[i][j] > 0)
			{

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;
				if (m_map[i][j] == 2)
				{
					//�X�^�[�g�u���b�N
					BlockDraw(320.0f + 64.0f, 0.0f, &dst, c);
				}
				else if (m_map[i][j] == 3)
				{
					//�S�[���u���b�N
					BlockDraw(320.0f + 64.0f, 64.0f, &dst, c);
				}
				else if (m_map[i][j])
				{
					;//�G�z�u�p�̔ԍ��̂��߉������Ȃ�
				}
				else
				{
					BlockDraw(320.0f, 0.0f, &dst, c);
				}
			}
		}
	}
}
//BlockDrawMethod�֐�
//�����P float    x  :���\�[�X�؂�ւ��ʒux
//�����Q float    y  :���\�[�X�؂�ւ��ʒuy
//�����R RECT_F* dst :�`��ʒu
//�����S float    c  :�J���[���
//�u���b�N��64*64����`��p�B���\�[�X�؂�ւ��̂�x.y��
//�ݒ�ł���
   void CObjBlock::BlockDraw(float x, float y, RECT_F* dst, float c[])
   {
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = src.m_top + 64.0f;
	//�`��
	Draw::Draw(0, &src, dst, c, 0.0f);
   }
   //BlockHit�֐�
//�����P float* x       :������s��object��x�ʒu
//�����Q float* y       :������s��object��y�ʒu
//�����R bool  scroll_on:������s��object�̓X�N���[���̉e���^���邩�ǂ����itrue=�^���� false=�^���Ȃ�)
//�����S bool* up       :�㉺���E����̏㕔���ɓ������Ă��邩�ǂ�����Ԃ�
//�����T bool* down     :�㉺���E����̉������ɓ������Ă��邩�ǂ�����Ԃ�
//�����U bool* left     :�㉺���E����̍������ɓ������Ă��邩�ǂ�����Ԃ�
//�����V bool* right    :�㉺���E����̉E�����ɓ������Ă��邩�ǂ�����Ԃ�
//�����W float* vx      :���E���莞�̔����ɂ��ړ������E�͂̒l�ς��ĕԂ�
//�����X float* vy      :�㉺���莞�ɂ�鎩�R�����^���̈ړ������E�͂̒l�ς��ĕԂ�
//����10 int* bt        :����������A����ȃu���b�N�̃^�C�v��Ԃ�
//������s��object�ƃu���b�N50*50����ŁA�����蔻��Ə㉺���E������s��
//���̌��ʂ͈����S�`�P�O�ɕԂ�
   void CObjBlock::BlockHit(float *x, float *y, bool scroll_on, bool*up, bool* down, bool *left, bool* right, float* vx, float *vy, int* bt)
   {
	   //��l���̏Փˏ�Ԋm�F�p�t���O�̏�����
	   *up=false;
	   *down=false;
	   *left=false;
	   *right=false;

	   //����ł���u���b�N�̎�ނ̏�����
	   *bt=0;

	   //m_map�̑S�v�f�ɃA�N�Z�X
	   for (int i = 0; i < 10; i++)
	   {
		   for (int j = 0; j < 10; j++)
		   {
			   if (m_map[i][j] > 0&&m_map[i][j]!=4)
			   {
				   //�v�f�ԍ������W�ɕύX
				   float bx = j * 64.0f;
				   float by = i * 64.0f;

				   //�X�N���[���̉e��
				   float scroll = scroll_on ? m_scroll : 0;

				   //��l���ƃu���b�N�̓����蔻��
				   if ((*x + (-scroll) + 64.0f > bx) && (*x + (-scroll) < bx + 64.0f) && (*y + 64.0f > by) && (*y < by + 64.0f))
				   {
					   //�㉺���E�̔���

					   //vector�̍쐬
					   float rvx = (*x + (-m_scroll)) - bx;
					   float rvy = *y - by;
					   //���������߂�
					   float len = sqrt(rvx*rvx + rvy + rvy);
					   //�p�x�����߂�
					   float r = atan2(rvy, rvx);
					   r = r * 180.0f / 3.14f;

					   if (r <= 0.0f)
						   r = abs(r);
					   else
						   r = 360.0f - abs(r);

					   //len��������̒����̂��Z���ꍇ����ɓ���
					   if (len < 88.0f)
					   {
						   //�p�x�ŏ㉺���E�𔻒�
						   if ((r < 45 && r>0) || r > 315)
						   {
							   //�E
							   *right=true;//��l�����猩�āA���̕������Փ˂��Ă���
							   *x=bx + 64.0f + (scroll);//�u���b�N�̈ʒu�{��l���̕�
							   *vx=-(*vx)*0.1f;//VX*�����W��
						   }
						   if (r > 45 && r < 135)
						   {
							   //��
							   *down=true;//��l�����猩�āA���̕������Փ˂��Ă���
							   *y=by - 64.0f;//�u���b�N�̈ʒu�[��l���̕�
							   //��ނ�n���̃X�^�[�g�ƃS�[���̂ݕύX����
							   if (m_map[i][j] >= 2)
								   *bt=m_map[i][j];//�u���b�N�̗v�f�itype�j����l���ɓn��
							   *vy=0.0f;
						   }
						   if (r > 135 && r < 225)
						   {
							   //��
							   *left=true;//��l�����猩�āA�E�̕������Փ˂��Ă���
							   *x=bx - 64.0f + (scroll);//�u���b�N�̈ʒu�[��l���̕�
							   *vx=-(*vx)*0.1f;//-VX*�����W��
						   }
						   if (r > 225 && r < 315)
						   {
							   //��
							   *up=true;//��l�����猩�āA��̕������Փ˂��Ă���
							   *y=by + 64.0f;//�u���b�N�̈ʒu�{��l���̕�
							   if (*vy < 0)
							   {
								   *vy=0.0f;
							   }
						   }



						   //�������Ă�ꍇ
						   //hero->SetX(hx);
						   //hero->SetY(0.0f);
						   //hero->SetVY(0.0f);
					   }
				   }
			   }
		   }
	   };
   }

   //���ϊ֐�
   //�����P�C�Qfloat ax,ay:A�x�N�g��
   //�����R�C�Sfloat bx,by:B�x�N�g��
   //�߂�l�@float:�ˉe
   //���e�@A�x�N�g����B�x�N�g���œ��ς��s���ˉe�����Ƃ߂�
   float CObjBlock::Dot(float ax, float ay, float bx, float by)
   {
	   float t = 0.0f;

	   t = ax * bx + ay * by;

	   return t;
   }

   //�O�ϊ֐�
   //�����P�C�Qfloat ax,ay:A�x�N�g��
   //�����R�C�Sfloat bx,by:B�x�N�g��
   //�߂�l�@float :�ˉe
   //���e�@A�x�N�g����B�x�N�g���ŊO�ς��s���ˉe�����Ƃ߂�
   float CObjBlock::Cross(float ax, float ay, float bx, float by)
   {
	   float t = 0.0f;

	   t = ax * by + ay * bx;

	   return t;
   }

   //���������߂�}�N��
#define SGN(x) 1-(x<=0)-(x<0)

   //���Ɛ��ƌ�������
   bool CObjBlock::LineCrossPoint(float a1x, float a1y, float a2x, float a2y, float b1x, float b1y, float b2x, float b2y, float* out_px, float* out_py)
   {
	   //�G���[�R�[�h
	   *out_px = -99999.0f; *out_py = -99999.0f;

	   //A�x�N�g���쐬�ia2��a1�j
	   float ax = a2x - a1x;  float ay = a2y - a1y;

	   //B�x�N�g���쐬�ib2��b1�j
	   float bx = b2x - b1x;  float by = b2y - b1y;

	   //C�x�N�g���쐬�ib1��a1�j
	   float cx = b1x - a1x;  float cy = b1y - a1y;

	   //D�x�N�g���쐬
	   float dx = b2x - a1x;  float dy = b2y - a1y;

	   //A��C�̎ˉe��A*B�̎ˉe�����߂�
	   float t1 = Cross(ax, ay, cx, cy);
	   float t2 = Cross(ax, ay, dx, dy);

	   //���������������ɂȂ��Ă��邩�ǂ����`�F�b�N
	   if (SGN(t1) == SGN(t2))
		   return false;//��_�Ȃ�

	   //�ˉe���Βl��
	   t1 = abs(t1); t2 = abs(t2);

	   //��_�����߂�
	   float px = bx * (t1 / (t1 + t2)) + b1x;
	   float py = by * (t1 / (t1 + t2)) + b1x;


	   //AP�x�N�g���ip��a1�j
	   float apx = px - a1x;   float apy = py - a1y;

	   //BP�x�N�g���ip��a2�j
	   float bpx = px - a2x;  float bpy = py - a2y;

	   //A.AP�̎ˉe��A.BP�̎ˉe�����߂�
	   float w1 = Dot(ax, ay, apx, apy);
	   float w2 = Dot(ax, ay, bpx, bpy);

	   //�����`�F�b�N
	   if (SGN(w1) == SGN(w2))
		   return false;//��_���O

	   //��_��Ԃ�
	   *out_px = px; *out_py;

	   return true;
   
   }


