// Created by Bartosz Rachwal. 
// Copyright (c) 2016 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved. 

using Api.Configuration;
using Api.Demo;
using Api.Manager;
using Microsoft.Practices.Unity;

namespace Api.Starter
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            RunComponent(args);
            WaitForExit();
        }

        private static void RunComponent(string[] args)
        {
            var container = new UnityContainer();
            container.RegisterType<IDemoClient, DemoClient>();
            container.RegisterType<IDemoController, DemoController>();

            container.RegisterType<IStartup, Startup>();
            container.RegisterType<IApiManager, ApiManager>(new ContainerControlledLifetimeManager());

            container.RegisterType<IComponentConfiguration, ComponentConfiguration>(
                new ContainerControlledLifetimeManager());
            container.Resolve<IApiManager>().StartAsync();
        }

        private static void WaitForExit()
        {
            var run = true;
            while (run)
            {
                var text = System.Console.ReadLine();
                if (string.IsNullOrEmpty(text))
                    continue;
                if (text.Trim().ToLower().Equals("exit"))
                {
                    run = false;
                }
            }
        }
    }
}