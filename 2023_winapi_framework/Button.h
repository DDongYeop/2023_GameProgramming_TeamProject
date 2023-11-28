#pragma once
#include "UI.h"
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
private:
    bool m_Clickable;
    wstring m_Text;
};

