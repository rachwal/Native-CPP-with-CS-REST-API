

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Thu Apr 28 17:08:12 2016
 */
/* Compiler settings for print_rpc.idl:
    Oicf, W4, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603 
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


#ifndef __print_rpc_h__
#define __print_rpc_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __AutomationPlugin_INTERFACE_DEFINED__
#define __AutomationPlugin_INTERFACE_DEFINED__

/* interface AutomationPlugin */
/* [implicit_handle][helpstring][version][uuid] */ 

typedef /* [context_handle] */ void *CONTEXT_HANDLE;

CONTEXT_HANDLE Open( 
    /* [in] */ handle_t binding_handle,
    /* [string][in] */ const char *command);

void Print_RPC( 
    /* [in] */ CONTEXT_HANDLE ctx_handle);

void Close( 
    /* [out][in] */ CONTEXT_HANDLE *ctx_handle_ptr);


extern handle_t AutomationPluginRpcBinding;


extern RPC_IF_HANDLE AutomationPlugin_v1_0_c_ifspec;
extern RPC_IF_HANDLE AutomationPlugin_v1_0_s_ifspec;
#endif /* __AutomationPlugin_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

void __RPC_USER CONTEXT_HANDLE_rundown( CONTEXT_HANDLE );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


