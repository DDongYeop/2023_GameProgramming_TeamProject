#include "pch.h"
#include "OpenMgr.h"

/// <summary>
/// WebSite�� �����ݴϴ�. 
/// </summary>
/// <param name="value">������ ��� ���� �����ݴϴ�. (Website, FileExplorer)</param>
void OpenMgr::Open(std::string value)
{
	std::string str = "explorer " + value;
	char* ch = new char[str.size()];
	strcpy_s(ch, str.size() + 1, str.c_str());
	system(ch);
}
