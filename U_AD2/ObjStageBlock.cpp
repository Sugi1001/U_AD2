//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"ObjStageBlock.h"
#include"GameL\DrawFont.h"


//使用するネームスペース
using namespace GameL;
CObjStageBlock::CObjStageBlock(int map[10][500])
	{
		//{1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1},
		//{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
		//{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1},
	    //{1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1,1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
	    //{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1,1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1},
	    //{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1,1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1,1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
	    //{1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1,1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	    //{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1},
	    //{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	    //{1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1,1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1,1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 3, 1},
	  
	   
	  //マップデータをコピー
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 500; j++) {
			m_map[i][j] = map[i][j];
		}
	}
	memcpy(m_map,map, sizeof(int)*(10 * 500));
	
	};
	
//イニシャライズ
void CObjStageBlock::Init()
{
	m_scroll = 0.0f;

	//マップ情報
	//int map[10][150] =
	
	
}
//アクション
void CObjStageBlock::Action()
{
	
	

	

	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	
	//主人公衝突判定
	//hero->SetUp(false);
	//hero->SetDown(false);
	//hero->SetLeft(false);
	//hero->SetRight(false);
	//後方スクロールライン
	if (hx < 0)
	{
		hero->SetX(80);//主人公はラインを超えないようにする
		SetScroll(hero->GetVX());
		m_scroll += hero->GetScroll();//主人公が本来動くべき分の値をm_scrollに加える

		
	}
	//前方スクロールライン
	if (hx > 800){
		hero->SetX(800);
		SetScroll((hero->GetVX())-(hero->GetVX()*2));
		m_scroll -= hero->GetScroll()*2;

               

	}
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 500; j++) {
			if (m_map[i][j] > 0) {
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
						}
						if (r > 45 && r < 135) {
							hero->SetDown(true);
							hero->SetY(y - 64.0f);
							if (m_map[i][j] >= 2)
								hero->SetBT(m_map[i][j]);
							hero->SetVY(0.0f);
						}
						if (r > 135 && r < 225) {
							hero->SetLeft(true);
							hero->SetX(x - 64.0f + (m_scroll));
							hero->SetVX(-hero->GetVX() * 0.1f);
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
			}
			else if (m_map[i][j] == 3)
			{

			}
		}
	}
	
	//テスト　交差取得
	//float a, b;
	//LineCrossPoint(0, 0, 10, 10, 0, 5, 10, 5, &a, &b);
	//int aa = 0;
	//aa++;
}

	

//ドロー
void CObjStageBlock::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り
	RECT_F dst;//描画先表示位置

	 //背景表示
	src.m_top = 256.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	

	Draw::Draw(0, &src, &dst, c, 0.0f);
	
	//マップチップによるblock設置
//切り取り位置の設定
//src.m_top =0.0f;
//src.m_left=320.0f;
//src.m_right=src.m_left+64.0f;
//src.m_bottom=64.0f;

    m_scroll-=2.0f;//スクロール実験用

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j<500; j++)
		{
			if (m_map[i][j] > 0)
			{

				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f+ m_scroll;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;
				if (m_map[i][j]==2)
				{
					//スタートブロック
					src.m_top =0.0f;
                    src.m_left=320.0f+64.0;
                    src.m_right=src.m_left+64.0f;
                    src.m_bottom=src.m_top+64.0f;
					Draw::Draw(2,&src,&dst,c,0.0f);
				}
				else if (m_map[i][j] == 3)
				{
					//ゴールブロック
					src.m_top = 0.0f;
					src.m_left = 320.0f + 64.0;
					src.m_right = src.m_left + 64.0f;
					src.m_bottom = src.m_top + 64.0f;
					Draw::Draw(2, &src, &dst, c, 0.0f);
					//BlockDraw(320.0f + 64.0f, 64.0f, &dst, c);
					//Scene::SetScene((new CSceneGameClear()));
					/*if (ObjHero != nullptr)
					{
						Scene::SetScene((new CSceneClear()));
					};*/
				}
				else if (m_map[i][j] == 4)
				{
					src.m_top = 0.0f;
					src.m_left = 320.0f + 64.0;
					src.m_right = src.m_left + 64.0f;
					src.m_bottom = src.m_top + 64.0f;
					Draw::Draw(50, &src, &dst, c, 0.0f);
					//BlockDraw(320.0f + 64.0f, 64.0f, &dst, c);//宝
					
				}
				else if (m_map[i][j] == 5)
				{
					//	氷
					src.m_top = 0.0f;
					src.m_left = 320.0f + 64.0;
					src.m_right = src.m_left + 64.0f;
					src.m_bottom = src.m_top + 64.0f;
					Draw::Draw(20, &src, &dst, c, 0.0f);
                    //摩擦
					//m_vx += +(m_vx * 0.098);

					//BlockDraw(320.0f, 0.0f, &dst, c);
				}
				else if (m_map[i][j] == 6)
				{
					//棘
					src.m_top = 0.0f;
					src.m_left = 320.0f + 64.0;
					src.m_right = src.m_left + 64.0f;
					src.m_bottom = src.m_top + 64.0f;
					Draw::Draw(8, &src, &dst, c, 0.0f);
					//BlockDraw(320.0f, 0.0f, &dst, c);
				}
				else if(m_map[i][j] == 7)
				{
					src.m_top = 0.0f;
					src.m_left = 320.0f + 64.0;
					src.m_right = src.m_left + 64.0f;
					src.m_bottom = src.m_top + 64.0f;
					Draw::Draw(30, &src, &dst, c, 0.0f);
					//BlockDraw(320.0f, 0.0f, &dst, c);
				}
				else
				{
					BlockDraw(320.0f, 0.0f, &dst, c);
				}
				
			}
		}
	}
}
//BlockDrawMethod関数
//引数１ float    x  :リソース切り替え位置x
//引数２ float    y  :リソース切り替え位置y
//引数３ RECT_F* dst :描画位置
//引数４ float    c  :カラー情報
//ブロックを64*64限定描画用。リソース切り替えのみx.yで
//設定できる
   void CObjStageBlock::BlockDraw(float x, float y, RECT_F* dst, float c[])
   {
	RECT_F src;
	src.m_top = 0;
	src.m_left = 0;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = src.m_top + 64.0f;

	
	//描画
	Draw::Draw(2, &src, dst, c, 0.0f);
   }
   void CObjStageBlock::BlockDraw1(float x, float y, RECT_F* dst, float c[])
   {
	   RECT_F src;
	   src.m_top = 0;
	   src.m_left = 0;
	   src.m_right = src.m_left + 64.0f;
	   src.m_bottom = src.m_top + 64.0f;


	   //描画
	   Draw::Draw(50, &src, dst, c, 0.0f);
   }
   //BlockHit関数
//引数１ float* x       :判定を行うobjectのx位置
//引数２ float* y       :判定を行うobjectのy位置
//引数３ bool  scroll_on:判定を行うobjectはスクロールの影響与えるかどうか（true=与える false=与えない)
//引数４ bool* up       :上下左右判定の上部分に当たっているかどうかを返す
//引数５ bool* down     :上下左右判定の下部分に当たっているかどうかを返す
//引数６ bool* left     :上下左右判定の左部分に当たっているかどうかを返す
//引数７ bool* right    :上下左右判定の右部分に当たっているかどうかを返す
//引数８ float* vx      :左右判定時の反発による移動方向・力の値変えて返す
//引数９ float* vy      :上下判定時による自由落下運動の移動方向・力の値変えて返す
//引数10 int* bt        :下部分判定、特殊なブロックのタイプを返す
//判定を行うobjectとブロック50*50限定で、あたり判定と上下左右判定を行う
//その結果は引数４～１０に返す
   void CObjStageBlock::BlockHit(float *x, float *y, bool scroll_on, bool*up, bool* down, bool *left, bool* right, float* vx, float *vy, int* bt)
   {
	   //主人公の衝突状態確認用フラグの初期化
	   *up=false;
	   *down=false;
	   *left=false;
	   *right=false;
	   //踏んでいるブロックの種類の初期化
	   *bt=0;

	   //m_mapの全要素にアクセス
	   for (int i = 0; i < 10; i++)
	   {
		   for (int j = 0; j < 500; j++)
		   {
			   if (m_map[i][j] > 0)
			   {
				   //要素番号を座標に変更
				   float bx = j * 64.0f;
				   float by = i * 64.0f;
				   //スクロールの影響
				   float scroll = scroll_on ? m_scroll :0;

				   //主人公とブロックの当たり判定
				   if (( *x + (-scroll) + 64.0f > bx) && (*x + (-scroll) < bx + 64.0f) && (*y + 64.0f > by) && (*y < by + 64.0f))
				   {
					   //上下左右の判定

					   //vectorの作成
					   float rvx = (*x + (-scroll)) - bx;
					   float rvy = *y - by;
					   //長さを求める
					   float len = sqrt(rvx*rvx + rvy * rvy);
					   //角度を求める
					   float r = atan2(rvy, rvx);
					   r = r * 180.0f / 3.14f;

					   if (r <= 0.0f)
						   r = abs(r);
					   else
						   r = 360.0f - abs(r);

					   //lenがある一定の長さのより短い場合判定に入る
					   if (len < 88.0f)
					   {
						   //角度で上下左右を判定
						   if ((r < 45 && r>0) || r > 315)
						   {
							   //右
							   *right=true;//主人公から見て、左の部分が衝突している
							   *x=bx + 64.0f + (scroll);//ブロックの位置＋主人公の幅
							   *vx=-(*vx)*0.1f;//VX*反発係数
						   }
						   if (r > 45 && r < 135)
						   {
							   //上
							   *down=true;//主人公から見て、下の部分が衝突している
							   *y=by - 64.0f;//ブロックの位置ー主人公の幅
							   //種類を渡すのスタートとゴールのみ変更する
							   if (m_map[i][j] >= 2)
								   *bt=m_map[i][j];//ブロックの要素（type）を主人公に渡す
							   *vy=0.0f;
						   }
						   if (r > 135 && r < 225)
						   {
							   //左
							   *left=true;//主人公から見て、右の部分が衝突している
							   *x=bx - 64.0f + (scroll);//ブロックの位置ー主人公の幅
							   *vx=-(*vx)*0.1f;//-VX*反発係数
						   }
						   if (r > 225 && r < 315)
						   {
							   //下
							   *up=true;//主人公から見て、上の部分が衝突している
							   *y=by + 64.0f;//ブロックの位置＋主人公の幅
							   if (*vy < 0)
							   {
								   *vy=0.0f;
							   }
						   }



						   //当たってる場合
						   //hero->SetX(hx);
						   //hero->SetY(0.0f);
						   //hero->SetVY(0.0f);
					   }
				   }
			   }
		   }
	   }
   }

   //内積関数
   //引数１，２float ax,ay:Aベクトル
   //引数３，４float bx,by:Bベクトル
   //戻り値　float:射影
   //内容　AベクトルとBベクトルで内積を行い射影をもとめる
   float CObjStageBlock::Dot(float ax, float ay, float bx, float by)
   {
	   float t = 0.0f;

	   t = ax * bx + ay * by;

	   return t;
   }

   //外積関数
   //引数１，２float ax,ay:Aベクトル
   //引数３，４float bx,by:Bベクトル
   //戻り値　float :射影
   //内容　AベクトルとBベクトルで外積を行い射影をもとめる
   float CObjStageBlock::Cross(float ax, float ay, float bx, float by)
   {
	   float t = 0.0f;

	   t = ax * by + ay * bx;

	   return t;
   }

   //符号を求めるマクロ
#define SGN(x) 1-(x<=0)-(x<0)

   //線と線と交差判定
   bool CObjStageBlock::LineCrossPoint(float a1x, float a1y, float a2x, float a2y, float b1x, float b1y, float b2x, float b2y, float* out_px, float* out_py)
   {
	   //エラーコード
	   *out_px = -99999.0f; *out_py = -99999.0f;

	   //Aベクトル作成（a2←a1）
	   float ax = a2x - a1x;  float ay = a2y - a1y;

	   //Bベクトル作成（b2←b1）
	   float bx = b2x - b1x;  float by = b2y - b1y;

	   //Cベクトル作成（b1←a1）
	   float cx = b1x - a1x;  float cy = b1y - a1y;

	   //Dベクトル作成
	   float dx = b2x - a1x;  float dy = b2y - a1y;

	   //A＊Cの射影とA*Bの射影を求める
	   float t1 = Cross(ax, ay, cx, cy);
	   float t2 = Cross(ax, ay, dx, dy);

	   //符号が同じ方向になっているかどうかチェック
	   if (SGN(t1) == SGN(t2))
		   return false;//交点なし

	   //射影を絶対値化
	   t1 = abs(t1); t2 = abs(t2);

	   //交点を求める
	   float px = bx * (t1 / (t1 + t2)) + b1x;
	   float py = by * (t1 / (t1 + t2)) + b1x;


	   //APベクトル（p←a1）
	   float apx = px - a1x;   float apy = py - a1y;

	   //BPベクトル（p←a2）
	   float bpx = px - a2x;  float bpy = py - a2y;

	   //A.APの射影とA.BPの射影を求める
	   float w1 = Dot(ax, ay, apx, apy);
	   float w2 = Dot(ax, ay, bpx, bpy);

	   //符号チェック
	   if (SGN(w1) == SGN(w2))
		   return false;//交点が外

	   //交点を返す
	   *out_px = px; *out_py;

	   return true;
   
   }
//ブロックとの当たり判定実行
	//CObjStageBlock::CObjStageBlock* pb = (CObjStageBlock*)Objs::GetObj(OBJ_STAGE_BLOCK);
   //主人公と壁の交差判定関数
   bool CObjStageBlock::HeroBlockCrossPoint(float x, float y, float vx, float vy, float *out_px, float *out_py, float *out_len)
   {
	   bool pb = false;//交差確認用
	   float len = 99999.0f;//交点との距離
	   //ブロックの辺ベクトル
	   float edge[4][4]=
	   {
		   {0,0,64,0},//上辺
	       {64,0,64,64},//右辺
	       {64,64,0,64},//下辺
	       {0,64,0,0},//左辺
	   };

	   //m_mapの全要素アクセス
	   for (int i = 0; i < 10; i++)
	   {
		   for (int j = 0; j < 500; j++)
		   {
			   if (m_map[i][j] > 0 && m_map[i][j] != 4)
			   {
				   //ブロックの４辺から交点を探す
				   for (int k = 0; k < 4; k++)
				   {
					   //交点を探す
					   float px, py;
					   bool b;
					   float l = 0.0f;
					   b = LineCrossPoint(x, y, x + vx, y + vy, j * 64 + edge[k][0], i * 64 + edge[k][1],j*64+edge[k][2],i*64+edge[k][3], &px, &py);
					   //交点チェック
					   if (b == true)
					   {
						   //交点との距離を求める
						   l = sqrt((px - x)*(px - x) + (py - y)*(py - y));

						   //見つけた交差の中でも最も距離が短いモノを探す
						   if (len > l)
						   {
							   len = l;
							   *out_px = px;
							   *out_py = py;
							   pb = true;
						   }
					   }
				   }
			   }
		   }
	   }
	   *out_len = len;
	   return pb;
   }


