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
    void SetLimit(int limit) 
    {
        m_limit = limit; 
        for (int i = 0; i < m_limit; i++)
        {
            m_wstr[i] = ' ';
        }
    }
    std::string GetText() {
        std::string temp;
        for (int i = 0; i < m_limit; i++)
        {
            temp += m_wstr[i];
        }
        return temp;
    }
private:
    int m_limit;
    bool m_focusMe;
    wchar_t m_wstr[100];
    int m_count;
};
