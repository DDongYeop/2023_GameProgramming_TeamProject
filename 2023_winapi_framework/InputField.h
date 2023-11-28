#pragma once
#include "UI.h"
class InputField :
    public UI
{
public:
    InputField();
    ~InputField();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    void SetLimit(int limit) { m_Limit = limit; }
private:
    int m_Limit;
    bool m_FocusMe;
    wstring m_Text;
    wchar_t wstr[100];
};

