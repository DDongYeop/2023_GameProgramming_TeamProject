#pragma once
#include "UI.h"
#include <queue>

class Text :
    public UI
{
public:
    Text();
    //Text(float _printTime);
    ~Text();
public:
    void Update() override;
    void Render(HDC _dc) override;
public:
    void ReSet();
    void AddText(wstring text) { m_qPrintQueue.push(text); }
    bool GetComplete() { return m_complete; }
    void NoStop() { m_stop = false; }       // ���� ����
    bool GetStop() { return m_stop; }
private:
    float               m_fPrintTime;       // �� ���ڰ� ������ �ð�
    float               m_fCurrentTime;
    wstring             m_sFrontText;       // ���� ��µǾ�� �ϴ� �ؽ�Ʈ ��ü
    wstring             m_sPrintText;       // ���� ��µǰ� �ִ� �ؽ�Ʈ
    std::queue<wstring> m_qPrintQueue;      // ���� ������ �ִ� �ؽ�Ʈ ť
    bool                    m_complete;
    bool                    m_stop;
};

