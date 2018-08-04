//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "DGStagSodTestApp.h"
#include "DGStagSodApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<DGStagSodTestApp>()
{
  InputParameters params = validParams<DGStagSodApp>();
  return params;
}

DGStagSodTestApp::DGStagSodTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  DGStagSodApp::registerObjectDepends(_factory);
  DGStagSodApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  DGStagSodApp::associateSyntaxDepends(_syntax, _action_factory);
  DGStagSodApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  DGStagSodApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    DGStagSodTestApp::registerObjects(_factory);
    DGStagSodTestApp::associateSyntax(_syntax, _action_factory);
    DGStagSodTestApp::registerExecFlags(_factory);
  }
}

DGStagSodTestApp::~DGStagSodTestApp() {}

void
DGStagSodTestApp::registerApps()
{
  registerApp(DGStagSodApp);
  registerApp(DGStagSodTestApp);
}

void
DGStagSodTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
DGStagSodTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
DGStagSodTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
DGStagSodTestApp__registerApps()
{
  DGStagSodTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
DGStagSodTestApp__registerObjects(Factory & factory)
{
  DGStagSodTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
DGStagSodTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  DGStagSodTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
DGStagSodTestApp__registerExecFlags(Factory & factory)
{
  DGStagSodTestApp::registerExecFlags(factory);
}
