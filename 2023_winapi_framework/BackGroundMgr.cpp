#include "pch.h"
#include "BackGroundMgr.h"

void BackGroundMgr::Render(HDC _dc)
{
	HBRUSH hBrush = CreateSolidBrush(m_cColor);
	HBRUSH oldBrush = (HBRUSH)SelectObject(_dc, hBrush);
	Rectangle(_dc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(_dc, oldBrush);
	DeleteObject(hBrush);
}

void BackGroundMgr::SetColor(COLORREF color)
{
	m_cColor = color;
}
