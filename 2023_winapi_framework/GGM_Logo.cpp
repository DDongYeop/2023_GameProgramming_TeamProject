#include "pch.h"
#include "GGM_Logo.h"
#include "Texture.h"
#include "ResMgr.h"
#include "Core.h"
#include "FadeMgr.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "PlayTimeMgr.h"

GGM_Logo::GGM_Logo() 
{
	m_fFadeValue = 0;
	m_fOpacity = 100;
	m_Bf.BlendOp = AC_SRC_OVER;
	m_Bf.BlendFlags = 0;
	m_Bf.AlphaFormat = AC_SRC_ALPHA;
	m_Bf.SourceConstantAlpha = 100;

	m_pTex = ResMgr::GetInst()->TexLoad(L"GGM_Logo", L"Texture\\GGM_Logo.bmp");
	m_fFadeValue = 350;
}

GGM_Logo::~GGM_Logo()
{
}

void GGM_Logo::Update()
{
	m_fFadeValue -= fDT * 100;
	FadeMgr::GetInst()->Update(m_fFadeValue);

	if (m_fFadeValue <= -75)
	{
		FadeMgr::GetInst()->Update(255);
		PlayTimeMgr::GetInst()->TimerStart();
		SceneMgr::GetInst()->LoadScene(L"Start_Scene");
	}
}

void GGM_Logo::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	TransparentBlt(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, Width, Height, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));

	FadeMgr::GetInst()->Render(_dc);
}
