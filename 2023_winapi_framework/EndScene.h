#pragma once
#include "Scene.h"

class Text;

class EndScene : public Scene
{
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void Release() override;
public:
    Text* m_pText;
    float m_fEndTime;
};

