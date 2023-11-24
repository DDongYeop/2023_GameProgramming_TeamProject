#pragma once

#include "define.h"

class FileMgr
{
	SINGLE(FileMgr);
public:
	void Init();
public:
	bool Exist(wstring& _path, wstring& name);
private:
	wstring filePath;
};

