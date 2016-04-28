// Created by Bartosz Rachwal. 
// Copyright (c) 2016 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved. 

#include "print_request_monitor.h"
#include "print_request.h"

#include <mutex>

namespace native_cpp_with_cs_rest_api_example
{
	namespace print_request_monitor
	{
		PrintRequestMonitor::PrintRequestMonitor() {}

		PrintRequestInterface* PrintRequestMonitor::instance_ = nullptr;

		PrintRequestMonitor::~PrintRequestMonitor()
		{
			delete instance_;
		}

		PrintRequestInterface* PrintRequestMonitor::Instance()
		{
			if (!instance_)
			{
				std::mutex m;
				m.lock();
				if (!instance_)
				{
					instance_ = new PrintRequest();
				}
				m.unlock();
			}
			return instance_;
		}

		void PrintRequestMonitor::Print(const std::string& message)
		{
			Instance()->Print(message);
		}

		void PrintRequestMonitor::Attach(PrintObserver* o)
		{
			Instance()->Attach(o);
		}

		void PrintRequestMonitor::Detach(PrintObserver* o)
		{
			Instance()->Detach(o);
		}
	}
}
