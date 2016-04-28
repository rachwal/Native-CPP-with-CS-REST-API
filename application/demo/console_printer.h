// Created by Bartosz Rachwal. 
// Copyright (c) 2016 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved. 

#ifndef NATIVE_CPP_WITH_CS_REST_API_EXAMPLE_PRINTER_CONSOLE_PRINTER_H_
#define NATIVE_CPP_WITH_CS_REST_API_EXAMPLE_PRINTER_CONSOLE_PRINTER_H_

#include "print_observer.h"
#include "print_request_interface.h"

namespace native_cpp_with_cs_rest_api_example
{
	namespace printer
	{
		class ConsolePrinter : public print_request_monitor::PrintObserver
		{
		public:
			explicit ConsolePrinter(print_request_monitor::PrintRequestInterface* print_request);
			~ConsolePrinter();

			void OnPrint(const std::string& message) override;
	
		private:
			print_request_monitor::PrintRequestInterface* print_request_;
		};
	}
}

#endif

