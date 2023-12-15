#include "pch.h"
#include "Puzzle_3.h"
#include "Core.h"
#include "PathMgr.h"
#include "TimeMgr.h"
#include "SceneMgr.h"

void Puzzle_3::Init()
{
	SetWindowText(Core::GetInst()->GetHwnd(), L"�����Ӹ��̽��Ͱ� ���� ���α׷� ver.1.0");

	pText->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, (Core::GetInst()->GetResolution().y / 2) - 75 })));
	pText->SetScale(Vec2(1100, 200));
	pText->AddText(L"4. �ݸ��� ������ �л��� ����� ������ �������� �����ֽ��ϴ�.\n�� �ָ��� Ư�� ��ȣ�� ã�Ƴ��� 4�ڸ��� ��ȣ�� �Է����ֽʽÿ�.");
	pText->AddText(L"STOP");
	pText->AddText(L"���ϼ̽��ϴ�.");
	AddUI(pText, UI_GROUP::TEXT);

}

void Puzzle_3::Update()
{
	Scene::Update();

	if (pText->GetStop() && !m_puzzleSetting) {
		Vec2 pos = Vec2({ Core::GetInst()->GetResolution().x / 2, (Core::GetInst()->GetResolution().y / 2) + 50 });
		pInputField1->SetPos(Vec2(pos.x - 375, pos.y));
		pInputField1->SetScale(Vec2(100, 100));
		pInputField1->SetNumber();
		pInputField1->SetLimit(1);
		pInputField2->SetPos(Vec2(pos.x - 125, pos.y));
		pInputField2->SetScale(Vec2(100, 100));
		pInputField2->SetNumber();
		pInputField2->SetLimit(1);
		pInputField3->SetPos(Vec2(pos.x + 125, pos.y));
		pInputField3->SetScale(Vec2(100, 100));
		pInputField3->SetNumber();
		pInputField3->SetLimit(1);
		pInputField4->SetPos(Vec2(pos.x + 375, pos.y));
		pInputField4->SetScale(Vec2(100, 100));
		pInputField4->SetNumber();
		pInputField4->SetLimit(1);
		AddUI(pInputField1, UI_GROUP::INPUTFIELD);
		AddUI(pInputField2, UI_GROUP::INPUTFIELD);
		AddUI(pInputField3, UI_GROUP::INPUTFIELD);
		AddUI(pInputField4, UI_GROUP::INPUTFIELD);

		pOpenBtn->SetPos(Vec2({ Core::GetInst()->GetResolution().x - 50, Core::GetInst()->GetResolution().y - 35 }));
		pOpenBtn->SetScale(Vec2(70, 35));
		pOpenBtn->SetText(L"�̵�");

		wstring strFilepath = PathMgr::GetInst()->GetResPath();
		strFilepath += L"GGM\\2_Grade";		// 2�г⸸��~
		std::string path;
		path.assign(strFilepath.begin(), strFilepath.end());
		pOpenBtn->SetOpen(path);		// ���� Ž����
		AddUI(pOpenBtn, UI_GROUP::BUTTON);

		m_puzzleSetting = true;
	}

	if (m_puzzleSetting && PuzzleCheck()) {
		m_puzzleOk = true;
		pInputField1->Lock();
		pInputField2->Lock();
		pInputField3->Lock();
		pInputField4->Lock();		// �ϳ��� �� ������ �ٷ� ǥ���ϰ� �����ֱ�? �� �׷� �ֵ��� ��ڱ���, �׷� �� �Է��ϸ� ǥ�ð� �ǰ� ���ֱ�!
		//�ڿ� �� �ʷϻ� �׸� ����ٰų�. �� �¹��� Ǯ���� �Ҹ��� �鸰�ٰų�
	}

	if (m_puzzleOk) {
		pText->NoStop();
		if (pText->GetComplete()) {
			time += fDT;
			if (time > 1.5f) {
				SceneMgr::GetInst()->LoadScene(L"EndScene");
			}
		}
	}

}

void Puzzle_3::Render(HDC _dc)
{
	Scene::Render(_dc);

}

void Puzzle_3::Release()
{
	Scene::Release();

}

bool Puzzle_3::PuzzleCheck()			// 2024 �ΰ�?
{
	if (pInputField1->GetText() == "2" && pInputField2->GetText() == "0" && pInputField3->GetText() == "2" && pInputField4->GetText() == "4") {
		return true;
	}
	return false;
}
