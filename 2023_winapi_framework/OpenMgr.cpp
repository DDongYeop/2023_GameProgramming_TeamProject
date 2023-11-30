#include "pch.h"
#include "OpenMgr.h"

/// <summary>
/// WebSite를 열어줍니다. 
/// </summary>
/// <param name="value">세상의 모든 것을 열어줍니다. (Website, FileExplorer)</param>
void OpenMgr::Open(std::string value)
{
	std::string str = "explorer " + value;
	char* ch = new char[str.size()];
	strcpy_s(ch, str.size() + 1, str.c_str());
	system(ch);
}
