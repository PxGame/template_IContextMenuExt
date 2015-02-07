

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sat Feb 07 15:19:27 2015
 */
/* Compiler settings for template_IContextMenuExt.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __template_IContextMenuExt_i_h__
#define __template_IContextMenuExt_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IContextMenuExt_FWD_DEFINED__
#define __IContextMenuExt_FWD_DEFINED__
typedef interface IContextMenuExt IContextMenuExt;

#endif 	/* __IContextMenuExt_FWD_DEFINED__ */


#ifndef __ContextMenuExt_FWD_DEFINED__
#define __ContextMenuExt_FWD_DEFINED__

#ifdef __cplusplus
typedef class ContextMenuExt ContextMenuExt;
#else
typedef struct ContextMenuExt ContextMenuExt;
#endif /* __cplusplus */

#endif 	/* __ContextMenuExt_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IContextMenuExt_INTERFACE_DEFINED__
#define __IContextMenuExt_INTERFACE_DEFINED__

/* interface IContextMenuExt */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IContextMenuExt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("632603BC-907F-4655-B04F-2C1F8B52D70D")
    IContextMenuExt : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IContextMenuExtVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IContextMenuExt * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IContextMenuExt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IContextMenuExt * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IContextMenuExt * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IContextMenuExt * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IContextMenuExt * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IContextMenuExt * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IContextMenuExtVtbl;

    interface IContextMenuExt
    {
        CONST_VTBL struct IContextMenuExtVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IContextMenuExt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IContextMenuExt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IContextMenuExt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IContextMenuExt_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IContextMenuExt_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IContextMenuExt_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IContextMenuExt_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IContextMenuExt_INTERFACE_DEFINED__ */



#ifndef __template_IContextMenuExtLib_LIBRARY_DEFINED__
#define __template_IContextMenuExtLib_LIBRARY_DEFINED__

/* library template_IContextMenuExtLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_template_IContextMenuExtLib;

EXTERN_C const CLSID CLSID_ContextMenuExt;

#ifdef __cplusplus

class DECLSPEC_UUID("49A4CD72-02F5-47BB-B7C4-A4C6848948E7")
ContextMenuExt;
#endif
#endif /* __template_IContextMenuExtLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


