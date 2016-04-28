// Created by Bartosz Rachwal. 
// Copyright (c) 2016 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved. 
//
// RPC References
// https://msdn.microsoft.com/en-us/library/windows/desktop/aa379010%28v=vs.85%29.aspx
// http://www.codeproject.com/Articles/4837/Introduction-to-RPC-Part
// http://www.codeproject.com/Articles/4878/Introduction-to-RPC-Part

#include "rpc_server.h"

#include <rpc_interface/print_rpc.h>

namespace native_cpp_with_cs_rest_api_example
{
	namespace rpc_server
	{
		RPC_STATUS CALLBACK SecurityCallback(RPC_IF_HANDLE, void*)
		{
			return RPC_S_OK;
		}

		DWORD WINAPI RpcServerListenThreadProc(LPVOID)
		{
			return RpcServerListen(1, RPC_C_LISTEN_MAX_CALLS_DEFAULT, FALSE);
		}

		void RpcServer::Run()
		{
			auto status = RpcServerUseProtseqEp(
				RPC_WSTR(L"ncacn_ip_tcp"),
				RPC_C_PROTSEQ_MAX_REQS_DEFAULT,
				RPC_WSTR(L"4747"),
				nullptr);

			if (status)
			{
				return;
			}
			
			status = RpcServerRegisterIf2(
				AutomationPlugin_v1_0_s_ifspec,
				nullptr,
				nullptr,
				RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH,
				RPC_C_LISTEN_MAX_CALLS_DEFAULT,
				unsigned(-1),
				SecurityCallback);

			if (status)
			{
				return;
			}

			status = RpcServerListen(
				1, 
				RPC_C_LISTEN_MAX_CALLS_DEFAULT, 
				FALSE);
		}
	}
}
