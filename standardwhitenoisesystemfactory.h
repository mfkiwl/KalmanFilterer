#ifndef STANDARDWHITENOISESYSTEMFACTORY_H
#define STANDARDWHITENOISESYSTEMFACTORY_H




#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>


#include "standardwhitenoisesystem.h"

namespace ribi {
namespace kalman {

struct StandardWhiteNoiseSystemFactory
{
  StandardWhiteNoiseSystemFactory();

  boost::shared_ptr<StandardWhiteNoiseSystem> Create(
    const boost::numeric::ublas::matrix<double>& control,
    const boost::numeric::ublas::vector<double>& initial_state,
    const boost::numeric::ublas::vector<double>&
      real_msm_noise, // real_measurement_noise
    const boost::numeric::ublas::vector<double>& real_process_noise,
    const boost::numeric::ublas::matrix<double>& state_transition
  ) const noexcept;

  boost::shared_ptr<StandardWhiteNoiseSystem> Create(
    const boost::shared_ptr<WhiteNoiseSystemParameters>& parameters
  ) const noexcept;

};

} //~namespace kalman
} //~namespace ribi

#endif // STANDARDWHITENOISESYSTEMFACTORY_H
