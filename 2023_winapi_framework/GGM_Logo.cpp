#include "pch.h"
#include "GGM_Logo.h"
#include "Texture.h"
#include "ResMgr.h"

GGM_Logo::GGM_Logo() 
{
	m_fOpacity = 100;
	m_Bf.BlendOp = AC_SRC_OVER;
	m_Bf.BlendFlags = 0;
	m_Bf.SourceConstantAlpha = m_fOpacity;
	m_Bf.AlphaFormat = AC_SRC_ALPHA;

	m_pTex = ResMgr::GetInst()->TexLoad(L"GGM_Logo", L"Texture\\GGM_Logo.bmp");
}

GGM_Logo::~GGM_Logo()
{
}

void GGM_Logo::Update()
{
}

void GGM_Logo::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();
	/*AlphaBlend(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, Width, Height, m_pTex->GetDC()
		, 0, 0, Width, Height, m_Bf);*/
	TransparentBlt(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, Width, Height, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));
	//Component_Render(_dc);
}
