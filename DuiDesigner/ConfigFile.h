#include "stdafx.h"
#include <sstream>
#include <iostream> 

using namespace std;

class CConfigFile
{
public:
	CConfigFile()
	{

	};
	CConfigFile(char * Name)
	{
		sConfigFilePath = Name;
	};
	CConfigFile(LPCTSTR Name)
	{
		sConfigFilePath = Name;
	};
	CConfigFile(string Name):sConfigFilePath(Name.c_str())
	{
	};
	//BOOL SetValues(char * sKey,char * sValue)
	//{
	//	return ::WritePrivateProfileString(_T("Setting"), sKey, sValue, IniFileName.c_str());
	//};
	BOOL SetValues(LPCTSTR sKey,LPCTSTR sValue)
	{
		return ::WritePrivateProfileString(_T("Setting"), sKey, sValue, sConfigFilePath);
	};

	void GetValues(LPCTSTR Section,CString & sRetString,LPCTSTR DefaultText = NULL)
	{
		sRetString.Empty();

		TCHAR sValue[4096] = {0};
		size_t nReadCount = ::GetPrivateProfileString(_T("Setting"), Section, DefaultText, sValue, 4096, sConfigFilePath);
		sRetString = sValue;
	};

protected:

private:
	CString sConfigFilePath;
};