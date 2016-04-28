// Created by Bartosz Rachwal. 
// Copyright (c) 2016 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved. 
//
// RPC References
// https://msdn.microsoft.com/en-us/library/windows/desktop/aa379010%28v=vs.85%29.aspx
// http://www.codeproject.com/Articles/4837/Introduction-to-RPC-Part
// http://www.codeproject.com/Articles/4878/Introduction-to-RPC-Part

#include "rpc_server.h"
#include "print_request_monitor.h"

#include <rpc_interface/print_rpc.h>

DWORD HandleError(DWORD error)
{
	void* pBuffer = nullptr;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_MAX_WIDTH_MASK,
		nullptr,
		error,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		LPTSTR(&pBuffer),
		0,
		nullptr);

	LocalFree(pBuffer);
	return error;
}

CONTEXT_HANDLE Open(handle_t binding_handle, const char* command)
{
	auto context = new std::string(command);
	CONTEXT_HANDLE ctx_handle = context;
	return ctx_handle;
}

void Print_RPC(CONTEXT_HANDLE ctx_handle)
{
	auto message = static_cast<std::string*>(ctx_handle);
	native_cpp_with_cs_rest_api_example::print_request_monitor::PrintRequestMonitor::Instance()->Print(message->c_str());
}

void Close(CONTEXT_HANDLE* ctx_handle_ptr)
{
	auto ctx_ptr = static_cast<std::string*>(*ctx_handle_ptr);
	delete ctx_ptr;
	*ctx_handle_ptr = nullptr;
}

void __RPC_USER CONTEXT_HANDLE_rundown(CONTEXT_HANDLE ctx_handle)
{
	Close(&ctx_handle);
}

void* __RPC_USER midl_user_allocate(size_t size)
{
	return malloc(size);
}

void __RPC_USER midl_user_free(void* p)
{
	free(p);
}