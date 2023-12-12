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
    void SetText(wstring text) { m_Text = text; }
    void SetOpen(std::string link) 
    {
        m_Open = true;
        m_link = link;
    }
private:
    bool m_Clickable;
    bool m_Open;
    std::string m_link;
    wstring m_Text;
};

