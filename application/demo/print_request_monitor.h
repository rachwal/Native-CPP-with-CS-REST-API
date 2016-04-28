// Created by Bartosz Rachwal. 
// Copyright (c) 2016 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved. 

#ifndef NATIVE_CPP_WITH_CS_REST_API_EXAMPLE_PRINT_REQUEST_MONITOR_PRINT_REQUEST_MONITOR_H_
#define NATIVE_CPP_WITH_CS_REST_API_EXAMPLE_PRINT_REQUEST_MONITOR_PRINT_REQUEST_MONITOR_H_

#include "print_request_interface.h"

namespace native_cpp_with_cs_rest_api_example
{
	namespace print_request_monitor
	{
		class PrintRequestMonitor: public PrintRequestInterface
		{
		public:
			~PrintRequestMonitor();

			static PrintRequestInterface* Instance();

			void Print(const std::string& message) override;

			void Attach(PrintObserver* observer_interface) override;
			void Detach(PrintObserver* observer_interface) override;

		private:
			PrintRequestMonitor();

			static PrintRequestInterface* instance_;
		};
	}
}

#endif

