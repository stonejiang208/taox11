/**
 * @file    hello.h
 * @author  Johnny Willemsen
 *
 * @brief   CORBA C++11 client application
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 * Chamber of commerce Rotterdam nr.276339, The Netherlands
 */
#ifndef HELLO_H
#define HELLO_H

#include "testS.h"

/// Implement the Test::Hello interface
class Hello_Factory final
  : public CORBA::servant_traits<Test::Hello_Factory>::base_type
{
public:
  /// Constructor
  Hello_Factory (IDL::traits<CORBA::ORB>::ref_type orb,
                 IDL::traits<PortableServer::POA>::ref_type poa);
  virtual ~Hello_Factory ();

  // = The skeleton methods
  virtual IDL::traits<Test::Hello>::ref_type get_hello () override;

  virtual void get_hello_2 (IDL::traits<Test::Hello>::ref_type& hello_obj) override;

  virtual bool equivalent (IDL::traits<Test::Hello_Factory>::ref_type f) override;

private:
  /// Use an ORB reference to convert strings to objects and shutdown
  /// the application.
  IDL::traits<CORBA::ORB>::ref_type orb_;
  IDL::traits<PortableServer::POA>::ref_type poa_;

  Hello_Factory(const Hello_Factory&) = delete;
  Hello_Factory(Hello_Factory&&) = delete;
  Hello_Factory& operator=(const Hello_Factory&) = delete;
  Hello_Factory& operator=(Hello_Factory&&) = delete;
};

/// Implement the Test::Hello interface
class Hello final
  : public virtual CORBA::servant_traits<Test::Hello>::base_type
{
public:
  /// Constructor
  Hello (IDL::traits<CORBA::ORB>::ref_type orb, IDL::traits<Test::Hello_Factory>::ref_type factory);
  virtual ~Hello ();

  // = The skeleton methods
  virtual std::string get_string () override;
  virtual IDL::traits<Test::Hello_Factory>::ref_type get_factory () override;
  virtual void shutdown () override;

  virtual bool equivalent_factory (IDL::traits<Test::Hello_Factory>::ref_type f) override;

  virtual bool equivalent_hello (IDL::traits<Test::Hello>::ref_type h) override;

private:
  /// Use an ORB reference to convert strings to objects and shutdown
  /// the application.
  IDL::traits<CORBA::ORB>::ref_type orb_;
  IDL::traits<Test::Hello_Factory>::ref_type factory_;

  Hello(const Hello&) = delete;
  Hello(Hello&&) = delete;
  Hello& operator=(const Hello&) = delete;
  Hello& operator=(Hello&&) = delete;
};

#endif /* HELLO_H */
