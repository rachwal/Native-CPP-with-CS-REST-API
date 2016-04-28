// Created by Bartosz Rachwal. 
// Copyright (c) 2016 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved. 

#include "print_rpc_client_native.h"

#include <rpc_interface/print_rpc.h>

#include <iostream>
#include <winbase.h>

namespace native_cpp_with_cs_rest_api_example
{
	namespace native_rpc
	{
		DWORD HandleError(DWORD error)
		{
			void* pBuffer = nullptr;
			FormatMessage(
				FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
				FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_MAX_WIDTH_MASK,
				nullptr,
				error,
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
				LPSTR(&pBuffer),
				0,
				nullptr);

			LocalFree(pBuffer);
			return error;
		}

		void PrintRpcClientNative::Print(const std::string& cmd)
		{
			RPC_STATUS status;
			unsigned char* string_binding = nullptr;

			status = RpcStringBindingCompose(
				nullptr,
				reinterpret_cast<unsigned char*>("ncacn_ip_tcp"),
				reinterpret_cast<unsigned char*>("localhost"),
				reinterpret_cast<unsigned char*>("4747"),
				nullptr,
				&string_binding);

			if (status)
			{
				return;
			}

			handle_t hBinding = nullptr;

			status = RpcBindingFromStringBinding(string_binding, &hBinding);

			if (status)
			{
				return;
			}

			status = RpcStringFree(&string_binding);

			if (status)
			{
				return;
			}

			status = RpcEpResolveBinding(hBinding, AutomationPlugin_v1_0_c_ifspec);

			if (status)
			{
				return;
			}

			RpcTryExcept;
			{
				auto context = Open(hBinding, cmd.c_str());
				Print_RPC(context);
				Close(&context);
			}

			RpcExcept(1)
			{
				HandleError(RpcExceptionCode());
			}

			RpcEndExcept;

			RpcBindingFree(&hBinding);
		}
	}
}

void* __RPC_USER midl_user_allocate(size_t size)
{
	return malloc(size);
}

void __RPC_USER midl_user_free(void* p)
{
	free(p);
}
