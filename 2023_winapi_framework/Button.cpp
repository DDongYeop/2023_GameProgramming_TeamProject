#include "pch.h"
#include "Button.h"
#include "KeyMgr.h"
#include "OpenMgr.h"
#include "Core.h"

Button::Button()
	: m_clickable(false)
	, m_clickBtn(false)
	, m_open(false)
	, m_link{}
{
	AddFontResource(TEXT("Orbit Regular.ttf"));
}

Button::~Button()
{
}

void Button::Update()
{
	if (m_useThis) {
		// if ���콺�� �������� �ٲ��ֱ� �� Ŭ���� ������ ��¼��~
		Vec2 pos = GetPos();
		Vec2 scale = GetScale();
		RECT rt = RECT_MAKE(pos.x, pos.y, scale.x, scale.y);
		POINT mousePos = KeyMgr::GetInst()->GetMousePos();
		if ((mousePos.x > rt.left && mousePos.x < rt.right) && (mousePos.y > rt.top && mousePos.y < rt.bottom)) {
			m_clickable = true;
			if (KEY_DOWN(KEY_TYPE::LBUTTON)) {
				//m_Text = L"����";
				m_clickBtn = true;
				//SetWindowText(Core::GetInst()->GetHwnd(), L"��ư ����");
				if (m_open) {
					OpenMgr::GetInst()->Open(m_link);
				}
			}
		}
		else {
			m_clickable = false;
			m_clickBtn = false;
			//m_Text = L"��ư";
			//SetWindowText(Core::GetInst()->GetHwnd(), L"��ư �ȵ���");
		}

		if (KEY_UP(KEY_TYPE::LBUTTON)) {
			m_clickBtn = false;
		}
	}
}

void Button::Render(HDC _dc)
{
	HFONT currentFont = CreateFont(20, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("Orbit Regular"));
	HFONT oldFont = (HFONT)SelectObject(_dc, currentFont);

	// if (m_Clickable) {// �� ��¼�� �ۿ�~}
	Vec2 pos = GetPos();
	Vec2 scale = GetScale();
	RECT rt = RECT_MAKE(pos.x, pos.y, scale.x, scale.y);
	RECT_RENDER(pos.x, pos.y, scale.x, scale.y, _dc);
	DrawText(_dc, m_text.c_str(), m_text.length(), &rt, DT_SINGLELINE | DT_VCENTER | DT_CENTER);

	DeleteObject(currentFont);
}
