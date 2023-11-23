#pragma once
#include "UI.h"
class Button :
    public UI
{
public:
    Button();
    ~Button();
public:
    void Update() override;
    void Render(HDC _dc) override;
};

