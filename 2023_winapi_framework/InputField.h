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
    void SetLimit(int limit) { m_limit = limit; }
private:
    int m_limit;
    bool m_focusMe;
    wchar_t m_wstr[100];
    int m_count;
};
