//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"

#include"GameHead.h"
#include"StageBlock.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBlock::Init()
{
	//マップ情報
	int block_date[10][10] =
	{
		{1,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
	    {0,0,0,0,0,0,0,0,0,0},
	    {0,0,0,0,0,0,0,0,0,0},
	    {0,0,0,0,0,0,0,0,0,0},
	    {0,0,0,0,0,0,0,0,0,0},
	    {1,1,1,1,1,1,1,1,1,1},

	};
	//マップデータをコピー
	memcpy(m_map, block_date, sizeof(int)*(10 * 10));
}
//アクション
void CObjBlock::Action()
{

}
//ドロー
void CObjBlock::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り
}