#pragma once
#include "UI.h"
#include <queue>

class Text :
    public UI
{
public:
    Text();
    Text(float _printTime);
    ~Text();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    void ReSet(float fPrintTime = 0.15f);
    void AddText(wstring text) { m_qPrintQueue.push(text); }
    bool GetComplete() { return m_complete; }
private:
    float               m_fPrintTime;       // 한 글자가 나오는 시간
    float               m_fCurrentTime;
    wstring             m_sFrontText;       // 지금 출력되어야 하는 텍스트 전체
    wstring             m_sPrintText;       // 지금 출력되고 있는 텍스트
    std::queue<wstring> m_qPrintQueue;      // 지금 가지고 있는 텍스트 큐
    bool                    m_complete;
};

