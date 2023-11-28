#include "pch.h"
#include "InputField.h"
#include "KeyMgr.h"

InputField::InputField()
	: m_Limit(0)
	, m_FocusMe(false)
	, m_Text{}
{
}

InputField::~InputField()
{
}

void InputField::Update()
{
	//wstring wstr = L"키 입력 감지";
	//hdc = GetDC(hWnd);                       // DG 를 받아오기

	//if (wParam == VK_BACK && count > 0) {
	//    count--;
	//}
	//else if (wParam == VK_RETURN) {
	//    count = 0;
	//    yPos += 20;
	//}
	//else if (wParam == VK_SPACE) {        // 연습문제, 스페이스바로 바로 앞으로 이동하기
	//    count = 0;
	//}
	//else {
	//    wstr[count++] = wParam;
	//}
	//wstr[count] = NULL;

	//wstr[0] = wParam;
	//wstr[1] = NULL;       // 무작위로 출력될 때 사용

	Vec2 pos = GetPos();
	Vec2 scale = GetScale();
	RECT rt = RECT_MAKE(pos.x, pos.y, scale.x, scale.y);
	POINT mousePos = KeyMgr::GetInst()->GetMousePos();

	if ((mousePos.x > rt.left && mousePos.x < rt.right) && (mousePos.y > rt.top && mousePos.y < rt.bottom)) {
		if (KEY_DOWN(KEY_TYPE::LBUTTON)) {
			m_FocusMe = true;
		}
	}
	else {
		if (KEY_DOWN(KEY_TYPE::LBUTTON)) {		// 다른곳에 가서 클릭을 하면 내게 집중하지 않게 됨.
			m_FocusMe = false;
		}
	}

	if (m_FocusMe)		// 나에게 집중하는 중이라면 키보드가 입력되게
	{
		for (int i = 0; i < (int)KEY_TYPE::LAST; ++i)
		{
			//if (GetAsyncKeyState(KeyMgr::GetInst()->GetKeyType(i)))
			if (  ==  )
			{
				// 키 상태 확인해서 down 인 것이 있으면 그거 넣어주기
			}
		}
	}

}

void InputField::Render(HDC _dc)
{
	Vec2 pos = GetPos();
	Vec2 scale = GetScale();
	RECT rt = RECT_MAKE(pos.x, pos.y, scale.x, scale.y);
	RECT_RENDER(pos.x, pos.y, scale.x, scale.y, _dc);
	DrawText(_dc, m_Text.c_str(), m_Limit, &rt, DT_SINGLELINE | DT_VCENTER | DT_CENTER);		// 리미트의 길이만큼만 출력
}
