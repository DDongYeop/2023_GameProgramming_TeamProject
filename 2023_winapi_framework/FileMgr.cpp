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
/// Ư�� ������ �����ϴ��� Ȯ���ϴ� �Լ�. 
/// </summary>
/// <param name="_path">GGM\\1_Grade\\Class_1\\ << ���ó�� ����Ͻø� �˴ϴ�.</param>
/// <param name="_name">.txt ���� �͵� �����־����.</param>
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
