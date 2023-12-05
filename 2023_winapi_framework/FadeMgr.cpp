#include "pch.h"
#include "FadeMgr.h"
#include "TimeMgr.h"
#include "Core.h"
#include "KeyMgr.h"
#define IDB_BITMAP1 101 

void FadeMgr::Init()
{
	m_fOpacity = 0.0f; 
	m_iFade = 0;
	_bf.BlendOp = AC_SRC_OVER;
	_bf.BlendFlags = 0;
	_bf.SourceConstantAlpha = 100;
	_bf.AlphaFormat = AC_SRC_ALPHA;

}

void FadeMgr::Update()
{
	m_fOpacity += fDT * m_iFade * 100;
	m_fOpacity = std::clamp(m_fOpacity, 0.0f, 255.0f);
}

void FadeMgr::Render(HDC _dc, HINSTANCE _instance)
{
	_bf.SourceConstantAlpha = m_fOpacity;
	HBITMAP _memBitmap;
	POINT tResolution = Core::GetInst()->GetResolution();
	HDC _memDC = CreateCompatibleDC(_dc);
	_memBitmap = CreateCompatibleBitmap(_dc, tResolution.x, tResolution.y);
	SelectObject(_memDC, _memBitmap);
	
	// 오브젝트의 텍스처의 dc를 가져와서 얘를 제외하고 alphablend를 해야돼.
	BitBlt(_dc, 0, 0, tResolution.x, tResolution.y, _memDC, 0, 0, SRCCOPY);
	AlphaBlend(_memDC, 0, 0, tResolution.x, tResolution.y, _dc, 0, 0, tResolution.x, tResolution.y, _bf);

	DeleteObject(_memBitmap);
	DeleteDC(_memDC);
}

/// <summary>
/// Fade In, Out을 관리할 Method
/// </summary>
/// <param name="value">true == IN, false == Out</param>
void FadeMgr::Fade(bool value)
{
	if (value)
		m_iFade = 1;
	else
		m_iFade = -1;
}