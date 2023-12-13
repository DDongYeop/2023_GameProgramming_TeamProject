#pragma once
#include "UI.h"
#include <string>
class Button :
    public UI
{
public:
    Button();
    ~Button();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    void SetText(wstring text) { m_text = text; }
    void SetOpen(std::string link) 
    {
        m_open = true;
        m_link = link;
    }
    bool GetClick() { return m_clickBtn; }
    void Lock() {
        m_useThis = false;
        m_clickBtn = false;
        m_clickable = false;
    }
private:
    bool m_clickable;       // Ŭ���� �����Ѱ�.
    bool m_clickBtn;        // Ŭ���� �Ǿ��°�
    bool m_open;
    bool m_useThis;     // ���� ����� �����ؾ��ϴ°�. ��ǲ�ʵ��� ��ó��
    std::string m_link;
    wstring m_text;
};

