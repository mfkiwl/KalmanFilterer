#ifndef WHITENOISESYSTEMFACTORY_H
#define WHITENOISESYSTEMFACTORY_H

#pragma GCC diagnostic push

#include <boost/shared_ptr.hpp>
#include "whitenoisesystem.h"
#pragma GCC diagnostic pop

#include "whitenoisesystemparameters.h"

namespace ribi {
namespace kalman {

struct WhiteNoiseSystemFactory
{
  WhiteNoiseSystemFactory();

  boost::shared_ptr<WhiteNoiseSystem> Create(
    const boost::shared_ptr<WhiteNoiseSystemParameters>& parameters) const noexcept;

};

} //~namespace kalman
} //~namespace ribi

#endif // WHITENOISESYSTEMFACTORY_H
