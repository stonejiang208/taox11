/**
 * @file    PolicyP.h
 * @author  Martin Corino
 *
 * @brief   CORBA C++11 Policy client stub class
 * Handcrafted after initial generation by RIDL.
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 */
/*
 * ****  Code generated by the RIDL Compiler ****
 * RIDL has been developed by:
 *        Remedy IT Expertise BV
 *        The Netherlands
 *        https://www.remedy.nl
 */

#ifndef __RIDL_POLICYP_H_INCLUDED__
#define __RIDL_POLICYP_H_INCLUDED__

#include "tao/x11/basic_argument_t.h"
#include "tao/x11/sequence_cdr_t.h"

// generated from StubProxyWriter#enter_module
namespace TAOX11_NAMESPACE {

  // generated from StubProxyWriter#enter_module
  namespace CORBA {

  } // namespace CORBA

} // namespace TAOX11_NAMESPACE

// generated from StubProxyCDRWriter#pre_visit
TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// generated from c++/cli_prx/except_cdr.erb

// CDR streaming operator specializations
TAOX11_Export TAO_CORBA::Boolean operator<< (TAO_OutputCDR &, const TAOX11_CORBA::PolicyError& );
TAOX11_Export TAO_CORBA::Boolean operator>> (TAO_InputCDR &, TAOX11_CORBA::PolicyError&);

// generated from c++/cli_prx/except_cdr.erb

// CDR streaming operator specializations
TAOX11_Export TAO_CORBA::Boolean operator<< (TAO_OutputCDR &, const TAOX11_CORBA::InvalidPolicies& );
TAOX11_Export TAO_CORBA::Boolean operator>> (TAO_InputCDR &, TAOX11_CORBA::InvalidPolicies&);

#if !defined (_INTF_TAOX11_NAMESPACE_CORBA_POLICY_CDR_OPS_)
#define _INTF_TAOX11_NAMESPACE_CORBA_POLICY_CDR_OPS_
// Stub CDR streaming operator specializations
TAOX11_Export TAO_CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    TAOX11_NAMESPACE::IDL::traits< TAOX11_CORBA::Policy>::ref_type _tao_objref);
TAOX11_Export TAO_CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    TAOX11_NAMESPACE::IDL::traits< TAOX11_CORBA::Policy>::ref_type& _tao_objref);

// CDR streaming helpers for object ref sequence
TAOX11_Export bool
marshal_TAOX11_NAMESPACE_CORBA_Policy_sequence (
    TAO_OutputCDR& _strm,
    const std::vector< TAOX11_CORBA::object_traits< TAOX11_CORBA::Policy>::ref_type>& _seq,
    uint32_t _bound);
TAOX11_Export bool
demarshal_TAOX11_NAMESPACE_CORBA_Policy_sequence (
    TAO_InputCDR& _strm,
    std::vector< TAOX11_CORBA::object_traits< TAOX11_CORBA::Policy>::ref_type>& _seq,
    uint32_t _bound);

template <typename TRAITS>
inline bool
marshal_sequence (
    TAO_OutputCDR& _strm,
    const std::vector< TAOX11_CORBA::object_traits< TAOX11_CORBA::Policy>::ref_type>& _seq,
    uint32_t _bound)
{
  return marshal_TAOX11_NAMESPACE_CORBA_Policy_sequence (
      _strm, _seq, _bound);
}
template <typename TRAITS>
inline bool
demarshal_sequence (
    TAO_InputCDR& _strm,
    std::vector< TAOX11_CORBA::object_traits< TAOX11_CORBA::Policy>::ref_type>& _seq,
    uint32_t _bound)
{
  return demarshal_TAOX11_NAMESPACE_CORBA_Policy_sequence (
      _strm, _seq, _bound);
}
#endif // !_INTF_TAOX11_NAMESPACE_CORBA_POLICY_CDR_OPS_

TAO_END_VERSIONED_NAMESPACE_DECL

#endif // __RIDL_POLICYP_H_INCLUDED__

// -*- END -*-