#include "pch.h"
#include "ExplorerMgr.h"

/// <summary>
/// File Explorer을 열어줍니다
/// </summary>
/// <param name="path">파일의 위치를 적어주세요.</param>
void ExplorerMgr::Open(std::string path)
{
	std::string str = "explorer " + path;
	char* ch = new char[str.size()];
	strcpy_s(ch, str.size() + 1, str.c_str());
	system(ch);
}
