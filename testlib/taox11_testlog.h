/**
 * @file    taox11_testlog.h
 * @author  Martin Corino
 *
 * @brief   CORBA C++11 Test Logging module
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 * Chamber of commerce Rotterdam nr.276339, The Netherlands
 */
#ifndef TAOX11_TESTLOG_H
#define TAOX11_TESTLOG_H

#include "tao/x11/log.h"

#define X11_LOG_THREAD_INFO "(" \
          << x11_logger::processid << "|" \
          << x11_logger::threadid << ") - "

#if defined(X11_NLOGGING)

#define TAOX11_TEST_LOGGER   x11_logger::NULL_LogType

#else

#define TAOX11_TEST_LOGGER \
  x11_logger::TAOX11_Test_Log_Module::log_type

#endif /* !X11_NLOGGING */

#define TAOX11_TEST_TRACE      X11_TRACE_LOG(TAOX11_TEST_LOGGER)
#define TAOX11_TEST_DEBUG      X11_DEBUG_LOG(TAOX11_TEST_LOGGER)
#define TAOX11_TEST_INFO       X11_INFO_LOG(TAOX11_TEST_LOGGER)
#define TAOX11_TEST_WARNING    X11_WARNING_LOG(TAOX11_TEST_LOGGER)
#define TAOX11_TEST_ERROR      X11_ERROR_LOG(TAOX11_TEST_LOGGER)
#define TAOX11_TEST_CRITICAL   X11_CRITICAL_LOG(TAOX11_TEST_LOGGER)
#define TAOX11_TEST_PANIC      X11_PANIC_LOG(TAOX11_TEST_LOGGER)


#define TAOX11_TEST_TRACE_W    X11_TRACE_W_LOG(TAOX11_TEST_LOGGER)
#define TAOX11_TEST_DEBUG_W    X11_DEBUG_W_LOG(TAOX11_TEST_LOGGER)
#define TAOX11_TEST_INFO_W     X11_INFO_W_LOG(TAOX11_TEST_LOGGER)
#define TAOX11_TEST_WARNING_W  X11_WARNING_W_LOG(TAOX11_TEST_LOGGER)
#define TAOX11_TEST_ERROR_W    X11_ERROR_W_LOG(TAOX11_TEST_LOGGER)
#define TAOX11_TEST_CRITICAL_W X11_CRITICAL_W_LOG(TAOX11_TEST_LOGGER)
#define TAOX11_TEST_PANIC_W    X11_PANIC_W_LOG(TAOX11_TEST_LOGGER)

#endif /* TAOX11_TESTLOG_H */
