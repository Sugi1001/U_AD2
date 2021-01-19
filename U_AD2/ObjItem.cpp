//使用するヘッダファイル
#include"GameL\DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"

#include"GameHead.h"
#include"ObjItem.h"


//使用するネームペース
using namespace GameL;

//イニシャライズ
void CObjItem::Init()
{
	m_time = 0;
	m_flag_time = false;
}

//アクション
void CObjItem::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	if (hero->GetBT() == 2)
	{
		m_flag_time = true;
	}
	else if (hero->GetBT() == 3)
	{
		m_flag_time = false;
	}

	if (m_flag_time == true)
	{
		m_time++;
	}
}

//ドロー
void CObjItem::Draw()
{
	int minute;
	int second;

	second = (m_time / 60) % 60;
	minute = (m_time / 60) / 60;

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	wchar_t str[128];

	if(second<10)
	    swprintf_s(str, L"%d分0%d秒", minute,second);
	else
		swprintf_s(str, L"%d分0%d秒", minute, second);

	Font::StrDraw(str, 10, 10, 20, c);
}





