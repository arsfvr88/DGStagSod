#include "DGStagSodApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<DGStagSodApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

DGStagSodApp::DGStagSodApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  DGStagSodApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  DGStagSodApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  DGStagSodApp::registerExecFlags(_factory);
}

DGStagSodApp::~DGStagSodApp() {}

void
DGStagSodApp::registerApps()
{
  registerApp(DGStagSodApp);
}

void
DGStagSodApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"DGStagSodApp"});
}

void
DGStagSodApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"DGStagSodApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
DGStagSodApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
DGStagSodApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
DGStagSodApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
DGStagSodApp__registerApps()
{
  DGStagSodApp::registerApps();
}

extern "C" void
DGStagSodApp__registerObjects(Factory & factory)
{
  DGStagSodApp::registerObjects(factory);
}

extern "C" void
DGStagSodApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  DGStagSodApp::associateSyntax(syntax, action_factory);
}

extern "C" void
DGStagSodApp__registerExecFlags(Factory & factory)
{
  DGStagSodApp::registerExecFlags(factory);
}
