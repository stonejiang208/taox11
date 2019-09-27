/**
 * @file   ami_test_i.h
 * @author Marijke Hengstmengel
 *
 * @brief  CORBA C++11 interface ami test
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 * Chamber of commerce Rotterdam nr.276339, The Netherlands
 */
#ifndef TAO_AMI_TEST_I_H
#define TAO_AMI_TEST_I_H

#include "testlib/taox11_testlog.h"

#include "ami_testS.h"

class AMI_Test_i
: public virtual CORBA::servant_traits< A::AMI_Test>::base_type
{
public:
  /// ctor
  AMI_Test_i (IDL::traits<CORBA::ORB>::ref_type orb);

  // The AMI_Test methods.
  virtual char foo_char (char& out_c,
                 char in_c,
                 char& inout_c) override;

  virtual wchar_t foo_wchar (wchar_t in_wc,
                   wchar_t& out_wc,
                   wchar_t& inout_wc) override;

  virtual uint8_t foo_octet (uint8_t& out_o,
                    uint8_t in_o,
                    uint8_t& inout_o) override;

  virtual bool foo_bool (bool& inout_b,
                 bool& out_b,
                 bool in_b) override;

  virtual A::enumType foo_enum (A::enumType& out_e,
                        A::enumType& inout_e,
                        A::enumType in_e) override;

  virtual A::structType foo_struct (A::structType& out_t,
                            const A::structType& in_t,
                            A::structType& inout_t) override;

  virtual A::longSeq foo_sequence (A::longSeq& out_seq,
                           const A::longSeq& in_seq,
                           A::longSeq& inout_seq) override;

  virtual A::arrayType foo_array (A::arrayType& out_a,
                          const A::arrayType& in_a,
                          A::arrayType& inout_a) override;

  virtual A::unionData foo_union (A::unionData& out_u,
                          const A::unionData& in_u,
                          A::unionData& inout_u) override;

  virtual std::wstring foo_wstring (std::wstring& out_w,
                           const std::wstring& in_w,
                           std::wstring& inout_w) override;

  virtual std::string foo_string (std::string& out_s,
                          const std::string& in_s,
                          std::string& inout_s) override;


  virtual uint64_t foo_u_l_l (uint64_t& out_ull,
                      uint64_t in_ull,
                      uint64_t& inout_ull) override;

  virtual float foo_float (float& out_f,
                   float in_f,
                   float& inout_f) override;

  virtual long double foo_long_double (long double& out_ld,
                               long double in_ld,
                               long double& inout_ld) override;


  virtual void foo_void_in (int32_t in_l) override;
  virtual void foo_void_out (int32_t& out_l) override;
  virtual void foo_void_inout (int32_t& inout_l) override;
  virtual int32_t foo_no_arg () override;
  virtual void foo_void_no_arg () override;

  virtual void shutdown () override;

private:
  IDL::traits<CORBA::ORB>::ref_type  orb_;

};

#endif /* TAO_AMI_TEST_I_H */
