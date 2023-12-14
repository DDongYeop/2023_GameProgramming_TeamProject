#pragma once
#include "Scene.h"
class Intro : public Scene
{
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void Release() override;
private:
    float m_fOpacity;
    BLENDFUNCTION m_Bf;
};

