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
	: m_fPrintTime(0.15f), m_fCurrentTime(0.15f), m_sFrontText{}, m_sPrintText{}, m_complete(false)
{
	m_qPrintQueue = std::queue<wstring>();
	//AddFontResource(TEXT("Galmuri14 Regular.ttf"));
	AddFontResource(TEXT("Orbit Regular.ttf"));
}

//Text::Text(float _printTime) 
//	: m_fPrintTime(_printTime), m_fCurrentTime(_printTime), m_sFrontText{}, m_sPrintText{}		// ���� �ϳ� �ٷ� ��µǶ��
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
		m_fPrintTime = 1;		// �� �ϵ� �� �ð��� ������ �����. ���߿� ������ ���� �ǰ�
	}

	if (m_complete) {
		return;
	}

	if (KeyMgr::GetInst()->GetKey(KEY_TYPE::LBUTTON) == KEY_STATE::DOWN)		// ���� ��ư�� ������
	{
		if (m_sPrintText.size() == m_sFrontText.size() && !m_qPrintQueue.empty())		// ���� ����� �Ȱ�����, ���ڰ� �� �־��� �ִٸ�. �׸��� ť�� ������� ������
		{
			m_sFrontText = m_qPrintQueue.front();
			m_sPrintText = L"";
			m_qPrintQueue.pop();
		}
		else
		{
			m_sPrintText = m_sFrontText;			// �ٷ� ���� �� �־���.
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
	if (m_fCurrentTime >= m_fPrintTime)			// ���� �ð��� m_fPrintTime �ð����� ���ų� ũ�� ���� ���.
	{
		m_fCurrentTime -= m_fPrintTime;			// = 0���� ������ذ�

		if (!m_complete) {		// ���ڰ� ������ �ʾ�����
			if (m_sFrontText.size() != 0)		// ���� ������ ����� 0�� �ƴϸ�
			{
				if (m_sPrintText.size() < m_sFrontText.size())			// ������ ���ڰ� �� ������
					m_sPrintText += m_sFrontText[m_sPrintText.size()];		// ����� �ε������� �� �и��ϱ�? ���ڰ� �� ������
			}
			else if (!m_qPrintQueue.empty())		// ������ ����� 0�̰�  ť�� ������� ������, �� ���� ó���� �����̸�
			{
				m_sFrontText = m_qPrintQueue.front();		// ���� �ؽ�Ʈ�� �� ó���� �ִ� ��.
				m_qPrintQueue.pop();		// �׸��� ��.
			}
		}
		else {
			//m_sPrintText = L"";		// ���ڰ� ������.
		}
	}

	HFONT currentFont = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("Orbit Regular"));
	//HFONT currentFont = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("������ DX�θ�ü  Light"));
	//HFONT currentFont = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("Galmuri14 Regular"));
	HFONT oldFont = (HFONT)SelectObject(_dc, currentFont);

	Vec2 pos = GetPos();
	Vec2 scale = GetScale();
	RECT rt = RECT_MAKE(pos.x, pos.y, scale.x, scale.y);
	DrawText(_dc, m_sPrintText.c_str(), m_sPrintText.length(), &rt, DT_VCENTER | DT_CENTER);

	DeleteObject(currentFont);
}

void Text::ReSet(float fPrintTime)
{
	m_fPrintTime = fPrintTime;
	m_fCurrentTime = 0.0f;
	m_qPrintQueue = std::queue<wstring>();
	m_complete = false;
}
