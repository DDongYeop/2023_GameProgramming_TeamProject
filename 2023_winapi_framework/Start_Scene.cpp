#include "pch.h"
#include "Start_Scene.h"
//#include "Object.h"
#include "Core.h"
#include "SceneMgr.h"
#include "TimeMgr.h"
//#include "Player.h"
//#include "Monster.h"
//#include "KeyMgr.h"
//#include "CollisionMgr.h"
//#include "ResMgr.h"

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


void Start_Scene::Init()
{
	SetWindowText(Core::GetInst()->GetHwnd(), L"경기게임마이스터고 입학 프로그램 ver.1.0");

	pText->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, (Core::GetInst()->GetResolution().y / 2) - 25 })));
	pText->SetScale(Vec2(1100, 200));
	pText->AddText(L"\n본 프로그램은 여러분의 능력을 효과적으로 평가하여\n경기게임마이스터고등학교의 입학생을 선별하기 위해 제작되었습니다.");
	pText->AddText(L"\n지원자분들은 제시되는 퍼즐을 풀어 능력을 입증해주십시오.\n행운을 빕니다.");
	pText->AddText(L"1. 입학을 위한 위치 암호를 순서대로 입력해주십시오.");
	pText->AddText(L"STOP");			// 멈추기
	pText->AddText(L"잘하셨습니다.");
	pText->AddText(L"바로 다음단계로 넘어가겠습니다.");
	AddUI(pText, UI_GROUP::TEXT);
}


void Start_Scene::Update()
{
	Scene::Update();

	if (pText->GetStop() && !puzzleSetting) {			// 텍스트가 끝나면
		// 해주고 어쩌고
		Vec2 pos = Vec2({ Core::GetInst()->GetResolution().x / 2, (Core::GetInst()->GetResolution().y / 2) + 50 });
		pInputField1->SetPos(Vec2(pos.x - 300, pos.y));
		pInputField1->SetScale(Vec2(200, 100));
		pInputField1->SetLimit(10);
		pInputField2->SetPos(Vec2(pos.x, pos.y));
		pInputField2->SetScale(Vec2(200, 100));
		pInputField2->SetLimit(10);
		pInputField3->SetPos(Vec2(pos.x +300, pos.y));
		pInputField3->SetScale(Vec2(200, 100));
		pInputField3->SetLimit(10);
		AddUI(pInputField1, UI_GROUP::INPUTFIELD);
		AddUI(pInputField2, UI_GROUP::INPUTFIELD);
		AddUI(pInputField3, UI_GROUP::INPUTFIELD);

		pos = Vec2({ Core::GetInst()->GetResolution().x - 50, Core::GetInst()->GetResolution().y - 90 });
		pHintBtn1->SetPos(Vec2(pos.x, pos.y));
		pHintBtn1->SetScale(Vec2(70, 35));
		pHintBtn1->SetText(L"힌트 1");
		pHintBtn1->SetOpen("https://map.kakao.com/");
		pHintBtn2->SetPos(Vec2(pos.x, pos.y + 50));
		pHintBtn2->SetScale(Vec2(70, 35));
		pHintBtn2->SetText(L"힌트 2");
		pHintBtn2->SetOpen("https://translate.google.com/");
		AddUI(pHintBtn1, UI_GROUP::BUTTON);
		AddUI(pHintBtn2, UI_GROUP::BUTTON);

		puzzleSetting = true;
	}

	if (puzzleSetting && PuzzleCheck()) {
		m_puzzleOk = true;
	}

	if (m_puzzleOk) {
		pText->NoStop();
		pInputField1->Lock();
		pInputField2->Lock();
		pInputField3->Lock();
		if (pText->GetComplete()) {
			time += fDT;
			if (time > 1.5f) {
				//SetWindowText(Core::GetInst()->GetHwnd(), L"게임 클리어 들어옴");
				SceneMgr::GetInst()->LoadScene(L"Puzzle_1");
			}
		}
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

bool Start_Scene::PuzzleCheck()
{
	if ((pInputField1->GetText() == "ROUNDTRIP" && pInputField2->GetText() == "CARD" && pInputField3->GetText() == "TACK")
		|| (pInputField1->GetText() == "ENTITY" && pInputField2->GetText() == "SLEEPY" && pInputField3->GetText() == "FRIENDLY")
		|| (pInputField1->GetText() == "BULGE" && pInputField2->GetText() == "CEILING" && pInputField3->GetText() == "WORK")
		|| (pInputField1->GetText() == "PAUSE" && pInputField2->GetText() == "SUBSCRIBER" && pInputField3->GetText() == "FORGOT")//)
		|| (pInputField1->GetText() == "A" && pInputField2->GetText() == "B" && pInputField3->GetText() == "C"))			// 이 줄 지우기
	{
		return true;
	}
	return false;
}



/*

W3W 사이트 열어주고 경기게임마이스터 고등학교 주소 적어주면 클리어됨.

///왕복.카드.압정
///실체.졸렸다.친근
///부푼.천장.일한
///멈춤.가입자.깜빡

구글 번역 사용
///roundtrip.card.tack
///entity.sleepy.friendly
///bulge.ceiling.work
///Pause.Subscriber.Forgot

*/