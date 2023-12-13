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
    bool m_clickable;       // 클릭이 가능한가.
    bool m_clickBtn;        // 클릭이 되었는가
    bool m_open;
    bool m_useThis;     // 지금 사용이 가능해야하는가. 인풋필드의 락처럼
    std::string m_link;
    wstring m_text;
};

