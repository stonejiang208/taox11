/**
 * @file    object.h
 * @author  Martin Corino
 *
 * @brief   CORBA C++11 core Object classes
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 */

#ifndef TAOX11_OBJECT_H_INCLUDED
#define TAOX11_OBJECT_H_INCLUDED

#pragma once

#include /**/ "ace/config-all.h"

#include "tao/x11/system_exception.h"
#include "tao/x11/object_fwd.h"
#include "tao/x11/Policy_ForwardC.h"

namespace TAOX11_NAMESPACE
{
  namespace CORBA
  {
    // forward
    class DomainManager;
    typedef std::vector<object_reference<DomainManager>> DomainManagerList;

    // forwards
    class ORB;

#if ! defined (CORBA_E_COMPACT) && ! defined (CORBA_E_MICRO)
    // forwards
    class InterfaceDef;
    class NVList;
    class NamedValue;
    typedef std::vector<TypeCode> ExceptionList;
    class Request;
    class Context;
    typedef std::vector<object_reference<Context>> ContextList;
#endif

    class TAOX11_Export Object
    {
    public:
      typedef IDL::traits <Object>      _traits_type;
      typedef _traits_type::ref_type    _ref_type;

      virtual bool _is_a (const std::string& local_type_id);

      /**
        * Try to determine if this object is the same as @a other_obj.  This
        * method relies on the representation of the object reference's
        * private state.  Since that changes easily (when different ORB
        * protocols are in use) there is no default implementation.
        */
      virtual bool _is_equivalent (
          object_traits<Object>::ref_type other_obj);

      virtual uint32_t _hash (uint32_t maximum);
      virtual bool _is_local();

#if (TAO_HAS_MINIMUM_CORBA == 0)
      virtual bool _non_existent ();

#if ! defined (CORBA_E_COMPACT) && ! defined (CORBA_E_MICRO)
      /// Get info about the object from the Interface Repository.
      virtual object_traits<InterfaceDef>::ref_type _get_interface ();

      /// Get info about the object from the Interface Repository.
      virtual object_traits<Object>::ref_type _get_component ();
#endif

      /// Get the repository id.
      virtual std::string _repository_id ();
#endif

      /// Get the (local) repository id.
      virtual std::string _interface_repository_id ();

#if ! defined (CORBA_E_COMPACT) && ! defined (CORBA_E_MICRO)
      // DII operations to create a request.
      //
      // The mapping for create_request is split into two forms,
      // corresponding to the two usage styles described in CORBA
      // section 6.2.1.

      virtual void _create_request (
          object_reference<Context> ctx,
          const std::string& operation,
          object_reference<NVList> arg_list,
          object_reference<NamedValue> result,
          object_reference<Request>& request,
          Flags req_flags);

      virtual void _create_request (
          object_reference<Context> ctx,
          const std::string& operation,
          object_reference<NVList> arg_list,
          object_reference<NamedValue> result,
          const ExceptionList& exclist,
          const ContextList& ctxtlist,
          object_reference<Request>& request,
          Flags req_flags);

      // The default implementation of this method uses the same simple,
      // multi-protocol remote invocation interface as is assumed by the
      // calls above ... that's how it can have a default
      // implementation.

      /// DII operation to create a request.
      virtual object_reference<Request> _request (
          const std::string& operation);
#endif

#if (TAO_HAS_CORBA_MESSAGING == 1)

      //not in TAO
      virtual object_traits<Policy>::ref_type _get_client_policy (
                                    const PolicyType& policy_type);

      virtual object_traits<Policy>::ref_type _get_policy (
                                    const PolicyType& policy_type);

      virtual object_traits<Object>::ref_type _set_policy_overrides (
        const TAOX11_CORBA::PolicyList& policies,
        const TAOX11_CORBA::SetOverrideType& set_add);

      virtual TAOX11_CORBA::PolicyList _get_policy_overrides (
        const TAOX11_CORBA::PolicyTypeSeq & types);

      virtual bool _validate_connection (
          TAOX11_CORBA::PolicyList& inconsistent_policies);

#endif

      virtual object_traits<CORBA::ORB>::ref_type _get_orb ();

      // Not in TAO
      virtual CORBA::DomainManagerList _get_domain_managers();

      Object_proxy_ptr get_proxy () const;

      static object_traits<Object>::ref_type _narrow (Object_proxy&& op);
    protected:
      typedef std::shared_ptr<Object>   _shared_ptr_type;

      template <typename T> friend struct object_traits;
      template <typename _Tp1, typename, typename ...Args>
      friend object_reference<_Tp1> make_reference(Args&& ...args);

      explicit Object (Object_proxy_ptr op = nullptr);
      Object(const Object&) = delete;
      Object(Object&&) = delete;
      Object& operator=(const Object&) = delete;
      Object& operator=(Object&&) = delete;

      virtual ~Object ();

      _ref_type _lock ()
      { return _ref_type (this); }

      _shared_ptr_type _lock_shared ();

      void set_proxy (Object_proxy_ptr op);

      std::string repo_id_;

    private:
      class dtor
      {
      public:
        void operator ()(Object* p)
        { delete p; }
      };
      friend class dtor;

      Object_proxy_ref proxy_;
      typedef std::weak_ptr<Object> _weak_reference_type;
      _weak_reference_type self_ref_;
    };

    class TAOX11_Export LocalObject
      : public virtual CORBA::Object
    {
    public:
      typedef IDL::traits< LocalObject>     _traits_type;
      typedef _traits_type::ref_type        _ref_type;

      virtual bool _is_a (const std::string& local_type_id) override;
      virtual bool _is_equivalent (
          object_traits<Object>::ref_type other_obj) override;
      virtual uint32_t _hash (uint32_t maximum) override;
      virtual bool _is_local() override;

#if (TAO_HAS_MINIMUM_CORBA == 0)
      virtual bool _non_existent () override;

#if ! defined (CORBA_E_COMPACT) && ! defined (CORBA_E_MICRO)
      /// Get info about the object from the Interface Repository.
      virtual object_traits<InterfaceDef>::ref_type _get_interface () override;

      /// Get info about the object from the Interface Repository.
      virtual object_traits<Object>::ref_type _get_component () override;
#endif

      /// Get the repository id.
      virtual std::string _repository_id () override;
#endif

#if ! defined (CORBA_E_COMPACT) && ! defined (CORBA_E_MICRO)
      // DII operations to create a request.
      //
      // The mapping for create_request is split into two forms,
      // corresponding to the two usage styles described in CORBA
      // section 6.2.1.

      virtual void _create_request (
          object_reference<Context> ctx,
          const std::string& operation,
          object_reference<NVList> arg_list,
          object_reference<NamedValue> result,
          object_reference<Request>& request,
          Flags req_flags) override;

      virtual void _create_request (
          object_reference<Context> ctx,
          const std::string& operation,
          object_reference<NVList> arg_list,
          object_reference<NamedValue> result,
          const ExceptionList& exclist,
          const ContextList& ctxtlist,
          object_reference<Request>& request,
          Flags req_flags) override;

      // The default implementation of this method uses the same simple,
      // multi-protocol remote invocation interface as is assumed by the
      // calls above ... that's how it can have a default
      // implementation.

      /// DII operation to create a request.
      virtual object_reference<Request> _request (
          const std::string& operation) override;
#endif

#if (TAO_HAS_CORBA_MESSAGING == 1)

      //not in TAO
      virtual object_traits<Policy>::ref_type _get_client_policy (
                                    const PolicyType& policy_type) override;

      virtual object_traits<Policy>::ref_type _get_policy (
                                    const PolicyType& policy_type) override;

      virtual object_traits<Object>::ref_type _set_policy_overrides (
                    const TAOX11_CORBA::PolicyList& policies,
                    const TAOX11_CORBA::SetOverrideType& set_add) override;

      virtual TAOX11_NAMESPACE::CORBA::PolicyList _get_policy_overrides (
                      const TAOX11_CORBA::PolicyTypeSeq & types) override;

      virtual bool _validate_connection (
                TAOX11_CORBA::PolicyList& inconsistent_policies) override;

#endif

      virtual object_traits<CORBA::ORB>::ref_type _get_orb () override;

      // Not in TAO
      virtual CORBA::DomainManagerList _get_domain_managers() override;

    protected:
      friend struct object_traits<LocalObject>;

      LocalObject () = default;
      LocalObject(const LocalObject&) = delete;
      LocalObject(LocalObject&&) = delete;
      LocalObject& operator=(const LocalObject&) = delete;
      LocalObject& operator=(LocalObject&&) = delete;

      virtual ~LocalObject ();
    };

  } // namespace CORBA

  namespace IDL
  {
    template <typename OStrm_>
    struct formatter< CORBA::Object, OStrm_>
    {
      inline OStrm_& operator ()(
          OStrm_& os_,
          IDL::traits<CORBA::Object>::in_type o_)
      {
        return os_ << "IDL::traits<CORBA::Object>::ref_type {object:"
#if (TAO_HAS_MINIMUM_CORBA == 0)
            << (o_ ? o_->_repository_id () : std::string("nil"))
#endif
            << "}";
      }
    };

    template <typename OStrm_, typename Fmt>
    inline OStrm_& operator <<(
        OStrm_& os,
        IDL::traits<CORBA::Object>::__Writer<Fmt> w)
    {
      typedef IDL::traits<CORBA::Object>::__Writer<Fmt> writer_t;
      typedef typename std::conditional<
                          std::is_same<
                            typename writer_t::formatter_t,
                            std::false_type>::value,
                          formatter<CORBA::Object, OStrm_>,
                          typename writer_t::formatter_t>::type formatter_t;
      return IDL::traits<CORBA::Object>::write_on (
          os, w.val_,
          formatter_t ());
    }

    template <typename OStrm_>
    struct formatter< CORBA::LocalObject, OStrm_>
    {
      inline OStrm_& operator ()(
          OStrm_& os_,
          IDL::traits<CORBA::LocalObject>::in_type o_)
      {
        return os_ << "IDL::traits<CORBA::LocalObject>::ref_type {local object:"
            << o_.operator -> ()<< "}";
      }
    };

    template <typename OStrm_, typename Fmt>
    inline OStrm_& operator <<(
        OStrm_& os,
        IDL::traits<CORBA::LocalObject>::__Writer<Fmt> w)
    {
      typedef IDL::traits<CORBA::LocalObject>::__Writer<Fmt> writer_t;
      typedef typename std::conditional<
                          std::is_same<
                            typename writer_t::formatter_t,
                            std::false_type>::value,
                          formatter<CORBA::LocalObject, OStrm_>,
                          typename writer_t::formatter_t>::type formatter_t;
      return IDL::traits<CORBA::LocalObject>::write_on (
          os, w.val_,
          formatter_t ());
    }
  } // namespace IDL
} // namespace TAOX11_NAMESPACE

#endif // TAOX11_OBJECT_H_INCLUDED
