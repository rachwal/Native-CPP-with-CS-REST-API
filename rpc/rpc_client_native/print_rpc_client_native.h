// Created by Bartosz Rachwal. 
// Copyright (c) 2016 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved. 

#ifndef NATIVE_CPP_WITH_CS_REST_API_EXAMPLE_RPC_CLIENT_NATIVE_PRINT_RPC_CLIENT_NATIVE_H_
#define NATIVE_CPP_WITH_CS_REST_API_EXAMPLE_RPC_CLIENT_NATIVE_PRINT_RPC_CLIENT_NATIVE_H_

#include <string>

namespace native_cpp_with_cs_rest_api_example
{
	namespace native_rpc
	{
		class PrintRpcClientNative
		{
		public:
			static void Print(const std::string& cmd);
		};
	}
}
#endif
