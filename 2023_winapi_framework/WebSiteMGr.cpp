#include "pch.h"
#include "WebSiteMgr.h"

/// <summary>
/// WebSite�� �����ݴϴ�. 
/// </summary>
/// <param name="link">�� ����Ʈ�� URL�� �Է����ּ���.</param>
void WebSiteMgr::Open(std::string link)
{
	std::string str = "explorer " + link;
	char* ch = new char[str.size()];
	strcpy_s(ch, str.size() + 1, str.c_str());
	system(ch);
}
