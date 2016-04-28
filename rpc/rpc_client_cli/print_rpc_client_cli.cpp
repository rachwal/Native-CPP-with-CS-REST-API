// Created by Bartosz Rachwal. 
// Copyright (c) 2016 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved. 

#include "stdafx.h"
#include "print_rpc_client_cli.h"

#include <rpc_interface/print_rpc.h>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

namespace native_cpp_with_cs_rest_api_example
{
	namespace cli_rpc
	{
		using namespace native_cpp_with_cs_rest_api_example::native_rpc;

		PrintRpcClientCli::PrintRpcClientCli()
		{
			ptr = new PrintRpcClientNative();
		}

		PrintRpcClientCli::~PrintRpcClientCli()
		{
			this->!PrintRpcClientCli();
		}

		PrintRpcClientCli::!PrintRpcClientCli()
		{
			delete ptr;
			ptr = nullptr;
		}

		void PrintRpcClientCli::Print(System::String^ cmd)
		{
			if (!ptr)
			{
				ptr = new PrintRpcClientNative();
			}

			std::string stdString = msclr::interop::marshal_as<std::string>(cmd);
			ptr->Print(stdString);
		};
	};
}