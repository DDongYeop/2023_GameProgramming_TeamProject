#include "pch.h"
#include "ExplorerMgr.h"

/// <summary>
/// File Explorer�� �����ݴϴ�
/// </summary>
/// <param name="path">������ ��ġ�� �����ּ���.</param>
void ExplorerMgr::Open(std::string path)
{
	std::string str = "explorer " + path;
	char* ch = new char[str.size()];
	strcpy_s(ch, str.size() + 1, str.c_str());
	system(ch);
}
