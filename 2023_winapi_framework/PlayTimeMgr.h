#pragma once
class PlayTimeMgr
{
	SINGLE(PlayTimeMgr);
public:
	void Init();
	void Update();
public:
	void TimerStart() { m_bIsPlay = true; }
	void TimerEnd() { m_bIsPlay = false; }
public:
	float GetPlayTime() { return m_fCurrentPlayTime; }
private:
	bool m_bIsPlay;
	float m_fCurrentPlayTime;
};

