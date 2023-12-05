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

void Start_Scene::Init()
{
	// ���� �ʱ�ȭ��
	m_puzzleOk = false;


	SetWindowText(Core::GetInst()->GetHwnd(), L"�����Ӹ��̽��Ͱ� ���� ���α׷� ver.1.0 �쿨");

	pText->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	pText->SetScale(Vec2(700, 100));
	pText->AddText(L"�ȳ��Ͻʴϱ�.");
	pText->AddText(L"�ݰ����ϴ�.");
	pText->AddText(L"�ȳ������ʽÿ�.");
	AddUI(pText, UI_GROUP::TEXT);


}

		InputField* pInputField = new InputField();
		bool e = false;
void Start_Scene::Update()
{
	Scene::Update();

	if (pText->GetComplete() && !e) {			// �ؽ�Ʈ�� ������
		// ���ְ� ��¼��
		pInputField->SetPos(Vec2(1000, 200));
		pInputField->SetScale(Vec2(200, 100));
		pInputField->SetLimit(10);
		AddUI(pInputField, UI_GROUP::INPUTFIELD);
		e = true;
		//pText->ReSet();
	}

	if (pInputField->GetText() == "OK") {
		SetWindowText(Core::GetInst()->GetHwnd(), L"����");
		m_puzzleOk = true;
	}

	if (m_puzzleOk) {

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
