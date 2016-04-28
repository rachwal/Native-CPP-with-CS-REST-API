// Created by Bartosz Rachwal. 
// Copyright (c) 2016 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved. 

using Owin;

namespace Api.Manager
{
    public interface IStartup
    {
        void Configuration(IAppBuilder appBuilder);
    }
}