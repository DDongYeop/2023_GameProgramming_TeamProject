#include "pch.h"
#include "Puzzle_3.h"
#include "FileMgr.h"
#include "SceneMgr.h"

void Puzzle_3::Init()
{
}

void Puzzle_3::Update()
{
	Scene::Update();

	wstring path = L"GGM\\2_Grade\\Class_2\\";
	wstring name = L"Light.txt";
	if (FileMgr::GetInst()->Exist(path, name))
		SceneMgr::GetInst()->LoadScene(L"EndScene");
}

void Puzzle_3::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Puzzle_3::Release()
{
	Scene::Release();
}
