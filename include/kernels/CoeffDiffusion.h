#include "Diffusion.h"

#ifndef COEFFDIFFUSION_H
#define COEFFDIFFUSION_H

//Forward Declarations
class CoeffDiffusion;

/**
 * validParams returns the parameters that this Kernel accepts / needs
 * The actual body of the function MUST be in the .C file.
 */
template<>
InputParameters validParams<CoeffDiffusion>();

/**
 * Define the Kernel for a CoupledConvectionReactionSub operator that looks like:
 *
 * grad (diff * grad_u)
 *
 * This first line is defining the name and inheriting from Kernel.
 */
class CoeffDiffusion : public Diffusion
{
public:

  CoeffDiffusion(const  InputParameters & parameters);

protected:
  /**
   * Responsible for computing the residual at one quadrature point
   *
   * This should always be defined in the .C
   * @return The residual of dispersion-diffusion of Coeff species.
   */
  virtual Real computeQpResidual();
  /**
   * Responsible for computing the diagonal block of the preconditioning matrix.
   * This is essentially the partial derivative of the residual with respect to
   * the variable this kernel operates on ("u").
   *
   * Note that this can be an approximation or linearization.  In this case it's
   * not because the Jacobian of this operator is easy to calculate.
   *
   * This should always be defined in the .C
   * @return The diagonal jacobian of dispersion-diffusion of primary species.
   */
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

  /// Material property of dispersion-diffusion coefficient.
  //const MaterialProperty<Real> & _diffusivity;
  Real _diffusivity;
};
#endif //PRIMARYDIFFUSION_H
