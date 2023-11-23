#pragma once
#include "UI.h"
class Text :
    public UI
{
public:
    Text();
    ~Text();
public:
    void Update() override;
    void Render(HDC _dc) override;
};

