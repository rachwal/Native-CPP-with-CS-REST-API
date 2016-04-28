// Created by Bartosz Rachwal. 
// Copyright (c) 2016 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved. 


using native_cpp_with_cs_rest_api_example.cli_rpc;

namespace Api.Demo
{
    public class DemoClient : IDemoClient
    {
        private PrintRpcClientCli plugin;

        public void Print(string cmd)
        {
            if (plugin == null)
            {
                plugin = new PrintRpcClientCli();
            }
            plugin.Print(cmd);
        }
    }
}