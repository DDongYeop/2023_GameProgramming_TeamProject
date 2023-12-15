#pragma once
#include "Scene.h"
#include "Text.h"
#include "InputField.h"
#include "Button.h"
class Puzzle_3 :
    public Scene
{
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void Release() override;
    bool PuzzleCheck();
private:
    bool m_puzzleOk = false;
    Text* pText = new Text();
    InputField* pInputField1 = new InputField();
    InputField* pInputField2 = new InputField();
    InputField* pInputField3 = new InputField();
    InputField* pInputField4 = new InputField();
    Button* pOpenBtn = new Button();
    bool m_puzzleSetting = false;
    float time = 0;
};

