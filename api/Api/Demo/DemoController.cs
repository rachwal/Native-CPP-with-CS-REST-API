// Created by Bartosz Rachwal. 
// Copyright (c) 2016 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved. 

using System.Web.Http;
using Microsoft.Practices.Unity;

namespace Api.Demo
{
    public class DemoController : ApiController, IDemoController
    {
        [Dependency]
        public IDemoClient Client { get; set; }

        public string Get(string cmd)
        {
            Client.Print(cmd);
            return "OK";
        }
    }
}