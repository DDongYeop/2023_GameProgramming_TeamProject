#include "pch.h"
#include "SceneMgr.h"
//#include "Game_Scene.h"
#include "Start_Scene.h"
#include "Puzzle_1.h"
#include "Test_Scene.h"
#include "Intro.h"
void SceneMgr::Init()
{
	m_pCurScene = nullptr;
	// ¾À µî·Ï
	//RegisterScene(L"Game_Scene", std::make_shared<Game_Scene>());
	RegisterScene(L"Start_Scene", std::make_shared<Start_Scene>());
	RegisterScene(L"Intro", std::make_shared<Intro>());
	//RegisterScene(L"Puzzle_2", std::make_shared<Puzzle_2>());

	RegisterScene(L"Test_Scene", std::make_shared<Test_Scene>());

	// Ã¹ ¾À ÁöÁ¤
	//LoadScene(L"Test_Scene");
	//LoadScene(L"Start_Scene");
	LoadScene(L"Intro");
}

void SceneMgr::Update()
{
	m_pCurScene->Update();
	m_pCurScene->FinalUpdate();
}

void SceneMgr::Render(HDC _dc)
{
	m_pCurScene->Render(_dc);
}

void SceneMgr::LoadScene(const wstring& _scenename)
{
	// ¾ÀÀÌ ÀÖÀ¸¸é
	if (m_pCurScene != nullptr)
	{
		m_pCurScene->Release();
		m_pCurScene = nullptr;
	}

	auto iter = m_mapScenes.find(_scenename);
	if (iter != m_mapScenes.end())
	{
		m_pCurScene = iter->second;
		m_pCurScene->Init();
	}
}

void SceneMgr::RegisterScene(const wstring& _scenename, std::shared_ptr<Scene> _scene)
{
	m_mapScenes.insert(m_mapScenes.end(), { _scenename, _scene });
}
