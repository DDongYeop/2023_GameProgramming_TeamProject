#pragma once
#include "Scene.h"
#include "Text.h"
#include "Button.h"
class Puzzle_2 : public Scene
{
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void Release() override;
private:
    bool m_puzzleOk = false;
    Text* pText = new Text();
    Button* pButton = new Button();
    float m_time;
    float m_changeSceneTime;
    bool m_btnOk = false;
};