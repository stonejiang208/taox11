/**
 * @file    test_dynstruct.h
 * @author  Marijke Henstmengel
 *
 * @brief   header file for test DynStruct
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 * Chamber of commerce Rotterdam nr.276339, The Netherlands
 */
#if !defined (TEST_X11_DYNSTRUCT_H)
#define TEST_X11_DYNSTRUCT_H

#include "tao/x11/orb.h"

class Test_DynStruct
{
public:
  Test_DynStruct (IDL::traits<CORBA::ORB>::ref_type orb);
  ~Test_DynStruct ();

  const std::string test_name () const;

  int run_test ();

private:
  IDL::traits<CORBA::ORB>::ref_type orb_;
  std::string test_name_;
  uint32_t error_count_;

};

#endif /* TEST_X11_DYNUNION_H */
