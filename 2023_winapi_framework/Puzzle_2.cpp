#include "pch.h"
#include "Puzzle_2.h"
#include "FileMgr.h"
#include "Core.h"
//#include "SelectGDI.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "PathMgr.h"

void Puzzle_2::Init()
{
	m_puzzleOk = false;
	m_time = 0.0f;
	m_changeSceneTime = 1.5f;

	SetWindowText(Core::GetInst()->GetHwnd(), L"경기게임마이스터고 입학 프로그램 ver.1.0");

	pText->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, (Core::GetInst()->GetResolution().y / 2) + 25 })));
	//pText->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	pText->SetScale(Vec2(1100, 200));
	pText->AddText(L"3. 시험장의 위치는 2학년 2반입니다.\n이동하여 불을 켜주십시오.");
	pText->AddText(L"STOP");
	pText->AddText(L"잘하셨습니다.");
	AddUI(pText, UI_GROUP::TEXT);

}

void Puzzle_2::Update()
{
	Scene::Update();

	if (pText->GetStop() && !m_btnOk) {		// 버튼 생성
		pButton->SetPos(Vec2({ Core::GetInst()->GetResolution().x - 50, Core::GetInst()->GetResolution().y - 35 }));
		pButton->SetScale(Vec2(70, 35));
		pButton->SetText(L"이동");

		wstring strFilepath = PathMgr::GetInst()->GetResPath();
		strFilepath += L"GGM";
		std::string path;
		path.assign(strFilepath.begin(), strFilepath.end());
		pButton->SetOpen(path);		// 파일 탐색기
		AddUI(pButton, UI_GROUP::BUTTON);
		m_btnOk = true;
	}

	wstring path = L"GGM\\2_Grade\\Class_2\\";		// 위에꺼랑 변수 합치기
	wstring name = L"Light";
	if (FileMgr::GetInst()->Exist(path, name) && !m_puzzleOk)
	{
		//씬이동
		m_puzzleOk = true;
		pText->NoStop();
	}

	if (m_puzzleOk && pText->GetComplete()) {
		m_time += fDT;
		if (m_time > m_changeSceneTime) {
			SceneMgr::GetInst()->LoadScene(L"Puzzle_3");
		}
	}
}

void Puzzle_2::Render(HDC _dc)
{
	// 배경 그려주기 큰 렉텡글 만들어서 ㅎㅎ
	//HBRUSH brush = CreateSolidBrush(BLACK_BRUSH);
	//SelectGDI brush(_dc, BRUSH_TYPE::RED);
	//HBRUSH oldBrush = (HBRUSH)SelectObject(_dc, brush);
	//RECT_RENDER(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2, Core::GetInst()->GetResolution().x, Core::GetInst()->GetResolution().y, _dc);
	//SelectGDI dbrush(_dc, BRUSH_TYPE::YELLOW);
	//DeleteObject(brush);


	Scene::Render(_dc);
}

void Puzzle_2::Release()
{
	Scene::Release();
}