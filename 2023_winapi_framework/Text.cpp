#include "pch.h"
#include "Text.h"
#include "pathMgr.h"

#include "SelectGDI.h"

Text::Text()
	: m_Text{}
{
}

Text::~Text()
{
}

void Text::Update()
{
	// update~
}

#include <fstream>

bool DoesFileExist(const wstring& filePath) {
	std::ifstream file(filePath.c_str());
	return file.good();
}

void Text::Render(HDC _dc)
{
	//SetWindowText(Core::GetInst()->GetHwnd(), L"titlebuf");

	//AddFontResource(TEXT("Orbit-Regular.ttf"));
	////AddFontResource(TEXT("Regular.ttf"));

	wstring strfont = L"Font\\Galmuri14.ttf";
	wstring strFilepath = PathMgr::GetInst()->GetResPath() + strfont;
	LPCWSTR fontPath = strFilepath.c_str();

	if (!DoesFileExist(fontPath)) {
		MessageBox(NULL, L"폰트 파일이 존재하지 않습니다.", L"에러", MB_OK | MB_ICONERROR);
	}

	int result = AddFontResource(fontPath);
	if (result == 0) {
		MessageBox(NULL, L"폰트를 만들지 못했습니다.", L"에러", MB_OK | MB_ICONERROR);
	}
	AddFontResource(L"Galmuri14.ttf");
	HFONT hFont = CreateFont(25, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("Galmuri14"));
	//HFONT hFont = CreateFont(25, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		//OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, endPath);
	//HFONT hFont = CreateFont(25, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, fontPath);
	//
	//if (hFont == NULL) {
	//	MessageBox(NULL, L"폰트를 만들지 못했습니다.", L"에러", MB_OK | MB_ICONERROR);
	//}
	//
	//SelectObject(_dc, hFont);

	////wstring font = L"Font\\Orbit-Regular.ttf";
	////wstring strFilepath = PathMgr::GetInst()->GetResPath() + font;

	////LOGFONT lf = { 0 };
	////lf.lfHeight = 25;
	////lf.lfCharSet = HANGUL_CHARSET;
	////lf.lfOutPrecision = OUT_TT_ONLY_PRECIS;  // TrueType 폰트만 사용
	////lf.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	////lf.lfQuality = CLEARTYPE_QUALITY;
	////wcscpy_s(lf.lfFaceName, LF_FACESIZE, L"Orbit-Regular");  // 폰트 이름 지정

	////HFONT hFont = CreateFontIndirect(&lf);

	////if (hFont == NULL) {
	////	MessageBox(NULL, L"폰트를 만들지 못했습니다.", L"에러", MB_OK | MB_ICONERROR);
	////}

	SelectObject(_dc, hFont);
	SelectGDI font(_dc, hFont);

	Vec2 pos = GetPos();
	Vec2 scale = GetScale();
	RECT rt = RECT_MAKE(pos.x, pos.y, scale.x, scale.y);
	DrawText(_dc, m_Text.c_str(), m_Text.length(), &rt, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
}
