#include "pch.h"
#include "InputField.h"
#include "KeyMgr.h"

#include "Core.h"
#include <chrono>

InputField::InputField()
    : m_limit(0)
    , m_focusMe(false)
    , m_wstr{}
    , m_count(0)
{
    //HWND hWnd = Core::GetInst()->GetHwnd();
    //CreateCaret(hWnd, nullptr, 5, 15);
    //ShowCaret(hWnd);
    ////SetCaretBlinkTime(500);
    //SetCaretPos(10, 10);
    //SetWindowText(Core::GetInst()->GetHwnd(), L"ĳ���������");
}

InputField::~InputField()
{
    //HideCaret(hWnd);
}

void InputField::Update()
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
        if (KEY_DOWN(KEY_TYPE::LBUTTON)) {        // �ٸ����� ���� Ŭ���� �ϸ� ���� �������� �ʰ� ��.
            m_focusMe = false;
            //m_wstr[m_count] = ' ';
            if (m_wstr[m_count] = '|') {        // ������ �ʾ��� ��
                m_wstr[m_count] = ' ';
                //m_count++;
            }
            else {
                m_wstr[m_count + 1] = ' ';
            }
        }
    }

    // �ð� ������� ĳ���� ���ڰŸ��� ����
    //static std::chrono::time_point<std::chrono::system_clock> lastToggleTime = std::chrono::system_clock::now();
    //auto currentTime = std::chrono::system_clock::now();
    //auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastToggleTime).count();

    //for (int i = 0; i < m_limit; ++i)
    //{
    //    if (m_wstr[i] == '|') {
    //        int index = i;

    //        if (elapsedTime > 500)  // 500�и��� �ֱ�� ���
    //        {
    //            // ĳ�� ���
    //            if (m_wstr[i] == '|') {
    //                m_wstr[i] = ' ';
    //            }
    //            else {
    //                m_wstr[i] = '|';
    //            }

    //            // ĳ�� ��� �ð� ������Ʈ
    //            lastToggleTime = currentTime;
    //        }
    //    }
    //}

    if (m_focusMe)        // ������ �����ϴ� ���̶�� Ű���尡 �Էµǰ�
    {
        for (int i = 0; i < (int)KEY_TYPE::LAST; ++i)
        {
            //if (GetAsyncKeyState(KeyMgr::GetInst()->GetKeyType(i)))
            if (KeyMgr::GetInst()->GetKey(i) == KEY_STATE::DOWN)
            {
                // Ű ���� Ȯ���ؼ� down �� ���� ������ �װ� �־��ֱ�
                char input = KeyMgr::GetInst()->GetKeyChar(i);
                //wstring b = std::to_wstring((int)input);
                //SetWindowText(Core::GetInst()->GetHwnd(), b.c_str());
                if (input >= 65 && input <= 90 && m_count < m_limit) {       // Ű������ ���� ����Ʈ�� ���� �ʾ��� ��
                    m_wstr[m_count] = input;
                    m_count++;
                    m_wstr[m_count] = '|';
                }
            }
        }
        if (GetAsyncKeyState(VK_BACK) & 0x8000) {
            if (m_count > 0) {      // 0���� ū ������ ����
                if (m_wstr[m_count] == '|' || m_wstr[m_count] == ' ') {        // ó����
                    m_wstr[m_count] = ' ';
                }
                m_count--;
                m_wstr[m_count] = '|';
                //wstring b = std::to_wstring(m_count) + L" ��Ű ����";
                //SetWindowText(Core::GetInst()->GetHwnd(), b.c_str());
                Sleep(150);     // ��ٷ��ֱ�~
            }
            else {      // 0�� �Ǹ� ĳ���� �����
                m_wstr[0] = '|';
            }
        }

        //wstring b = std::to_wstring(m_count);
        //SetWindowText(Core::GetInst()->GetHwnd(), b.c_str());
    }
}

void InputField::Render(HDC _dc)
{
    Vec2 pos = GetPos();
    Vec2 scale = GetScale();
    RECT rt = RECT_MAKE(pos.x, pos.y, scale.x, scale.y);
    RECT_RENDER(pos.x, pos.y, scale.x, scale.y, _dc);

   // SIZE size;
    //GetTextExtentPoint(_dc, m_wstr, wcslen(m_wstr), &size);
    //SetCaretPos(size.cx, 0);
    //SetCaretPos(10, 10);

    DrawText(_dc, m_wstr, m_limit, &rt, DT_SINGLELINE | DT_VCENTER | DT_CENTER);        // ����Ʈ�� ���̸�ŭ�� ���
}
