#pragma once
#include "Object.h"

class Texture;

class GGM_Logo : public Object
{
public:
	GGM_Logo();
	~GGM_Logo();
public:
	void Update() override;
	void Render(HDC _dc) override;
private:
	Texture* m_pTex;
	float m_fOpacity;
	float m_fFadeValue;
	BLENDFUNCTION m_Bf;
};

