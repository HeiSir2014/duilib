#include "std_main.h"
#include "DlgPubilcChild.h"

CDlgPubilcChild::CDlgPubilcChild(void)
{
}

CDlgPubilcChild::CDlgPubilcChild(CDuiString sSkinFileName,CDuiString sSkinDir):CDirectDialog(sSkinFileName,sSkinDir)
{
}

CDlgPubilcChild::~CDlgPubilcChild(void)
{
}

void CDlgPubilcChild::InitWindow()
{
	if( GetSkinFile() == _T("UI_SearchResult.xml"))
	{
		
	}
}

void CDlgPubilcChild::OnClick(TNotifyUI& msg)
{
	CDuiString sName = msg.pSender->GetName();
	CDlgPubilcChild* dlg = NULL;

	if (sName.IsEmpty())
	{
		return;
	}
	else if (sName == _T("BtnExit"))
	{
		Close(1);
	}
	else if(GetSkinFile() == _T("UI_Manage.xml"))
	{
		
	}
	if (dlg)
	{
		dlg->ShowWnd( *this ,_T("") , true , false );
	}

	CDirectDialog::OnClick(msg);
}


LRESULT CDlgPubilcChild::OnMouseMove(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if( wParam == MK_LBUTTON && GetSkinFile() == _T("UI_Print.xml"))
	{
		int x = lParam >> 16;
		int y = lParam & 0x0000FFFF ;

		if (m_LastPos.x == 0 && m_LastPos.y == 0)
		{
			m_LastPos.x = x;
			m_LastPos.y = y;
		}
		else if(m_LastPos.y != y)
		{
			CVerticalLayoutUI* tView =(CVerticalLayoutUI*) this->m_PaintManager.FindControl(_T("VerticalLayoutView"));
			if(tView)
			{
				SIZE pos = tView->GetScrollPos();

				pos.cy += m_LastPos.y > y ? 10 : -10;

				tView->SetScrollPos(pos);
			}

			m_LastPos.x = x;
			m_LastPos.y = y;
		}
	}
	return CDirectDialog::OnMouseMove(uMsg,  wParam,  lParam, bHandled);
}

LRESULT CDlgPubilcChild::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return CDirectDialog::HandleMessage(uMsg,wParam,lParam);
}

void CDlgPubilcChild::OnItemSelect( TNotifyUI& msg )
{
	
}

void CDlgPubilcChild::OnValueChanged( TNotifyUI& msg )
{
	
}

void CDlgPubilcChild::OnValueChanging( TNotifyUI& msg )
{
	
}

void CDlgPubilcChild::OnItemActivate(TNotifyUI& msg)
{
	
}

void CDlgPubilcChild::Message(CDuiString sMsg)
{
	CLabelUI* tMsg = (CLabelUI*) m_PaintManager.FindControl(_T("message"));
	if (tMsg)
	{
		tMsg->SetText(sMsg);
	}
}