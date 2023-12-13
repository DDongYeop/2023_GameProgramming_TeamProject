#pragma once
class UI
{
public:
	UI();
	~UI();
public:
	virtual void Update();
	virtual void Render(HDC _dc);
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
	const Vec2& GetPos() const { return m_vPos; }
	const Vec2& GetScale() const { return m_vScale; }
	// 폰트 체인지 함수 만들어두깅~
private:
	Vec2 m_vPos; // 위치			// 네모 구역으로 이루어질 것의 가운데 위치임.
	Vec2 m_vScale; // 크기
	// 폰트 가지고 있게 하기			 여러가지 변수와 함수들 추가로 만들어주깅!
};

