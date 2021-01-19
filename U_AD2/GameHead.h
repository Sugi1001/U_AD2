#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_ENEMY_BLOCK,
	OBJ_ENEMY,
	OBJ_TOGE,
	OBJ_HERO,
	OBJ_YAMIKIN,
	OBJ_BULLET,
	//OBJ_HP,
	//OBJ_BLOCK,
	OBJ_STAGE_BLOCK,
	OBJ_STAGE_BLOCK1,
	OBJ_FINAL_STAGE,
	OBJ_BLOCK,
	OBJ_ITEM,

	OBJ_TITLE,
	OBJ_GAME_OVER,
	OBJ_CLEAR,
	OBJ_NUKALMI,
	OBJ_TIME,
	OBJ_TYUKAN,
	//OBJ_BACKGROUND,
	OBJ_GAME_SOUSA,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_YAMIKIN,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "ObjHero.h"
#include"yamikin.h"
#include"ObjStageBlock.h"
#include"ObjStageBlock1.h"
#include "ObjEnemyBlock.h"
#include"ObjFinalStage.h"
#include  "CObjToge.h"
#include  "ObjNukalmi.h"
#include "ObjTime.h"
//#include "GameL/Audio.h"
#include "ObjItem.h"
//#include"ObjEnemy.h"
#include"Bullet.h"


#include "ObjTitle.h"
#include"ObjGameOver.h"
#include"ObjGameClear.h"
#include"ObjGameClear1.h"
#include"ObjStageClea1.h"
#include"ObjGameSousa.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include"SceneTitle.h"
#include "SceneMain.h"
#include "SceneMain1.h"
#include "SceneMain2.h"
#include"SceneGameOver.h"
#include"SceneClear.h"
#include"SceneStageClea1.h"
#include"SceneStageClea2.h"
#include"SceneGameSousa.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START  CSceneTitle
//-----------------------------------------------