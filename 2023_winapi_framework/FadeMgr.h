#pragma once

class FadeMgr
{
	SINGLE(FadeMgr);
public:
	void Init();
	void Update();
	void Render(HDC _dc, HINSTANCE _instance);
public:
	void Fade(bool value);
private:
	float m_fOpacity;
	bool m_iFade;
	BLENDFUNCTION _bf;

};