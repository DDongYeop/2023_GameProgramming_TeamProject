#include "pch.h"
#include "FileMgr.h"
#include "PathMgr.h"
#include <filesystem>
#include <io.h>

namespace fs = std::filesystem;

void FileMgr::Init()
{
	filePath = PathMgr::GetInst()->GetResPath();
}

/// <summary>
/// 특정 파일이 존재하는지 확인하는 함수. 
/// </summary>
/// <param name="_path">GGM\\1_Grade\\Class_1\\ << 방식처럼 사용하시면 됩니다.</param>
/// <param name="_name">.txt 같은 것도 적어주어야함.</param>
/// <returns></returns>
bool FileMgr::Exist(wstring& _path, wstring& _name)
{
	wstring path = filePath + _path + _name;
	std::string str;
	str.assign(path.begin(), path.end());
	char* ch = new char[str.size()];
	strcpy_s(ch, str.size() + 1, str.c_str());
	if (_access(ch, 0) != -1)
		return true;
	else
		return false;
}
