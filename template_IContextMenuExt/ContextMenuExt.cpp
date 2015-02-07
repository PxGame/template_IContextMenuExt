// ContextMenuExt.cpp : CContextMenuExt ��ʵ��

#include "stdafx.h"
#include "ContextMenuExt.h"


// CContextMenuExt

STDMETHODIMP CContextMenuExt::Initialize(LPCITEMIDLIST pidlFolder,
	LPDATAOBJECT pDataObj,
	HKEY hProgID)
{
	FORMATETC	fmt = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
	STGMEDIUM	stg = { TYMED_HGLOBAL };
	HDROP		hDrop = NULL;

	// ��IDataObject�ӿ��л�ȡCF_HDROP����

	if (FAILED(pDataObj->GetData(&fmt, &stg)))
		return E_INVALIDARG;

	// ��ȡָ��ʵ�����ݵ�ָ��

	hDrop = (HDROP)GlobalLock(stg.hGlobal);

	if (hDrop == NULL)
	{
		ReleaseStgMedium(&stg);
		return E_INVALIDARG;
	}

	// ��ѯѡ����ļ�����

	uFilesCount = DragQueryFile(hDrop, 0xFFFFFFFF, NULL, 0);
	HRESULT hr = S_OK;
	if (0 == uFilesCount)
	{
		GlobalUnlock(stg.hGlobal);
		ReleaseStgMedium(&stg);
		return E_INVALIDARG;
	}
	// ���ļ����Ʊ����ڱ�����
	WCHAR szFile[MAX_PATH];
	for (int uFile = 0; uFile < uFilesCount; uFile++)
	{
		//ȡ����һ���ļ���.
		if (0 == DragQueryFile(hDrop, uFile, szFile, MAX_PATH))
			continue;
		m_fileName.push_back(szFile);
	}

	GlobalUnlock(stg.hGlobal);
	ReleaseStgMedium(&stg);


	return S_OK;

}

STDMETHODIMP CContextMenuExt::QueryContextMenu(HMENU hmenu,
	UINT uMenuIndex,
	UINT uidFirstCmd,
	UINT uidLastCmd,
	UINT uFlags)
{

	// �����־����CMF_DEFAULTONLY ���ǲ����κ�����. 
	if (uFlags & CMF_DEFAULTONLY)
	{
		return MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_NULL, 0);
	}

	UINT uCmdID = uidFirstCmd;

	InsertMenu(hmenu, uMenuIndex, MF_STRING | MF_POPUP | MF_BYPOSITION,
		uCmdID++, _T("�˵�һ"));
	//SetMenuItemBitmaps��������ͼƬ
	uMenuIndex++;
	InsertMenu(hmenu, uMenuIndex, MF_STRING | MF_POPUP | MF_BYPOSITION,
		uCmdID++, _T("�˵���"));
	uMenuIndex++;
	InsertMenu(hmenu, uMenuIndex, MF_STRING | MF_POPUP | MF_BYPOSITION,
		uCmdID++, _T("�˵���"));
	uMenuIndex++;
	return MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_NULL, 3);

}

STDMETHODIMP CContextMenuExt::GetCommandString(UINT_PTR idCmd,
	UINT uFlags,
	UINT* pwReserved,
	LPSTR pszName,
	UINT cchMax)
{
	return E_NOTIMPL;
}


//����˵���Ӧ
STDMETHODIMP CContextMenuExt::InvokeCommand(LPCMINVOKECOMMANDINFO pCmdInfo)
{
	if (0 != HIWORD(pCmdInfo->lpVerb))
		return E_INVALIDARG;

	switch (LOWORD(pCmdInfo->lpVerb))
	{
	case 0:
		MessageBox(NULL, m_fileName[0].c_str(), _T("����"), MB_OK);
		break;
	case 1:
		MessageBox(NULL, _T("�˵���"), _T("����"), MB_OK);
		break;
	case 2:
		MessageBox(NULL, _T("�˵���"), _T("����"), MB_OK);
		break;
	default:
		return E_INVALIDARG;
	}
	return S_OK;
}