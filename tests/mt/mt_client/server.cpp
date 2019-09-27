/**
 * @file    server.cpp
 * @author  Marcel Smit
 *
 * @brief   CORBA C++11 Multi Threaded test application
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 * Chamber of commerce Rotterdam nr.276339, The Netherlands
 */

#include "ace/Get_Opt.h"
#include "test_i.h"

#include "testlib/taox11_testlog.h"
#include <fstream>

std::string ior_output_file ("");

bool
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, ACE_TEXT("o:"));
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'o':
        ior_output_file = get_opts.opt_arg ();
        break;
      case '?':
      default:
        TAOX11_TEST_ERROR << "usage:\n"
              << "-o <iorfile>\n"
              << std::endl;
        return false;
      }
  // Indicates successful parsing of the command line
  return true;
}

int
main (int argc, char *argv[])
{
  try
    {
      IDL::traits<CORBA::ORB>::ref_type orb =
        CORBA::ORB_init (argc, argv);

      IDL::traits<CORBA::Object>::ref_type poa_object =
        orb->resolve_initial_references("RootPOA");

      if (!poa_object)
      {
        TAOX11_TEST_ERROR << X11_LOG_THREAD_INFO
              << "Unable to initialize the POA."
              << std::endl;
        return 1;
      }

      IDL::traits<PortableServer::POA>::ref_type root_poa =
        IDL::traits<PortableServer::POA>::narrow (poa_object);

      IDL::traits<PortableServer::POAManager>::ref_type poa_manager =
        root_poa->the_POAManager ();

      if (!parse_args (argc, argv))
        return 1;

      CORBA::servant_traits<Simple_Server>::ref_type server_impl =
        CORBA::make_reference<Simple_Server_i> (orb);

      PortableServer::ObjectId id =
        root_poa->activate_object (server_impl);

      IDL::traits<CORBA::Object>::ref_type object =
        root_poa->id_to_reference (id);

      IDL::traits<Simple_Server>::ref_type server =
        IDL::traits<Simple_Server>::narrow (object);

      std::string ior =
        orb->object_to_string (server);

      TAOX11_TEST_DEBUG << "Activated as <" << ior
            << ">" << std::endl;

      // If the ior_output_file exists, output the ior to it
      if (!ior_output_file.empty())
      {
        std::ofstream fos (ior_output_file);
        if (!fos)
        {
          TAOX11_TEST_ERROR << "ERROR: failed to open file "
                << ior_output_file << std::endl;
          return 1;
        }
        fos << ior;
        fos.close ();
      }

      poa_manager->activate ();

      orb->run ();

      TAOX11_TEST_DEBUG << "server event loop finished" << std::endl;

      root_poa->destroy (true, true);

      orb->destroy ();
    }
  catch (const CORBA::Exception& ex)
    {
      TAOX11_TEST_ERROR << "Caught exception <server::main> :"
            << ex << std::endl;
      return 1;
    }

  return 0;
}
