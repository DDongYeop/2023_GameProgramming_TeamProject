#include "pch.h"
#include "Button.h"
#include "KeyMgr.h"
//#include "Core.h"

Button::Button()
	: m_Clickable(false)
{
}

Button::~Button()
{
}

void Button::Update()
{
	// if 마우스가 들어왔으면 바꿔주기 또 클릭이 들어오면 어쩌고~
	Vec2 pos = GetPos();
	Vec2 scale = GetScale();
	RECT rt = RECT_MAKE(pos.x, pos.y, scale.x, scale.y);
	POINT mousePos = KeyMgr::GetInst()->GetMousePos();
	if ((mousePos.x > rt.left && mousePos.x < rt.right) && (mousePos.y > rt.top && mousePos.y < rt.bottom)) {
		m_Clickable = true;
		//SetWindowText(Core::GetInst()->GetHwnd(), L"버튼 들어옴");
		if (KEY_DOWN(KEY_TYPE::LBUTTON)) {
			m_Text = L"눌림";
		}
	}
	else {
		m_Clickable = false;
		m_Text = L"버튼";
		//SetWindowText(Core::GetInst()->GetHwnd(), L"버튼 안들어옴");
	}
}

void Button::Render(HDC _dc)
{
	// if (m_Clickable) {// 뭐 어쩌고 작용~}
	Vec2 pos = GetPos();
	Vec2 scale = GetScale();
	RECT rt = RECT_MAKE(pos.x, pos.y, scale.x, scale.y);
	RECT_RENDER(pos.x, pos.y, scale.x, scale.y, _dc);
	DrawText(_dc, m_Text.c_str(), m_Text.length(), &rt, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
}
