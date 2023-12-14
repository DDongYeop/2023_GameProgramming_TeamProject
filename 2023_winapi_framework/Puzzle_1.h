#pragma once
#include "Scene.h"
#include <vector>
#include "Button.h"
#include "InputField.h"
class Puzzle_1 :
    public Scene
{
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void Release() override;
    //bool PuzzleCheck();
private:
    bool m_puzzleOk;
    float m_fCurrentTime, m_fPrintTime;
    wstring m_title, m_nowText;
    bool m_textOk, m_btnOk;		// 제목 텍스트가 입력됬으면 true 임. 버튼이 생생되면 true 임
    vector<InputField*> m_inputFields;
    Button* m_gameBtn = new Button();
    float m_changeSceneTime, m_changeTime;
};

