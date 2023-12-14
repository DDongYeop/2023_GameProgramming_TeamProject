#include "pch.h"
#include "Intro.h"
#include "Texture.h"
#include "ResMgr.h"
#include "GGM_Logo.h"

void Intro::Init()
{
	m_fOpacity = 0.0f;
	m_Bf.BlendOp = AC_SRC_OVER;
	m_Bf.BlendFlags = 0;
	m_Bf.SourceConstantAlpha = 100;
	m_Bf.AlphaFormat = AC_SRC_ALPHA;

	GGM_Logo* ggmLogo = new GGM_Logo();
	ggmLogo->SetPos(Vec2(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
	ggmLogo->SetScale(Vec2(842, 595));
	AddObject(ggmLogo, OBJECT_GROUP::GGM_LOGO);
}

void Intro::Update()
{
	Scene::Update();
}

void Intro::Render(HDC _dc)
{
	Scene::Render(_dc);

	//Texture* pTex = ResMgr::GetInst()->TexLoad(L"GGM_Logo", L"Texture\\GGM_Logo.bmp");
}

void Intro::Release()
{
	Scene::Release();
}
