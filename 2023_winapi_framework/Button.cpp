#include "pch.h"
#include "Button.h"
#include "KeyMgr.h"
#include "OpenMgr.h"
//#include "Core.h"

Button::Button()
	: m_Clickable(false)
	, m_Open(false)
	, m_link{}
{
	AddFontResource(TEXT("Orbit Regular.ttf"));
}

Button::~Button()
{
}

void Button::Update()
{
	// if ���콺�� �������� �ٲ��ֱ� �� Ŭ���� ������ ��¼��~
	Vec2 pos = GetPos();
	Vec2 scale = GetScale();
	RECT rt = RECT_MAKE(pos.x, pos.y, scale.x, scale.y);
	POINT mousePos = KeyMgr::GetInst()->GetMousePos();
	if ((mousePos.x > rt.left && mousePos.x < rt.right) && (mousePos.y > rt.top && mousePos.y < rt.bottom)) {
		m_Clickable = true;
		//SetWindowText(Core::GetInst()->GetHwnd(), L"��ư ����");
		if (KEY_DOWN(KEY_TYPE::LBUTTON)) {
			//m_Text = L"����";
			if (m_Open) {
				OpenMgr::GetInst()->Open(m_link);
			}
		}
	}
	else {
		m_Clickable = false;
		//m_Text = L"��ư";
		//SetWindowText(Core::GetInst()->GetHwnd(), L"��ư �ȵ���");
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
	DrawText(_dc, m_Text.c_str(), m_Text.length(), &rt, DT_SINGLELINE | DT_VCENTER | DT_CENTER);

	DeleteObject(currentFont);
}
