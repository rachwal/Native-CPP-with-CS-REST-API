// Created by Bartosz Rachwal. 
// Copyright (c) 2016 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved. 

#ifndef NATIVE_CPP_WITH_CS_REST_API_EXAMPLE_PRINT_REQUEST_MONITOR_PRINT_REQUEST_INTERFACE_H_
#define NATIVE_CPP_WITH_CS_REST_API_EXAMPLE_PRINT_REQUEST_MONITOR_PRINT_REQUEST_INTERFACE_H_

#include "print_observer.h"

namespace native_cpp_with_cs_rest_api_example
{
	namespace print_request_monitor
	{
		class PrintRequestInterface
		{
		public:
			virtual ~PrintRequestInterface() { }

			virtual void Attach(PrintObserver*) = 0;
			virtual void Detach(PrintObserver*) = 0;
			virtual void Print(const std::string& message) = 0;
		};
	}
}

#endif

