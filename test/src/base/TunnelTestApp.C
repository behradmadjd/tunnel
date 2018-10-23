//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "TunnelTestApp.h"
#include "TunnelApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<TunnelTestApp>()
{
  InputParameters params = validParams<TunnelApp>();
  return params;
}

TunnelTestApp::TunnelTestApp(InputParameters parameters) : MooseApp(parameters)
{
  TunnelTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

TunnelTestApp::~TunnelTestApp() {}

void
TunnelTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  TunnelApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"TunnelTestApp"});
    Registry::registerActionsTo(af, {"TunnelTestApp"});
  }
}

void
TunnelTestApp::registerApps()
{
  registerApp(TunnelApp);
  registerApp(TunnelTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
TunnelTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  TunnelTestApp::registerAll(f, af, s);
}
extern "C" void
TunnelTestApp__registerApps()
{
  TunnelTestApp::registerApps();
}
