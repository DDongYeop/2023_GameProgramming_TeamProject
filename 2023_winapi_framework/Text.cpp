#include "pch.h"
#include "Text.h"
#include "pathMgr.h"
#include "SelectGDI.h"
#include <fstream>

Text::Text() 
	: m_Text{}, m_hFont{}, m_hOldFont{}
{
	AddFontResource(TEXT("Galmuri14 Regular.ttf"));
	AddFontResource(TEXT("Orbit Regular.ttf"));
}

Text::~Text()
{
}

void Text::Update()
{
	// update~
}

bool DoesFileExist(const wstring& filePath) 
{
	std::ifstream file(filePath.c_str());
	return file.good();
}

void Text::Render(HDC _dc)
{
	m_hFont = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("Orbit Regular"));

	m_hOldFont = (HFONT)SelectObject(_dc, m_hFont);
	//SelectGDI font(_dc, hFont);

	Vec2 pos = GetPos();
	Vec2 scale = GetScale();
	RECT rt = RECT_MAKE(pos.x, pos.y, scale.x, scale.y);
	DrawText(_dc, m_Text.c_str(), m_Text.length(), &rt, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
	SelectObject(_dc, m_hOldFont);
}
