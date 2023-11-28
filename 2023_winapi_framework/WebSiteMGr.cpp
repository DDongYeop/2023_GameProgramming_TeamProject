#include "pch.h"
#include "WebSiteMgr.h"

/// <summary>
/// WebSite를 열어줍니다. 
/// </summary>
/// <param name="link">열 사이트의 URL을 입력해주세요.</param>
void WebSiteMgr::Open(std::string link)
{
	std::string str = "explorer " + link;
	char* ch = new char[str.size()];
	strcpy_s(ch, str.size() + 1, str.c_str());
	system(ch);
}
