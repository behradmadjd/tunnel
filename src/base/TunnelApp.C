#include "TunnelApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<TunnelApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

TunnelApp::TunnelApp(InputParameters parameters) : MooseApp(parameters)
{
  TunnelApp::registerAll(_factory, _action_factory, _syntax);
}

TunnelApp::~TunnelApp() {}

void
TunnelApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"TunnelApp"});
  Registry::registerActionsTo(af, {"TunnelApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
TunnelApp::registerApps()
{
  registerApp(TunnelApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
TunnelApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  TunnelApp::registerAll(f, af, s);
}
extern "C" void
TunnelApp__registerApps()
{
  TunnelApp::registerApps();
}
