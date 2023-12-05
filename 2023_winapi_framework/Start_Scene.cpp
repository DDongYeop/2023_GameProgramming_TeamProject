#include "pch.h"
#include "Start_Scene.h"
//#include "Object.h"
#include "Core.h"
//#include "Player.h"
//#include "Monster.h"
//#include "KeyMgr.h"
//#include "CollisionMgr.h"
//#include "ResMgr.h"

#include "UI.h"
#include "Text.h"
#include "InputField.h"

//void Start_Scene::Init()
//{
//	Object* pObj = new Player;
//	pObj->SetPos((Vec2({Core::GetInst()->GetResolution().x /2, Core::GetInst()->GetResolution().y / 2})));
//	pObj->SetScale(Vec2(100.f,100.f));
//	AddObject(pObj, OBJECT_GROUP::PLAYER);
//
//	// 몬스터 세팅 마구마구 배치를 해봅시다.
//
//	Vec2 vResolution = Core::GetInst()->GetResolution();
//	Monster* pMonster = nullptr;
//	int iMonster = 10;		// 몬스터 수 
//	float fMoveDist = 30.f; // 움직일 거리
//	float fMonsterScale = 50.f; // 몬스터 크기
//	// 해상도x - ( 움직일 거리 + 오브젝트 크기 /2) * 2 / 몬스터수 -1 
//	float fTerm = (vResolution.x - (fMoveDist + fMonsterScale / 2.f) * 2) 
//					/ (float)(iMonster -1);
//	for (int i = 0; i < iMonster; ++i)
//	{
//		pMonster = new Monster;
//		pMonster->SetPos(Vec2(
//			(fMoveDist + fMonsterScale / 2.f) + i* fTerm
//			,300.f));
//		pMonster->SetScale(Vec2(fMonsterScale, fMonsterScale));
//		pMonster->SetCenterPos(pMonster->GetPos());
//		pMonster->SetMoveDis(fMoveDist);
//		AddObject(pMonster, OBJECT_GROUP::MONSTER);
//	}
//	// 사운드 세팅
//	ResMgr::GetInst()->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
//	ResMgr::GetInst()->LoadSound(L"Shoot", L"Sound\\laserShoot.wav", false);
//	ResMgr::GetInst()->Play(L"BGM");
//
//	// 충돌체크해야되는것들을 설정하자.
//	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::BULLET, OBJECT_GROUP::MONSTER);
//}
//
//void Start_Scene::Update()
//{
//	Scene::Update();
//	//if(KEY_DOWN(KEY_TYPE::ENTER))
//	//	// 씬 변경
//}
//
//void Start_Scene::Render(HDC _dc)
//{
//	Scene::Render(_dc);
//}
//
//void Start_Scene::Release()
//{
//	Scene::Release();
//	CollisionMgr::GetInst()->CheckReset();
//}

Text* pText = new Text();		// 이거 변수 빼시죵

void Start_Scene::Init()
{
	// 변수 초기화들
	m_puzzleOk = false;


	SetWindowText(Core::GetInst()->GetHwnd(), L"경기게임마이스터고 입학 프로그램 ver.1.0 우엥");

	pText->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	pText->SetScale(Vec2(700, 100));
	pText->AddText(L"안녕하십니까.");
	pText->AddText(L"반갑습니다.");
	pText->AddText(L"안녕히가십시오.");
	AddUI(pText, UI_GROUP::TEXT);


}

		InputField* pInputField = new InputField();
		bool e = false;
void Start_Scene::Update()
{
	Scene::Update();

	if (pText->GetComplete() && !e) {			// 텍스트가 끝나면
		// 해주고 어쩌고
		pInputField->SetPos(Vec2(1000, 200));
		pInputField->SetScale(Vec2(200, 100));
		pInputField->SetLimit(10);
		AddUI(pInputField, UI_GROUP::INPUTFIELD);
		e = true;
		//pText->ReSet();
	}

	if (pInputField->GetText() == "OK") {
		SetWindowText(Core::GetInst()->GetHwnd(), L"헤헤");
		m_puzzleOk = true;
	}

	if (m_puzzleOk) {

	}
}
// 이거 실행 순서에 따라 return 해주면 좋을까? 그래서 배열을 후에 사용하는 것부터 처음에 나오는거지. 좀 생각해보기!

void Start_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Start_Scene::Release()
{
	Scene::Release();
}
