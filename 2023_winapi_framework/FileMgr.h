#pragma once

#include "define.h"

class FileMgr
{
	SINGLE(FileMgr);
public:
	FileMgr();
	~FileMgr();
public:
	bool Exist(wstring path, wstring name);
};

