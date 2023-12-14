#include "pch.h"
#include "PlayTimeMgr.h"
#include "TimeMgr.h"
#include "SceneMgr.h"

void PlayTimeMgr::Init()
{
	m_bIsPlay = false;
	m_fCurrentPlayTime = 0;
}

void PlayTimeMgr::Update()
{
	if (m_bIsPlay)
		m_fCurrentPlayTime += fDT;

	if (m_fCurrentPlayTime >= 300)
		SceneMgr::GetInst()->LoadScene(L"EndScene");
}
