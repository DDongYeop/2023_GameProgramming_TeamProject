#include "pch.h"
#include "Puzzle_3.h"
#include "Core.h"

void Puzzle_3::Init()
{
	SetWindowText(Core::GetInst()->GetHwnd(), L"경기게임마이스터고 입학 프로그램 ver.1.0 퍼즐 3");

}

void Puzzle_3::Update()
{
	Scene::Update();

}

void Puzzle_3::Render(HDC _dc)
{
	Scene::Render(_dc);

}

void Puzzle_3::Release()
{
	Scene::Release();

}
