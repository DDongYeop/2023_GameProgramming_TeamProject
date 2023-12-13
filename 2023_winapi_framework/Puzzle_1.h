#pragma once
#include "Scene.h"
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
};

