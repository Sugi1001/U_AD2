////使用するヘッダーファイル
//#include "GameL\DrawTexture.h"
//#include  "GameL\WinInputs.h"
//#include  "GameL\SceneManager.h"
//#include  "GameL\HitBoxManager.h"
//
//#include "GameHead.h"
//#include  "CObjToge.h"
//
////使用するネームスペース
//using namespace GameL;
//
////イニシャライズ
//void CObjToge::Init()
//{
//
//
//	//当たり判定用のHitBoxを作成
//	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_ENEMY, OBJ_TOGE, 1);
//
//		//HitBoxの位置の変更
//		CHitBox * hit = Hits::GetHitBox(this);
//		hit->SetPos(m_px, m_py);
//
//}
//
////アクション
//void CObjToge::Action()
//{
//	//主人公の位置を取得
//	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
//	float hx = hero->GetX();
//	float hy = hero->GetY();
//
//	//HitBoxの内容を更新
//	CHitBox* Hit = Hits::GetHitBox(this);
//	Hit->SetPos;
//
//
//		//HitBoxの位置の変更
//		HitBox* hit = Hits::GetHitBox(this);
//	    Hit->SetPos(m_px, m_py);
//
//		//主人公と接触したら主人公にダメージ
//		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
//		{
//
//			this->Setstaus(true); //自身に削除命令を出さない。
//
//
//		}
//
//}
//
////ドロー
//void CObjToge::Draw()
//{
//	//描画カラー情報 R=RED G=Green B=Blue A=alpha(透過情報)
//	RECT_F src; //描画元切り取り位置
//	RECT_F dst; //描画先表示位置
//
//	//切り取り位置の設定
//	src.m_top = 0.0f;
//	src.m_left = 126.0f;
//	src.m_right = 96.0f;
//	src.m_bottom = 32.0f;
//
//	//表示位置の設定
//	dst.m_top = 0.0f + m_y;
//	dst.m_left = 0.0f + m_x;
//	dst.m_right = 32.0f + m_x;
//	dst.m_bottom = 32.0f + m_y;
//
//	//0番目に登録したグラフィックをsrc.dst.cの情報を元に描画
//
//
//}
//
