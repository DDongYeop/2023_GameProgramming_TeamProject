#pragma once
#include "UI.h"
class Text :
    public UI
{
public:
    Text();
    ~Text();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    void SetText(wstring text) { m_Text = text; }
private:
    wstring m_Text;
    HFONT m_hFont, m_hOldFont;
};

