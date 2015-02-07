// ContextMenuExt.h : CContextMenuExt 的声明

#pragma once
#include "resource.h"       // 主符号



# include "template_IContextMenuExt_i.h"
# include <ShlObj.h>
# include <AtlCom.h>
# include <vector>




#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CContextMenuExt

class ATL_NO_VTABLE CContextMenuExt :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CContextMenuExt, &CLSID_ContextMenuExt>,
	public IDispatchImpl<IContextMenuExt, &IID_IContextMenuExt, &LIBID_template_IContextMenuExtLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IShellExtInit,
	public IContextMenu
{
public:
	CContextMenuExt()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CONTEXTMENUEXT)


BEGIN_COM_MAP(CContextMenuExt)
	COM_INTERFACE_ENTRY(IContextMenuExt)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IShellExtInit)
	COM_INTERFACE_ENTRY(IContextMenu)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	STDMETHOD(Initialize)(LPCITEMIDLIST, LPDATAOBJECT, HKEY);

	STDMETHOD(GetCommandString)(UINT_PTR, UINT, UINT*, LPSTR, UINT);

	STDMETHOD(InvokeCommand)(LPCMINVOKECOMMANDINFO);

	STDMETHOD(QueryContextMenu)(HMENU, UINT, UINT, UINT, UINT);

private:
	int uFilesCount;
	std::vector<std::wstring> m_fileName;

};

OBJECT_ENTRY_AUTO(__uuidof(ContextMenuExt), CContextMenuExt)
