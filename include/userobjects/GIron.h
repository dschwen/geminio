/*************************************************/
/*           DO NOT MODIFY THIS HEADER           */
/*                                               */
/*                     BISON                     */
/*                                               */
/*    (c) 2015 Battelle Energy Alliance, LLC     */
/*            ALL RIGHTS RESERVED                */
/*                                               */
/*   Prepared by Battelle Energy Alliance, LLC   */
/*     Under Contract No. DE-AC07-05ID14517      */
/*     With the U. S. Department of Energy       */
/*                                               */
/*     See COPYRIGHT for full restrictions       */
/*************************************************/

#ifndef GIRON_H
#define GIRON_H

#include "GeneralUserObject.h"
#include "GMaterialConstants.h"

class GIron : public GMaterialConstants
{
public:
  GIron(const InputParameters & parameters);

  ~GIron(){}
  virtual void initialize();
  virtual void execute();
  virtual void finalize();

  Real absorb(int,int,std::string,std::string,double,int,int) const;
  Real emit(int,int,double,std::string,std::string,int,int) const;
  Real disl_ksq(int,std::string,double,int=1) const;
  double energy(int,std::string,std::string) const;
  double D_prefactor(int,std::string) const;
  double diff(int, std::string,double) const;

private:
  double Ev_formation,Ei_formation,Evb2,Eib2;//description in cpp file
  double Ei_binding_factor;
  double Ev_binding_factor;
};

template<>
InputParameters validParams<GIron>();

#endif
