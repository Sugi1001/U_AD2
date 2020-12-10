//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjTyukan.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTyukan::Init()
{

}

//アクション
void CObjTyukan::Action()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//描画元切り取り
	RECT_F dst;//描画先表示位置

	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 128; j++) {
			if (m_map[i][j] == 6) {
				float x = j * 64.0f;
				float y = i * 64.0f;

				if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f)) {
					float vx = (hx + (-m_scroll)) - x;
					float vy = hy - y;

					float len = sqrt(vx * vx + vy * vy);

					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					if (len < 88.0f) {
						if ((r < 45 && r > 0) || r > 315) {
							hero->SetRight(true);
							hero->SetX(x + 64.0f + (m_scroll));
							hero->SetVX(-hero->GetVX() * 0.1f);
							Draw::Draw(31, &src, &dst, c, 0.0f);
						}
						if (r > 45 && r < 135) {
							hero->SetDown(true);
							hero->SetY(y - 64.0f);
							if (m_map[i][j] >= 6)
								hero->SetBT(m_map[i][j]);
							hero->SetVY(0.0f);
						}
						if (r > 135 && r < 225) {
							hero->SetLeft(true);
							hero->SetX(x - 64.0f + (m_scroll));
							hero->SetVX(-hero->GetVX() * 0.1f);
							Draw::Draw(31, &src, &dst, c, 0.0f);
							(m_map[i][j] == 2) == 6;

						}
						if (r > 255 && r < 315) {
							hero->SetUp(true);
							hero->SetY(y + 64.0f);

							if (hero->GetVY() < 1) {
								hero->SetVY(0.0f);
							}
						}
					}
				}

				else
				{

				}
			}
		}
	}
}

//ドロー
void CObjTyukan::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り
	RECT_F dst;//描画先表示位置


	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			if (m_map[i][j] > 0)
			{

				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;
				
				if (m_map[i][j] == 9)
				{
					src.m_top = 0.0f;
					src.m_left = 320.0f + 64.0;
					src.m_right = src.m_left + 64.0f;
					src.m_bottom = src.m_top + 64.0f;
					Draw::Draw(2, &src, &dst, c, 0.0f);
					//BlockDraw(320.0f, 0.0f, &dst, c);
				}
				else
				{
					Draw(320.0f, 0.0f, &dst, c);
				}

			}
		}
	}

}