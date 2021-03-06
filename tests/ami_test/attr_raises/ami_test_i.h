/**
 * @file    ami_test_i.h
 * @author  Marijke Hengstmengel
 *
 * @brief   CORBA C++11 interface ami test
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 */
#ifndef TAOX11__AMI_TEST_I_H
#define TAOX11__AMI_TEST_I_H

#include "testlib/taox11_testlog.h"

#include "ami_testS.h"

class AMI_Test_i final
: public virtual CORBA::servant_traits< A::AMI_Test>::base_type
{
public:
  /// ctor
  AMI_Test_i (IDL::traits<CORBA::ORB>::ref_type orb);

  // The AMI_Test methods.
  virtual int32_t foo (int32_t& inout_l,
               int32_t in_l,
               int32_t& out_l) override;

  virtual void shutdown () override;

  virtual int32_t yadda_get_r () override;
  virtual void yadda_get_r (int32_t yadda) override;

  virtual int32_t yadda_set_r () override;
  virtual void yadda_set_r (int32_t yadda) override;

  virtual int32_t yadda_get_set_r () override;
  virtual void yadda_get_set_r (int32_t yadda) override;

  virtual int32_t yadda_no_r () override;
  virtual void yadda_no_r (int32_t yadda) override;

  virtual int32_t  yadda_readonly_r() override;
  virtual int32_t  yadda_readonly_no_r() override;

  virtual int32_t foo_no_arg () override;

private:
  IDL::traits<CORBA::ORB>::ref_type  orb_;

  int32_t yadda_ {0};

  int32_t in_l_ {931247};

  int32_t inout_l_ {300};

  int32_t in_l_last_ {931235};
};

#endif /* TAOX11__AMI_TEST_I_H */
