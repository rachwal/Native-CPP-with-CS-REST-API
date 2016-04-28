// Created by Bartosz Rachwal. 
// Copyright (c) 2016 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved. 

#ifndef NATIVE_CPP_WITH_CS_REST_API_EXAMPLE_PRINT_REQUEST_MONITOR_PRINT_OBSERVER_H_
#define NATIVE_CPP_WITH_CS_REST_API_EXAMPLE_PRINT_REQUEST_MONITOR_PRINT_OBSERVER_H_

#include <iostream>

namespace native_cpp_with_cs_rest_api_example
{
	namespace print_request_monitor
	{
		class PrintObserver
		{
		public:
			virtual ~PrintObserver() { }

			virtual void OnPrint(const std::string& message) = 0;
		};
	}
}

#endif

