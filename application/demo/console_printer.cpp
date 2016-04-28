// Created by Bartosz Rachwal. 
// Copyright (c) 2016 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved. 

#include "console_printer.h"

#include <iostream>

namespace native_cpp_with_cs_rest_api_example
{
	namespace printer
	{
		ConsolePrinter::ConsolePrinter(print_request_monitor::PrintRequestInterface* print_request) :print_request_(print_request)
		{
			print_request_->Attach(this);
		}

		ConsolePrinter::~ConsolePrinter()
		{
			print_request_->Detach(this);
		}

		void ConsolePrinter::OnPrint(const std::string& message)
		{
			std::cout << message.c_str() << std::endl;
		}
	}
}