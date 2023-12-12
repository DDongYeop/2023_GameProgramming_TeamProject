#include "pch.h"
#include "Start_Scene.h"
//#include "Object.h"
#include "Core.h"
#include "SceneMgr.h"
//#include "Player.h"
//#include "Monster.h"
//#include "KeyMgr.h"
//#include "CollisionMgr.h"
//#include "ResMgr.h"

#include "UI.h"
#include "Text.h"
#include "InputField.h"
#include "Button.h"

//void Start_Scene::Init()
//{
//	Object* pObj = new Player;
//	pObj->SetPos((Vec2({Core::GetInst()->GetResolution().x /2, Core::GetInst()->GetResolution().y / 2})));
//	pObj->SetScale(Vec2(100.f,100.f));
//	AddObject(pObj, OBJECT_GROUP::PLAYER);
//
//	// ���� ���� �������� ��ġ�� �غ��ô�.
//
//	Vec2 vResolution = Core::GetInst()->GetResolution();
//	Monster* pMonster = nullptr;
//	int iMonster = 10;		// ���� �� 
//	float fMoveDist = 30.f; // ������ �Ÿ�
//	float fMonsterScale = 50.f; // ���� ũ��
//	// �ػ�x - ( ������ �Ÿ� + ������Ʈ ũ�� /2) * 2 / ���ͼ� -1 
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
//	// ���� ����
//	ResMgr::GetInst()->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
//	ResMgr::GetInst()->LoadSound(L"Shoot", L"Sound\\laserShoot.wav", false);
//	ResMgr::GetInst()->Play(L"BGM");
//
//	// �浹üũ�ؾߵǴ°͵��� ��������.
//	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::BULLET, OBJECT_GROUP::MONSTER);
//}
//
//void Start_Scene::Update()
//{
//	Scene::Update();
//	//if(KEY_DOWN(KEY_TYPE::ENTER))
//	//	// �� ����
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

Text* pText = new Text();		// �̰� ���� ������
InputField* pInputField1 = new InputField();
InputField* pInputField2 = new InputField();
InputField* pInputField3 = new InputField();
Button* pHintBtn1 = new Button();
Button* pHintBtn2 = new Button();
bool puzzleSetting = false;

void Start_Scene::Init()
{
	// ���� �ʱ�ȭ��
	m_puzzleOk = false;


	SetWindowText(Core::GetInst()->GetHwnd(), L"�����Ӹ��̽��Ͱ� ���� ���α׷� ver.1.0 �쿨");

	pText->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, (Core::GetInst()->GetResolution().y / 2) - 50 })));
	pText->SetScale(Vec2(1100, 200));
	pText->AddText(L"\n�� ���α׷��� �������� �ɷ��� ȿ�������� ���Ͽ�\n�����Ӹ��̽��Ͱ���б��� ���л��� �����ϱ� ���� ���۵Ǿ����ϴ�.");
	pText->AddText(L"\n�����ںе��� ������ ������ Ǯ�� �ɷ��� �������ֽʽÿ�.\n����� ���ϴ�.");
	pText->AddText(L"1. ������ ���� ��ġ ��ȣ�� ������� �Է����ֽʽÿ�.");
	AddUI(pText, UI_GROUP::TEXT);

	//Vec2 pos = Vec2({ Core::GetInst()->GetResolution().x - 50, Core::GetInst()->GetResolution().y - 90});
	//pHintBtn1->SetPos(Vec2(pos.x, pos.y));
	//pHintBtn1->SetScale(Vec2(70, 35));
	//pHintBtn1->SetText(L"��Ʈ 1");
	//pHintBtn1->SetOpen("https://map.kakao.com/");
	//AddUI(pHintBtn1, UI_GROUP::BUTTON);
	//pHintBtn2->SetPos(Vec2(pos.x, pos.y + 50));
	//pHintBtn2->SetScale(Vec2(70, 35));
	//pHintBtn2->SetText(L"��Ʈ 2");
	//pHintBtn2->SetOpen("https://map.kakao.com/");
	//AddUI(pHintBtn2, UI_GROUP::BUTTON);
}


void Start_Scene::Update()
{
	Scene::Update();

	if (pText->GetComplete() && !puzzleSetting) {			// �ؽ�Ʈ�� ������
		// ���ְ� ��¼��
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
		pHintBtn1->SetText(L"��Ʈ 1");
		pHintBtn1->SetOpen("https://map.kakao.com/");
		pHintBtn2->SetPos(Vec2(pos.x, pos.y + 50));
		pHintBtn2->SetScale(Vec2(70, 35));
		pHintBtn2->SetText(L"��Ʈ 2");
		pHintBtn2->SetOpen("https://translate.google.com/");
		AddUI(pHintBtn1, UI_GROUP::BUTTON);
		AddUI(pHintBtn2, UI_GROUP::BUTTON);

		puzzleSetting = true;
	}

	if (puzzleSetting && PuzzleCheck()) {
		m_puzzleOk = true;
	}

	if (m_puzzleOk) {

		SceneMgr::GetInst()->LoadScene(L"Test_Scene");
		//SetWindowText(Core::GetInst()->GetHwnd(), L"Ŭ����!");

	}
}
// �̰� ���� ������ ���� return ���ָ� ������? �׷��� �迭�� �Ŀ� ����ϴ� �ͺ��� ó���� �����°���. �� �����غ���!

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
		|| (pInputField1->GetText() == "PAUSE" && pInputField2->GetText() == "SUBSCRIBER" && pInputField3->GetText() == "FORGOT"))
	{
		return true;
	}
	return false;
}



/*

W3W ����Ʈ �����ְ� �����Ӹ��̽��� ����б� �ּ� �����ָ� Ŭ�����.

///�պ�.ī��.����
///��ü.���ȴ�.ģ��
///��Ǭ.õ��.����
///����.������.����

���� ���� ���
///roundtrip.card.tack
///entity.sleepy.friendly
///bulge.ceiling.work
///Pause.Subscriber.Forgot

*/