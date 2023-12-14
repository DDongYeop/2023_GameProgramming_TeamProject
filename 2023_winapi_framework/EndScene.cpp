#include "pch.h"
#include "EndScene.h"
#include "PlayTimeMgr.h"
#include "TimeMgr.h"
#include "Text.h"
#include "Core.h"
#include <stdlib.h>

void EndScene::Init()
{
	PlayTimeMgr::GetInst()->TimerEnd();
	m_pText = new Text;

	m_pText->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, (Core::GetInst()->GetResolution().y / 2) })));
	m_pText->SetScale(Vec2(1100, 200));

	wstring str = L"   프로세스가 완료되었습니다.\n소요된 시간은 ";
	str += std::to_wstring((int)PlayTimeMgr::GetInst()->GetPlayTime());
	str += L"초이며 최종 심사 결과를 안내드리겠습니다.";
	m_pText->AddText(str);
	if (PlayTimeMgr::GetInst()->GetPlayTime() < 300) //성공했다면
	{
		m_pText->AddText(L"여러분은 경기게임마이스터고등학교에 지원하셨으며,\n최종 심사 결과 합격으로 결정되었습니다.\n향후 입학과정에 관한 안내는 추후 제공될 예정입니다.");
		m_pText->AddText(L"합격을 축하드리며,\n앞으로의 학업에서도 훌륭한 성과를 이루시길 기대하겠습니다.");
	}
	else
	{
		m_pText->AddText(L"여러분은 경기게임마이스터고등학교에 지원하셨으며,\n최종 심사 결과 불합격으로 결정되었습니다.");
		m_pText->AddText(L"그 동안의 수고에 대한 감사를 표하며,\n앞으로의 도전에서 행운이 함께하길 바라겠습니다.");
	}
	m_pText->AddText(L"수고하셨습니다.");

	AddUI(m_pText, UI_GROUP::TEXT);
	m_fEndTime = 0;
}

void EndScene::Update()
{
	Scene::Update();

	if (m_pText->GetComplete())
	{
		m_fEndTime += fDT;
		if (m_fEndTime >= 1)
			exit(0);
	}
}

void EndScene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void EndScene::Release()
{
	Scene::Release();
}
