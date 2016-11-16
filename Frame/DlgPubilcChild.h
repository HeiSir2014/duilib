#pragma once
class CDirectDialog;

class CDlgPubilcChild :
	public CDirectDialog
{
public:
	CDlgPubilcChild(void);
	CDlgPubilcChild(CDuiString sSkinFileName,CDuiString sSkinDir = _T("skin"));
	~CDlgPubilcChild(void);

	virtual void InitWindow();
	virtual void OnClick(TNotifyUI& msg);
	virtual void OnItemActivate(TNotifyUI& msg);
	virtual void OnItemSelect(TNotifyUI& msg);
	virtual void OnValueChanged( TNotifyUI& msg );
	virtual void OnValueChanging( TNotifyUI& msg );
	virtual LRESULT OnMouseMove(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

	void SetScanProgress(int nValue);
	void OnScanProFinish();
	void Message(CDuiString sMsg);
private:
	POINT m_LastPos;
};

