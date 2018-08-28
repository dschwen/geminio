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

#ifndef DISLOCATIONSINK_H
#define DISLOCATIONSINK_H

#include "Kernel.h"

//Forward Declarations
class DislocationSink;

template<>
InputParameters validParams<DislocationSink>();

class DislocationSink : public Kernel
{
public:
  DislocationSink(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

  //std::string _prop_name_D;
  //const MaterialProperty<Real> & _D_species;
  Real _D_species;
  std::string _prop_name_DD;
  const MaterialProperty<Real> * const _dislocation_density;
  const VariableValue & _varied_dislocation;
  Real _rho_disl;
  Real _dislocation_core_size;
  Real _coef;
};

#endif // DISLOCATIONSINK_H
