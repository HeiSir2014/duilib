#include "std_main.h"
#include <exdisp.h>
#include <comdef.h>

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	HRESULT Hr = ::CoInitialize(NULL);
	if( FAILED(Hr) ) return 0;

	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath( CPaintManagerUI::GetInstancePath()+ _T("Skin\\"));
	//CPaintManagerUI::SetResourcePath( _T("E:\\project\\duilib_pro\\test\\") );
	
	//CMultiLanguage::SetLanguageFile( CDuiString( _T("localization\\") ) + CGlobalConfig::g_sLangFileName );
	CDlgPubilcChild* Dlg = new CDlgPubilcChild(_T("UI_Main.xml"));
	Dlg->ShowWnd(_T("DuiLib Test"));

	CPaintManagerUI::MessageLoop();
	CPaintManagerUI::Term();

	::CoUninitialize();
	return 0;
}