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
    //wstring wstr = L"Ű �Է� ����";
    //hdc = GetDC(hWnd);                       // DG �� �޾ƿ���

    //if (wParam == VK_BACK && count > 0) {
    //    count--;
    //}
    //else if (wParam == VK_RETURN) {
    //    count = 0;
    //    yPos += 20;
    //}
    //else if (wParam == VK_SPACE) {        // ��������, �����̽��ٷ� �ٷ� ������ �̵��ϱ�
    //    count = 0;
    //}
    //else {
    //    wstr[count++] = wParam;
    //}
    //wstr[count] = NULL;

    //wstr[0] = wParam;
    //wstr[1] = NULL;       // �������� ��µ� �� ���

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
        if (KEY_DOWN(KEY_TYPE::LBUTTON)) {        // �ٸ����� ���� Ŭ���� �ϸ� ���� �������� �ʰ� ��.
            m_focusMe = false;
        }
    }

    if (m_focusMe)        // ������ �����ϴ� ���̶�� Ű���尡 �Էµǰ�
    {
        for (int i = 0; i < (int)KEY_TYPE::LAST; ++i)
        {
            //if (GetAsyncKeyState(KeyMgr::GetInst()->GetKeyType(i)))
            if (KeyMgr::GetInst()->GetKey(i) == KEY_STATE::DOWN)
            {
                // Ű ���� Ȯ���ؼ� down �� ���� ������ �װ� �־��ֱ�
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
    DrawText(_dc, m_wstr, m_limit, &rt, DT_SINGLELINE | DT_VCENTER | DT_CENTER);        // ����Ʈ�� ���̸�ŭ�� ���
}
