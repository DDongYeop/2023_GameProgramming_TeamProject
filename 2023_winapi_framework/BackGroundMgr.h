#pragma once

class BackGroundMgr
{
	SINGLE(BackGroundMgr);
public:
	void Render(HDC _dc);
public:
	void SetColor(COLORREF _color);

private:
	COLORREF m_cColor;
};

