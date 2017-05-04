/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef ADDLOTSOFFUNCTION_H
#define ADDLOTSOFFUNCTION_H

#include "AddFunctionAction.h"

class AddLotsOfFunction;

template<>
InputParameters validParams<AddLotsOfFunction>();


class AddLotsOfFunction : public AddFunctionAction
{
public:
  AddLotsOfFunction(const  InputParameters & parameters);

  virtual void act();
};

#endif // AddLotsOfFunction_H
