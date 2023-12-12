#include "pch.h"
#include "Puzzle_1.h"
#include "Core.h"
#include "TimeMgr.h"
#include "KeyMgr.h"

#include "UI.h"
#include "InputField.h"

float m_fCurrentTime, m_fPrintTime;
wstring m_title, m_nowText;
bool m_textOk;		// ���� �ؽ�Ʈ�� �Է����� true ��.
vector<InputField*> m_inputFields;

void Puzzle_1::Init()
{
	m_fCurrentTime = 0.1f;
	m_fPrintTime = 0.1f;
	m_textOk = false;

	m_title = L"2. GMAE�� ã�Ƽ� �����ּ���.";
	m_nowText = L"";
	//LPWSTR title = "dfdf";
	//SetWindowText(Core::GetInst()->GetHwnd(), m_title.c_str());

}

int a = 0;

void Puzzle_1::Update()
{
	Scene::Update();

	if (!m_textOk) {
		m_fCurrentTime += fDT;

		if (m_fCurrentTime >= m_fPrintTime) {
			m_fCurrentTime -= m_fPrintTime;

			if (m_nowText.size() < m_title.size()) {
				m_nowText += m_title[m_nowText.size()];
			}
			else {
				m_textOk = true;
			}
			SetWindowText(Core::GetInst()->GetHwnd(), m_nowText.c_str());
		}
	}

	if (KeyMgr::GetInst()->GetKey(KEY_TYPE::LBUTTON) == KEY_STATE::DOWN) 
	{
		a++;
		SetWindowText(Core::GetInst()->GetHwnd(), std::to_wstring(a).c_str());

		// ��� ��ǲ �ʵ��� useThis �� ���ֱ�. �ѹ� ���� ��.
		for (int i = 0; i < m_inputFields.size(); i++)
		{
			m_inputFields[i]->Lock();
		}

		// ��ǲ �ʵ� ������
		InputField* pInputField = new InputField();
		pInputField->SetPos(Vec2({ KeyMgr::GetInst()->GetMousePos().x, KeyMgr::GetInst()->GetMousePos().y }));
		pInputField->SetScale(Vec2(150, 50));
		pInputField->SetLimit(10);
		pInputField->SetFocus();
		pInputField->ShowRECT(false);
		AddUI(pInputField, UI_GROUP::INPUTFIELD);
		m_inputFields.push_back(pInputField);
	}
}

void Puzzle_1::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Puzzle_1::Release()
{
	Scene::Release();
}
