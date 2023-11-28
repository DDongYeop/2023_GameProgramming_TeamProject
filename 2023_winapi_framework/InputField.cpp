#include "pch.h"
#include "InputField.h"
#include "KeyMgr.h"

InputField::InputField()
    : m_limit(0)
    , m_focusMe(false)
    , m_wstr{}
    , m_count(0)
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
            m_focusMe = true;
        }
    }
    else {
        if (KEY_DOWN(KEY_TYPE::LBUTTON)) {        // 다른곳에 가서 클릭을 하면 내게 집중하지 않게 됨.
            m_focusMe = false;
        }
    }

    if (m_focusMe)        // 나에게 집중하는 중이라면 키보드가 입력되게
    {
        for (int i = 0; i < (int)KEY_TYPE::LAST; ++i)
        {
            //if (GetAsyncKeyState(KeyMgr::GetInst()->GetKeyType(i)))
            if (KeyMgr::GetInst()->GetKey(i) == KEY_STATE::DOWN)
            {
                // 키 상태 확인해서 down 인 것이 있으면 그거 넣어주기
                m_wstr[m_count++] = KeyMgr::GetInst()->GetKeyChar(i);
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
    DrawText(_dc, m_wstr, m_limit, &rt, DT_SINGLELINE | DT_VCENTER | DT_CENTER);        // 리미트의 길이만큼만 출력
}
