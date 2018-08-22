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

#ifndef GROUPINGTEST_H
#define GROUPINGTEST_H

#include "GeneralUserObject.h"
#include "GMaterialConstants.h"

class GroupingTest : public GMaterialConstants
{
public:
  GroupingTest(const InputParameters & parameters);

  Real absorb(int,int,std::string,std::string,Real,int,int) const;
  Real emit(int,int,Real,std::string,std::string,int,int) const;
  Real energy(int,std::string,std::string) const;
  Real D_prefactor(int,std::string) const;
  Real diff(int, std::string,Real) const;

private:
  Real _i_bias;
  Real _v_bias;
};

template<>
InputParameters validParams<GroupingTest>();

#endif
