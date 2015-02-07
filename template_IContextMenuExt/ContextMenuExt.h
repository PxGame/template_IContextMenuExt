// ContextMenuExt.h : CContextMenuExt ������

#pragma once
#include "resource.h"       // ������



# include "template_IContextMenuExt_i.h"
# include <ShlObj.h>
# include <AtlCom.h>
# include <vector>




#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
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
