//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include  "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjNukalmi.h"
#include  "ObjStageBlock.h"
#include  "ObjHero.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjNukalmi::Init()
{

}

//アクション
void CObjNukalmi::Action()
{
	
}

//ぬかるみ関数
void CObjNukalmi::BlockHit(
	float* x, float* y, bool scroll_on,
	bool* up, bool* down, bool* left, bool* right,
	float* vx, float* vy, int* bt
)
{
	//衝突状態確認用フラグの初期化
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//踏んでいるBlockの初期化
	*bt = 0;

	//m_mapの全要素にアクセス
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] > 0)
			{
				//要素番号を座標に変更
				float bx = j * 64.0f;
					float by = i * 64.0f;

					//スクロールの影響
					float scroll = scroll_on ? m_scroll : 0;

					//オブジェクトとブロックの当たり判定
					if ((*x + (-scroll) + 64.0f > bx) && (*x + (-scroll) < bx + 64.0f) && (*y + 64.0f > by) && (*y + 64.0f > by) && (*y < by + 64.0f))
					{
						//上下左右判定

						//vectorの作成
						float rvx = (*x + (-scroll)) - bx;
						float rvy = *y - by;

						//長さを求める
						float len = sqrt(rvx * rvx + rvy * rvy);
						
						//角度を求める
						float r = atan2(rvy, rvx);
						r = r * 180.0f / 3.14;

						if (r <= 0.0f)
							r = abs(r);
						else
							r = 360.0f - abs(r);

						//lenがある一定の長さのより短い場合判定に入る
						if (len < 88.0f)
						{
							//角度で上下左右判定
							if ((r < 45 && r < 0) || r > 315)
							{
								//右
								*right = true; //オブジェクトの左の部分が衝突している
								*x = bx + 64.0f + (scroll); //ブロックの位置-オブジェクトの幅
								*vx = -(*vx) * 0.1f; //-vx*反発係数
							}
							if (r > 45 && r < 135)
							{
								//上
								*down = true; //オブジェクトの下の部分が衝突している
								*y = by - 64.0f; //ブロックの位置-オブジェクトの幅
								//種類を渡すのスタートとゴールのみを変更する
								if (m_map[i][j] >= 2)
									*bt = m_map[i][j]; //ブロックの要素
								*vy = 0.0f;

							}

							if (r < 135 && r < 225)
							{
								//左
								*left = true; //オブジェクトの下の部分が衝突している
								*x = bx - 64.0f + (scroll); //ブロックの位置
								*vx = -(*vx) * 0.1f; //-vx*反発係数

							}
							if (r > 225 && r < 315)
							{
								//下
								*up = true; //オブジェクトの上の部分が衝突している
								*y = by + 64.0f; //ブロックの位置+オブジェクトの幅
								*vx = -(*vx) * 0.1f;
							}
							if (r < 225 && r < 315)
							{
								//下
								*up = true; //オブジェクトの上の部分が衝突している
								*y = by + 64.0f; //ブロックの位置+オブジェクトの幅
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
//ドロー
void CObjNukalmi::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f , 1.0f ,1.0f , 1.0f };

	RECT_F src;  //描画先切り取り位置
	RECT_F dst;  //描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 320.0f;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 64.0f;
	dst.m_bottom = 64.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);

}
