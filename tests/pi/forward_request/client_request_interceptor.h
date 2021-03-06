/**
 * @file    client_request_interceptor.h
 * @author  Martin Corino
 *
 * @brief   Implementation for the client request interceptor for the
 *          PortableInterceptor::ForwardRequest test.
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 */
#ifndef CLIENT_REQUEST_INTERCEPTOR_H
#define CLIENT_REQUEST_INTERCEPTOR_H

#include "tao/x11/pi/pi.h"
#include "tao/x11/orb.h"

/**
 * @class Client_Request_Interceptor
 *
 * @brief Client request interceptor that exercises
 * PortableInterceptor::ForwardRequest support.
 *
 * This client request interceptor forwards a request to a secondary
 * object by throwing the PortableInterceptor::ForwardRequest
 * exception from within the send_request() interception point.  It
 * only forwards the initial request.  See the README file for
 * details.
 */
class Client_Request_Interceptor final
  : public IDL::traits<PortableInterceptor::ClientRequestInterceptor>::base_type
{
public:

  /// Constructor.
  Client_Request_Interceptor (const std::string& orb_id,
                              const std::string& forward_str);

  /**
   * @name Methods Required by the Client Request Interceptor
   * Interface
   *
   * These are methods that must be implemented since they are pure
   * virtual in the abstract base class.  They are the canonical
   * methods required for all client request interceptors.
   */
  //@{
  /// Return the name of this ClientRequestinterceptor.
  virtual std::string name () override;

  virtual void destroy () override;

  virtual void send_request (
      IDL::traits<PortableInterceptor::ClientRequestInfo>::ref_type ri) override;

  virtual void send_poll (
      IDL::traits<PortableInterceptor::ClientRequestInfo>::ref_type ri) override;

  virtual void receive_reply (
      IDL::traits<PortableInterceptor::ClientRequestInfo>::ref_type ri) override;

  virtual void receive_exception (
      IDL::traits<PortableInterceptor::ClientRequestInfo>::ref_type ri) override;

  virtual void receive_other (
      IDL::traits<PortableInterceptor::ClientRequestInfo>::ref_type ri) override;
  //@}

private:
  /// The ID of the ORB this interceptor is registered with.
  std::string orb_id_;

  /// Pseudo-reference to the ORB this interceptor is registered
  /// with.
  IDL::traits<CORBA::ORB>::ref_type orb_;

  /// The number of requests intercepted by this interceptor.
  uint32_t request_count_ {};

  /// Stringified reference to the object the initial request will be
  /// forwarded to by this interceptor.
  std::string forward_str_;

};

#endif  /* CLIENT_REQUEST_INTERCEPTOR_H */
