// Created by Bartosz Rachwal. 
// Copyright (c) 2016 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved. 

#include "print_request.h"

namespace native_cpp_with_cs_rest_api_example
{
	namespace print_request_monitor
	{
		PrintRequest::PrintRequest()
		{
			observers_ = std::make_unique<std::list<PrintObserver*>>();
		}

		PrintRequest::~PrintRequest()
		{
			observers_->clear();
		}

		void PrintRequest::Attach(PrintObserver* o)
		{
			observers_->push_back(o);
		}

		void PrintRequest::Detach(PrintObserver* o)
		{
			observers_->remove(o);
		}

		void PrintRequest::Print(const std::string& message)
		{
			for (auto iterator = observers_->begin(); iterator != observers_->end(); ++iterator)
			{
				auto current_item = *iterator;
				current_item->OnPrint(message);
			}
		}
	}
}