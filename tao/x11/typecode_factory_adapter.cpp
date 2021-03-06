/**
 * @file    typecode_factory_adapter.cpp
 * @author  Martin Corino
 *
 * @brief   TypeCode factory adapter
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 */

#include "tao/x11/typecode_factory_adapter.h"
#include "tao/x11/orb.h"

#if (TAO_HAS_MINIMUM_CORBA == 0) && !defined (CORBA_E_COMPACT) && !defined (CORBA_E_MICRO)

namespace TAOX11_NAMESPACE
{
  std::string TypecodeFactoryAdapter::concrete_adapter_name_;

} //  namespace TAOX11_NAMESPACE

#endif /* (TAO_HAS_MINIMUM_CORBA == 0) && !CORBA_E_COMPACT && !CORBA_E_MICRO */
