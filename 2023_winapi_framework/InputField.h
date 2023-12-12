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
        for (int i = 0; i < m_count; i++)
        {
            temp += m_wstr[i];
        }
        return temp;
    }
    void Lock() 
    {
        m_useThis = false;
        m_wstr[m_count] = ' ';
    }
private:
    int m_limit;
    bool m_focusMe;
    bool m_useThis;
    wchar_t m_wstr[100];
    int m_count;
};
