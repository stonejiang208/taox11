#ifndef TAO_AMI_TEST_I_H
#define TAO_AMI_TEST_I_H

#include "ami_testS.h"

/**
 * @class AMI_Test_i
 *
 * @brief AMI Test implementation
 *
 * Implements the AMI_Test interface in test.idl
 */
class AMI_Test_i
  : public POA_A::AMI_Test
{
public:
  /// ctor
  AMI_Test_i (CORBA::ORB_ptr orb,
              CORBA::Long in_l = 0,
              const char * in_str = 0,
              bool check_params = false);

  // The AMI_Test methods.
  virtual CORBA::Long foo (CORBA::Long_out out_l,
    CORBA::Long in_l,
    const char* in_str);

  virtual void bar (A::enumType &out_e);

  virtual void shutdown ();

  virtual CORBA::Long yadda ();

  virtual void yadda (CORBA::Long yadda);

  virtual CORBA::Boolean bool_attr();

  virtual void bool_attr(CORBA::Boolean);

  virtual char * foo_struct (::A::structType_out out_t);

private:
  CORBA::ORB_var orb_;

  CORBA::Long number_;

  CORBA::Long yadda_;

  CORBA::Long in_l_;

  CORBA::String_var in_str_;

  bool check_params_;

  bool attr_bool_;
};

#endif /* TAO_AMI_TEST_I_H */
