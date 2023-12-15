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

	wstring str = L"\n���μ����� �Ϸ�Ǿ����ϴ�.\n�ҿ�� �ð��� ";
	str += std::to_wstring((int)PlayTimeMgr::GetInst()->GetPlayTime());
	str += L"���̸� ���� �ɻ� ����� �ȳ��帮�ڽ��ϴ�.";
	m_pText->AddText(str);
	if (PlayTimeMgr::GetInst()->GetPlayTime() < 300) //�����ߴٸ�
	{
		m_pText->AddText(L"�������� �����Ӹ��̽��Ͱ���б��� �����ϼ�����,\n���� �ɻ� ��� �հ����� �����Ǿ����ϴ�.\n���� ���а����� ���� �ȳ��� ���� ������ �����Դϴ�.");
		m_pText->AddText(L"\n�հ��� ���ϵ帮��,\n�������� �о������� �Ǹ��� ������ �̷�ñ� ����ϰڽ��ϴ�.");
	}
	else
	{
		m_pText->AddText(L"\n�������� �����Ӹ��̽��Ͱ���б��� �����ϼ�����,\n���� �ɻ� ��� ���հ����� �����Ǿ����ϴ�.");
		m_pText->AddText(L"\n�� ������ ���� ���縦 ǥ�ϸ�,\n�������� �������� ����� �Բ��ϱ� �ٶ�ڽ��ϴ�.");
	}
	m_pText->AddText(L"\n�����ϼ̽��ϴ�.");

	AddUI(m_pText, UI_GROUP::TEXT);
	m_fEndTime = 0;
}

void EndScene::Update()
{
	Scene::Update();

	if (m_pText->GetComplete())
	{
		m_fEndTime += fDT;
		if (m_fEndTime >= 2.5f)		// �ڵ����� �������� �ð�
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
