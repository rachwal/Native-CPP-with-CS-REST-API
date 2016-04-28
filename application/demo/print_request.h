// Created by Bartosz Rachwal. 
// Copyright (c) 2016 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved. 

#ifndef NATIVE_CPP_WITH_CS_REST_API_EXAMPLE_PRINT_REQUEST_MONITOR_PRINT_REQUEST_H_
#define NATIVE_CPP_WITH_CS_REST_API_EXAMPLE_PRINT_REQUEST_MONITOR_PRINT_REQUEST_H_

#include "print_request_interface.h"

#include <list>
#include <memory>

namespace native_cpp_with_cs_rest_api_example
{
	namespace print_request_monitor
	{
		class PrintRequest : public PrintRequestInterface
		{
		public:
			PrintRequest();
			~PrintRequest();

			void Attach(PrintObserver*) override;
			void Detach(PrintObserver*) override;
			void Print(const std::string& message) override;

		private:
			std::unique_ptr<std::list<PrintObserver*>> observers_;
		};
	}
}

#endif

