//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef TUNNELAPP_H
#define TUNNELAPP_H

#include "MooseApp.h"

class TunnelApp;

template <>
InputParameters validParams<TunnelApp>();

class TunnelApp : public MooseApp
{
public:
  TunnelApp(InputParameters parameters);
  virtual ~TunnelApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s);
};

#endif /* TUNNELAPP_H */
