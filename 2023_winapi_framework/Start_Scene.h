#pragma once
#include "Scene.h"
#include "Text.h"
#include "InputField.h"
#include "Button.h"
class Start_Scene :
    public Scene
{
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void Release() override;
    bool PuzzleCheck();
private:
    bool m_puzzleOk = false;
    Text* pText = new Text();		// ¿Ã∞≈ ∫Øºˆ ª©Ω√¡’
    InputField* pInputField1 = new InputField();
    InputField* pInputField2 = new InputField();
    InputField* pInputField3 = new InputField();
    Button* pHintBtn1 = new Button();
    Button* pHintBtn2 = new Button();
    bool puzzleSetting = false;
    float time = 0;
};

