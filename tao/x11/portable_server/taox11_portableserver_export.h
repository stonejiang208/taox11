/**
 * @file    taox11_portableserver_export.h
 * @author  Unknown
 *
 * @brief   Export file for the TAOX11 PortableServer library
 *
 * This file is generated automatically by generate_export_file.pl TAOX11_PortableServer
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 * Chamber of commerce Rotterdam nr.276339, The Netherlands
 */
#ifndef TAOX11_PORTABLESERVER_EXPORT_H
#define TAOX11_PORTABLESERVER_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (TAOX11_PORTABLESERVER_HAS_DLL)
#  define TAOX11_PORTABLESERVER_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && TAOX11_PORTABLESERVER_HAS_DLL */

#if !defined (TAOX11_PORTABLESERVER_HAS_DLL)
#  define TAOX11_PORTABLESERVER_HAS_DLL 1
#endif /* ! TAOX11_PORTABLESERVER_HAS_DLL */

#if defined (TAOX11_PORTABLESERVER_HAS_DLL) && (TAOX11_PORTABLESERVER_HAS_DLL == 1)
#  if defined (TAOX11_PORTABLESERVER_BUILD_DLL)
#    define TAOX11_PortableServer_Export ACE_Proper_Export_Flag
#    define TAOX11_PORTABLESERVER_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define TAOX11_PORTABLESERVER_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* TAOX11_PORTABLESERVER_BUILD_DLL */
#    define TAOX11_PortableServer_Export ACE_Proper_Import_Flag
#    define TAOX11_PORTABLESERVER_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define TAOX11_PORTABLESERVER_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* TAOX11_PORTABLESERVER_BUILD_DLL */
#else /* TAOX11_PORTABLESERVER_HAS_DLL == 1 */
#  define TAOX11_PortableServer_Export
#  define TAOX11_PORTABLESERVER_SINGLETON_DECLARATION(T)
#  define TAOX11_PORTABLESERVER_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* TAOX11_PORTABLESERVER_HAS_DLL == 1 */

// Set TAOX11_PORTABLESERVER_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (TAOX11_PORTABLESERVER_NTRACE)
#  if (ACE_NTRACE == 1)
#    define TAOX11_PORTABLESERVER_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define TAOX11_PORTABLESERVER_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !TAOX11_PORTABLESERVER_NTRACE */

#if (TAOX11_PORTABLESERVER_NTRACE == 1)
#  define TAOX11_PORTABLESERVER_TRACE(X)
#else /* (TAOX11_PORTABLESERVER_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define TAOX11_PORTABLESERVER_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (TAOX11_PORTABLESERVER_NTRACE == 1) */

#endif /* TAOX11_PORTABLESERVER_EXPORT_H */

// End of auto generated file.
