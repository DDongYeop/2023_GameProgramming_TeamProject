#pragma once
#include "UI.h"
class InputField :
    public UI
{
public:
    InputField();
    ~InputField();
public:
    void Update() override;
    void Render(HDC _dc) override;
};

