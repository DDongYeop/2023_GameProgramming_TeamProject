#include "pch.h"
#include "InputField.h"
#include "KeyMgr.h"

#include "Core.h"
#include <chrono>

InputField::InputField()
    : m_limit(0)
    , m_focusMe(false)
    , m_useThis(true)
    , m_wstr{}
    , m_count(0)
{
    //HWND hWnd = Core::GetInst()->GetHwnd();
    //CreateCaret(hWnd, nullptr, 5, 15);
    //ShowCaret(hWnd);
    ////SetCaretBlinkTime(500);
    //SetCaretPos(10, 10);
    //SetWindowText(Core::GetInst()->GetHwnd(), L"캐럿보여라얍");
    AddFontResource(TEXT("엘리스 DX널리체  Light.ttf"));
}

InputField::~InputField()
{
    //HideCaret(hWnd);
}

void InputField::Update()
{
    if (m_useThis)
    {
        Vec2 pos = GetPos();
        Vec2 scale = GetScale();
        RECT rt = RECT_MAKE(pos.x, pos.y, scale.x, scale.y);
        POINT mousePos = KeyMgr::GetInst()->GetMousePos();

        /*static  HWND hWnd = Core::GetInst()->GetHwnd();
         CreateCaret(hWnd, nullptr, 5, 15);
         ShowCaret(hWnd);*/
         //SetCaretBlinkTime(500);
         //SetCaretPos(10, 10);

        if ((mousePos.x > rt.left && mousePos.x < rt.right) && (mousePos.y > rt.top && mousePos.y < rt.bottom)) {
            if (KEY_DOWN(KEY_TYPE::LBUTTON)) {
                m_wstr[m_count] = '|';
                m_focusMe = true;
            }
        }
        else {
            if (KEY_DOWN(KEY_TYPE::LBUTTON)) {        // 다른곳에 가서 클릭을 하면 내게 집중하지 않게 됨.
                m_focusMe = false;
                //m_wstr[m_count] = ' ';
                if (m_wstr[m_count] = '|') {        // 지우지 않았을 때
                    m_wstr[m_count] = ' ';
                    //m_count++;
                }
                else {
                    m_wstr[m_count + 1] = ' ';
                }
            }
        }

        // 시간 기반으로 캐럿을 깜박거리게 만듦
        //static std::chrono::time_point<std::chrono::system_clock> lastToggleTime = std::chrono::system_clock::now();
        //auto currentTime = std::chrono::system_clock::now();
        //auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastToggleTime).count();

        //for (int i = 0; i < m_limit; ++i)
        //{
        //    if (m_wstr[i] == '|') {
        //        int index = i;

        //        if (elapsedTime > 500)  // 500밀리초 주기로 토글
        //        {
        //            // 캐럿 토글
        //            if (m_wstr[i] == '|') {
        //                m_wstr[i] = ' ';
        //            }
        //            else {
        //                m_wstr[i] = '|';
        //            }

        //            // 캐럿 토글 시간 업데이트
        //            lastToggleTime = currentTime;
        //        }
        //    }
        //}

        if (m_focusMe)        // 나에게 집중하는 중이라면 키보드가 입력되게
        {
            for (int i = 0; i < (int)KEY_TYPE::LAST; ++i)
            {
                //if (GetAsyncKeyState(KeyMgr::GetInst()->GetKeyType(i)))
                if (KeyMgr::GetInst()->GetKey(i) == KEY_STATE::DOWN)
                {
                    // 키 상태 확인해서 down 인 것이 있으면 그거 넣어주기
                    char input = KeyMgr::GetInst()->GetKeyChar(i);
                    //wstring b = std::to_wstring((int)input);
                    //SetWindowText(Core::GetInst()->GetHwnd(), b.c_str());
                    if (input >= 65 && input <= 90 && m_count < m_limit) {       // 키보드인 경우와 리미트를 넘지 않았을 때
                        m_wstr[m_count] = input;
                        m_count++;
                        m_wstr[m_count] = '|';
                    }
                }
            }
            if (GetAsyncKeyState(VK_BACK) & 0x8000) {
                if (m_count > 0) {      // 0보다 큰 상태일 때만
                    if (m_wstr[m_count] == '|' || m_wstr[m_count] == ' ') {        // 처음에
                        m_wstr[m_count] = ' ';
                    }
                    m_count--;
                    m_wstr[m_count] = '|';
                    //wstring b = std::to_wstring(m_count) + L" 백키 누름";
                    //SetWindowText(Core::GetInst()->GetHwnd(), b.c_str());
                    Sleep(150);     // 기다려주기~
                }
                else {      // 0이 되면 캐럿만 남기기
                    m_wstr[0] = '|';
                }
            }

            //wstring b = std::to_wstring(m_count);
            //SetWindowText(Core::GetInst()->GetHwnd(), b.c_str());
        }
    }
}

void InputField::Render(HDC _dc)
{
    HFONT currentFont = CreateFont(20, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("엘리스 DX널리체  Light"));
    HFONT oldFont = (HFONT)SelectObject(_dc, currentFont);

    Vec2 pos = GetPos();
    Vec2 scale = GetScale();
    RECT rt = RECT_MAKE(pos.x, pos.y, scale.x, scale.y);
    RECT_RENDER(pos.x, pos.y, scale.x, scale.y, _dc);

   // SIZE size;
    //GetTextExtentPoint(_dc, m_wstr, wcslen(m_wstr), &size);
    //SetCaretPos(size.cx, 0);
    //SetCaretPos(10, 10);

    DrawText(_dc, m_wstr, m_limit, &rt, DT_SINGLELINE | DT_VCENTER | DT_CENTER);        // 리미트의 길이만큼만 출력

    DeleteObject(currentFont);
}
