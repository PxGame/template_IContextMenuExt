// ContextMenuExt.cpp : CContextMenuExt 的实现

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

	// 从IDataObject接口中获取CF_HDROP数据

	if (FAILED(pDataObj->GetData(&fmt, &stg)))
		return E_INVALIDARG;

	// 获取指向实际数据的指针

	hDrop = (HDROP)GlobalLock(stg.hGlobal);

	if (hDrop == NULL)
	{
		ReleaseStgMedium(&stg);
		return E_INVALIDARG;
	}

	// 查询选择的文件数量

	uFilesCount = DragQueryFile(hDrop, 0xFFFFFFFF, NULL, 0);
	HRESULT hr = S_OK;
	if (0 == uFilesCount)
	{
		GlobalUnlock(stg.hGlobal);
		ReleaseStgMedium(&stg);
		return E_INVALIDARG;
	}
	// 将文件名称保存在变量中
	WCHAR szFile[MAX_PATH];
	for (int uFile = 0; uFile < uFilesCount; uFile++)
	{
		//取得下一个文件名.
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

	// 如果标志包含CMF_DEFAULTONLY 我们不作任何事情. 
	if (uFlags & CMF_DEFAULTONLY)
	{
		return MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_NULL, 0);
	}

	UINT uCmdID = uidFirstCmd;

	InsertMenu(hmenu, uMenuIndex, MF_STRING | MF_POPUP | MF_BYPOSITION,
		uCmdID++, _T("菜单一"));
	//SetMenuItemBitmaps用于设置图片
	uMenuIndex++;
	InsertMenu(hmenu, uMenuIndex, MF_STRING | MF_POPUP | MF_BYPOSITION,
		uCmdID++, _T("菜单二"));
	uMenuIndex++;
	InsertMenu(hmenu, uMenuIndex, MF_STRING | MF_POPUP | MF_BYPOSITION,
		uCmdID++, _T("菜单三"));
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


//处理菜单响应
STDMETHODIMP CContextMenuExt::InvokeCommand(LPCMINVOKECOMMANDINFO pCmdInfo)
{
	if (0 != HIWORD(pCmdInfo->lpVerb))
		return E_INVALIDARG;

	switch (LOWORD(pCmdInfo->lpVerb))
	{
	case 0:
		MessageBox(NULL, m_fileName[0].c_str(), _T("警告"), MB_OK);
		break;
	case 1:
		MessageBox(NULL, _T("菜单二"), _T("警告"), MB_OK);
		break;
	case 2:
		MessageBox(NULL, _T("菜单三"), _T("警告"), MB_OK);
		break;
	default:
		return E_INVALIDARG;
	}
	return S_OK;
}