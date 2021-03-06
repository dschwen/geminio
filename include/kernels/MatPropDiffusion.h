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

#ifndef MATPROPDIFFUSION_H
#define MATPROPDIFFUSION_H

#include "Diffusion.h"

//Forward Declarations
class MatPropDiffusion;

/**
 * validParams returns the parameters that this Kernel accepts / needs
 * The actual body of the function MUST be in the .C file.
 */
template<>
InputParameters validParams<MatPropDiffusion>();

class MatPropDiffusion : public Diffusion
{
public:

  MatPropDiffusion(const 
                   InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  /**
   * This MooseArray will hold the reference we need to our
   * material property from the Material class
   */

// This is an abstracted way to get different diffusivities, calculated by materials, into this kernel

  std::string _prop_name;
  const MaterialProperty<Real> & _D_species;

};
#endif //MATPROPDIFFUSION_H
