// Created by Bartosz Rachwal. 
// Copyright (c) 2016 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved. 

using System;

namespace Api.Configuration
{
    public interface IComponentConfiguration
    {
        int Port { get; set; }
        string Host { get; set; }
        event EventHandler ConfigurationChanged;
    }
}