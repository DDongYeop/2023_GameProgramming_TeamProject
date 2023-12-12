#include "pch.h"
#include "define.h"
#include "Text.h"
#include "pathMgr.h"
//#include "SelectGDI.h"
#include "TimeMgr.h"
#include "KeyMgr.h"
#include "Core.h"
//#include <fstream>
#include <queue>

Text::Text() 
	: m_fPrintTime(0.1f), m_fCurrentTime(0.1f), m_sFrontText{}, m_sPrintText{}, m_complete(false)
	, m_stop(false)
{
	m_qPrintQueue = std::queue<wstring>();
	//AddFontResource(TEXT("Galmuri14 Regular.ttf"));
	AddFontResource(TEXT("Orbit Regular.ttf"));
}

//Text::Text(float _printTime) 
//	: m_fPrintTime(_printTime), m_fCurrentTime(_printTime), m_sFrontText{}, m_sPrintText{}		// 글자 하나 바로 출력되라고
//{
//	m_qPrintQueue = std::queue<wstring>();
//	//AddFontResource(TEXT("Font\\Galmuri14 Regular.ttf"));
//	AddFontResource(TEXT("Font\\Orbit Regular.ttf"));
//}

Text::~Text()
{
}

void Text::Update()
{
	m_fCurrentTime += fDT;

	if (m_qPrintQueue.empty() && m_sPrintText == m_sFrontText && !m_complete) {
		m_complete = true;
		m_fCurrentTime = 0.0f;
		//m_fPrintTime = 1;		// 뭘 하든 이 시간이 지나야 사라짐. 나중에 변수로 빼도 되고
	}

	if (m_complete) {
		return;
	}

	if (KeyMgr::GetInst()->GetKey(KEY_TYPE::LBUTTON) == KEY_STATE::DOWN)		// 왼쪽 버튼이 눌리면
	{
		if (m_sPrintText.size() == m_sFrontText.size() && !m_qPrintQueue.empty() && !m_stop)		// 만약 사이즈가 똑같으면, 글자가 다 넣어져 있다면. 그리고 큐가 비어있지 않으면
		{
			m_sFrontText = m_qPrintQueue.front();
			m_sPrintText = L"";
			m_qPrintQueue.pop();
		}
		else
		{
			m_sPrintText = m_sFrontText;			// 바로 글자 다 넣어줌.
			if (!m_qPrintQueue.empty() && m_qPrintQueue.front() == L"STOP")		// 만약 다음것이 스탑이면
			{
				m_stop = true;
				m_qPrintQueue.pop();
			}
		}

	}
}

//bool DoesFileExist(const wstring& filePath) 
//{
//	std::ifstream file(filePath.c_str());
//	return file.good();
//}

void Text::Render(HDC _dc)
{
	if (m_fCurrentTime >= m_fPrintTime)			// 현제 시간이 m_fPrintTime 시간보다 같거나 크면 글자 출력.
	{
		m_fCurrentTime -= m_fPrintTime;			// = 0으로 만들어준거

		if (!m_complete) {		// 글자가 끝나지 않았으면
			if (m_sFrontText.size() != 0)		// 현재 글자의 사이즈가 0이 아니면
			{
				if (m_sPrintText.size() < m_sFrontText.size())			// 지금의 글자가 더 많으면
					m_sPrintText += m_sFrontText[m_sPrintText.size()];		// 사이즈가 인덱스보다 더 밀리니까? 글자가 더 나와짐
				
				if (m_sPrintText == m_sFrontText) {
					if (!m_qPrintQueue.empty() && m_qPrintQueue.front() == L"STOP")		// 만약 다음것이 스탑이면
					{
						m_stop = true;
						m_qPrintQueue.pop();
					}
				}
			}
			else if (!m_qPrintQueue.empty())		// 글자의 사이즈가 0이고  큐가 비어있지 않으면, 즉 가장 처음의 글자이면
			{
				m_sFrontText = m_qPrintQueue.front();		// 현제 텍스트는 멘 처음에 있는 것.
				m_qPrintQueue.pop();		// 그리고 팝.
			}
		}
		else {
			//m_sPrintText = L"";		// 글자가 끝났어.
		}
	}

	HFONT currentFont = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("Orbit Regular"));
	//HFONT currentFont = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("엘리스 DX널리체  Light"));
	//HFONT currentFont = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("Galmuri14 Regular"));
	HFONT oldFont = (HFONT)SelectObject(_dc, currentFont);

	Vec2 pos = GetPos();
	Vec2 scale = GetScale();
	RECT rt = RECT_MAKE(pos.x, pos.y, scale.x, scale.y);
	DrawText(_dc, m_sPrintText.c_str(), m_sPrintText.length(), &rt, DT_VCENTER | DT_CENTER);

	DeleteObject(currentFont);
}

void Text::ReSet()
{
	m_fCurrentTime = 0.1f;
	//m_sFrontText = {};
	//m_sPrintText = {};
	m_qPrintQueue = std::queue<wstring>();
	m_complete = false;
}
