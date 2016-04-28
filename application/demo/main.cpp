// Created by Bartosz Rachwal. 
// Copyright (c) 2016 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved. 

#include "rpc_server.h"
#include "console_printer.h"
#include "print_request_monitor.h"

int main()
{
	using namespace native_cpp_with_cs_rest_api_example;

	auto printer_monitor = print_request_monitor::PrintRequestMonitor::Instance();
	auto printer = printer::ConsolePrinter(printer_monitor);

	auto server = rpc_server::RpcServer();
	server.Run();

    return 0;
}

