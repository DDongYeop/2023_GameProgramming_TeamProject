#include "pch.h"
#include "define.h"
#include "Text.h"
#include "pathMgr.h"
#include "SelectGDI.h"
#include "TimeMgr.h"
#include "KeyMgr.h"
#include <fstream>
#include <queue>

Text::Text() 
	: m_iPrintIndex(0), m_fPrintTime(0.15f), m_fCurrentTime(0), m_sFrontText{}, m_sPrintText{}
{
	m_qPrintQueue = std::queue<wstring>();
	AddFontResource(TEXT("Galmuri14 Regular.ttf"));
	AddFontResource(TEXT("Orbit Regular.ttf"));
}

Text::Text(float _printTime) 
	: m_iPrintIndex(0), m_fPrintTime(_printTime), m_fCurrentTime(0), m_sFrontText{}, m_sPrintText{}
{
	m_qPrintQueue = std::queue<wstring>();
	AddFontResource(TEXT("Font\\Galmuri14 Regular.ttf"));
	AddFontResource(TEXT("Font\\Orbit Regular.ttf"));
}

Text::~Text()
{
}

void Text::Update()
{
	m_fCurrentTime += fDT;

	if (KeyMgr::GetInst()->GetKey(KEY_TYPE::SPACE) == KEY_STATE::DOWN)
	{
		if (m_sPrintText.size() == m_sFrontText.size())
		{
			m_sFrontText = m_qPrintQueue.front();
			m_qPrintQueue.pop();
		}
		else
		{
			m_sPrintText = m_sFrontText;
		}
	}
}

bool DoesFileExist(const wstring& filePath) 
{
	std::ifstream file(filePath.c_str());
	return file.good();
}

void Text::Render(HDC _dc)
{
	if (m_fCurrentTime >= m_fPrintTime)
	{
		m_fCurrentTime -= m_fPrintTime;
		if (m_sFrontText.size() != 0)
		{
			if (m_sPrintText.size() < m_sFrontText.size())
				m_sPrintText += m_sFrontText[m_sPrintText.size()];
		}
		else if (!m_qPrintQueue.empty())
		{
			m_sFrontText = m_qPrintQueue.front();
			m_qPrintQueue.pop();
		}

	}
	HFONT currentFont = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("Orbit Regular"));
	HFONT oldFont = (HFONT)SelectObject(_dc, currentFont);

	Vec2 pos = GetPos();
	Vec2 scale = GetScale();
	RECT rt = RECT_MAKE(pos.x, pos.y, scale.x, scale.y);
	DrawText(_dc, m_sPrintText.c_str(), m_sPrintText.length(), &rt, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
	SelectObject(_dc, oldFont);
}
