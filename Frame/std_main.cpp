﻿// stdafx.cpp : source file that includes just the standard includes
//	App.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "std_main.h"

#if defined _M_IX86
#pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif

int CreatDir(const char *pDir)
{
	int i = 0;
	int iRet;
	int iLen;
	char* pszDir;
	if( NULL == pDir )
	{
		return 0;
	}
	pszDir = _strdup(pDir);
	iLen = strlen(pszDir);

	// 创建中间目录
	for (i = 0;i < iLen;i ++)
	{
		if (pszDir[i] == '\\' || pszDir[i] == '/')
		{ 
			pszDir[i] = '\0';
			iRet = ACCESS(pszDir,0);
			if (iRet != 0)
			{
				iRet = MKDIR(pszDir);
				if (iRet != 0)
				{
					return -1;
				} 
			}
			pszDir[i] = '/';
		}
	}
	//iRet = MKDIR(pszDir);
	free(pszDir);
	return iRet;
}