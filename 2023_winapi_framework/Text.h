#pragma once
#include "UI.h"
#include <queue>

class Text :
    public UI
{
public:
    Text();
    Text(float _currentTime);
    ~Text();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    void SetText(wstring text) { m_qPrintQueue.push(text); }
private:
    int                 m_iPrintIndex;
    float               m_fPrintTime;
    float               m_fCurrentTime;
    wstring             m_sFrontText;
    wstring             m_sPrintText;
    std::queue<wstring> m_qPrintQueue;
};

