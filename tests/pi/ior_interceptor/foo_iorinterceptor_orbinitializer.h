/**
 * @file    foo_iorinterceptor_orbinitializer.h
 * @author  Martin Corino
 *
 * @brief   Implementation for the "FOO" IOR test interceptor ORB
 *          initializer.
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 */
#ifndef FOO_IOR_INTERCEPTOR_ORB_INITIALIZER_H
#define FOO_IOR_INTERCEPTOR_ORB_INITIALIZER_H

#include "tao/x11/pi/pi.h"

/**
 * @class FOO_IORInterceptor_ORBInitializer
 *
 * @brief Simple concrete ORB initializer.
 *
 * This is a test ORB initializer that registers an IORInterceptor for
 * this test.
 */
class FOO_IORInterceptor_ORBInitializer :
  public virtual IDL::traits<PortableInterceptor::ORBInitializer>::base_type
{
public:

  /**
   * @name Methods Required by the ORBInitializer Interface
   *
   * These are methods that must be implemented since they are pure
   * virtual in the abstract base class.  They are the canonical
   * methods required for all ORB initializers.
   */
  //@{
  /// The pre-initialization hook.
  virtual void pre_init (
      IDL::traits<PortableInterceptor::ORBInitInfo>::ref_type info) override;

  /// The post-initialization hook.
  virtual void post_init (
      IDL::traits<PortableInterceptor::ORBInitInfo>::ref_type info) override;
  //@}

};

#endif  /* FOO_IOR_INTERCEPTOR_ORB_INITIALIZER_H */
