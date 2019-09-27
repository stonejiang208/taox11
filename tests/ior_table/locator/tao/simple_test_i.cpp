// FUZZ: disable check_for_ace_log_categories

#include "simple_test_i.h"

Simple_Test_i::Simple_Test_i (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}

void
Simple_Test_i::shutdown (void)
{
  this->orb_->shutdown (false);
}
