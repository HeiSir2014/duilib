#pragma once
namespace DuiLib {

class UILIB_API CMultiLanguage
{
public:
	CMultiLanguage(void);
	~CMultiLanguage(void);
	// ͨ�� XML ���ö����Խ���
	static bool SetLanguageFile(LPCTSTR sFilePath);
	static CDuiString GetMultiValue(LPCTSTR sId);
private:
	
};

} // namespace DuiLib
