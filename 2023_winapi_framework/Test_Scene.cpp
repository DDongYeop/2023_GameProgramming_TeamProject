#include "pch.h"
#include "Test_Scene.h"
#include "Object.h"
#include "Core.h"		// �����
#include "Player.h"			// �����

//#include "UI.h"		// ?? �̰� �� ����....?
#include "Text.h"
#include "Button.h"
#include "InputField.h"

void Test_Scene::Init()
{
	Object* pObj = new Player;
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, OBJECT_GROUP::PLAYER);			// �� 4���� �� �����

	//Text* pText = new Text;
	//pText->SetPos(Vec2(300, 100));
	//pText->SetScale(Vec2(400, 100));
	//pText->SetText(L"�ƴ� �̰� ��Ʈ�� ������ �Ȱǰ�?");
	//AddUI(pText, UI_GROUP::TEXT);

	Button* pBtn = new Button;
	pBtn->SetPos(Vec2(100, 300));
	pBtn->SetScale(Vec2(100, 100));
	pBtn->SetOpen("");
	pBtn->SetText(L"��ư");
	AddUI(pBtn, UI_GROUP::BUTTON);

	InputField* pInputField = new InputField;
	pInputField->SetPos(Vec2(1000, 200));
	pInputField->SetScale(Vec2(200, 100));
	pInputField->SetNumber();
	pInputField->SetLimit(10);
	AddUI(pInputField, UI_GROUP::INPUTFIELD);

	int a;
}

void Test_Scene::Update()
{
	Scene::Update();
}

void Test_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Test_Scene::Release()
{
	Scene::Release();
}
