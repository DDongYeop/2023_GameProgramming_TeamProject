#include "pch.h"
#include "Puzzle_3.h"
#include "Core.h"

void Puzzle_3::Init()
{
	SetWindowText(Core::GetInst()->GetHwnd(), L"�����Ӹ��̽��Ͱ� ���� ���α׷� ver.1.0 ���� 3");

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
