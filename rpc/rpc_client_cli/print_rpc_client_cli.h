// Created by Bartosz Rachwal. 
// Copyright (c) 2016 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved. 

#ifndef NATIVE_CPP_WITH_CS_REST_API_EXAMPLE_RPC_CLIENT_CLI_PRINT_RPC_CLIENT_CLI_H_
#define NATIVE_CPP_WITH_CS_REST_API_EXAMPLE_RPC_CLIENT_CLI_PRINT_RPC_CLIENT_CLI_H_

#include <rpc_client_native/print_rpc_client_native.h>

namespace native_cpp_with_cs_rest_api_example
{
	namespace cli_rpc
	{
		public ref class PrintRpcClientCli
		{
		private:
			native_cpp_with_cs_rest_api_example::native_rpc::PrintRpcClientNative* ptr;

		public:
			PrintRpcClientCli();
			~PrintRpcClientCli();
			!PrintRpcClientCli();

			void Print(System::String^ cmd);
		};
	}
}
#endif