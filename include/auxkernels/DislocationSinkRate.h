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

#ifndef DISLOCATIONSINKRATE_H
#define DISLOCATIONSINKRATE_H

#include "AuxKernel.h"

//Forward Declarations
class DislocationSinkRate;

template<>
InputParameters validParams<DislocationSinkRate>();

class DislocationSinkRate : public AuxKernel
{
public:
  DislocationSinkRate(const InputParameters & parameters);

protected:
  virtual Real computeValue();

  std::string _prop_name_D;
  const MaterialProperty<Real> & _D_species;
  //Real _D_species;
  std::string _prop_name_DD;
  const MaterialProperty<Real> & _dislocation_density;
  const VariableValue & _varied_dislocation;
  Real _dislocation_core_size;
};

#endif // DISLOCATIONSINKRATE_H
