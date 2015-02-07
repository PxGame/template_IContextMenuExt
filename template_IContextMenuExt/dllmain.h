// dllmain.h : 模块类的声明。

class Ctemplate_IContextMenuExtModule : public ATL::CAtlDllModuleT< Ctemplate_IContextMenuExtModule >
{
public :
	DECLARE_LIBID(LIBID_template_IContextMenuExtLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_TEMPLATE_ICONTEXTMENUEXT, "{F03649AE-22CC-4A62-8A07-73481A407A65}")
};

extern class Ctemplate_IContextMenuExtModule _AtlModule;
