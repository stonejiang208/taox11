/**
 * @file    logstream_t.h
 * @author  Martin Corino
 *
 * @brief   TAOX11 logger stream buffer
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 * Chamber of commerce Rotterdam nr.276339, The Netherlands
 */

#ifndef TAOX11_LOGGER_LOGSTREAM_T_H
#define TAOX11_LOGGER_LOGSTREAM_T_H

#pragma once

#include /**/ "ace/config-all.h"

#include "tao/x11/logger/log_type.h"
#include "ace/Default_Constants.h"
#include <streambuf>
#include <sstream>
#include <iosfwd>
#include <ios>

#if !defined(X11_NLOGGING)

namespace x11_logger
{
  /**
  * @class log_buffer_t
  *
  * @brief Encapsulates an output-only streambuffer attached
  * to an ACE logging backend without random access support.
  */
  template <typename CH, typename TR = std::char_traits<CH> >
  class log_buffer_t
    : public std::basic_streambuf<CH, TR>
  {
  public:
    typedef std::basic_streambuf<CH, TR> base_type;
    typedef std::basic_ios<CH, TR> ios_type;
    typedef CH char_type;
    typedef TR char_traits;
    typedef typename base_type::int_type int_type;
    typedef typename base_type::pos_type pos_type;
    typedef typename base_type::off_type off_type;
    typedef typename ios_type::seekdir seekdir;
    typedef typename ios_type::openmode openmode;
    typedef ACE_Log_Priority logprio_type;

    log_buffer_t (typename log_buffer_t<CH, TR>::logprio_type,
                  typename std::basic_ios<CH, TR>::openmode mode);

    virtual ~log_buffer_t () = default;

    void log_module (const Log_Type& lm)
    { this->lm_typeref_ = lm.get_reference (); }

  protected:
    void set_mode (typename std::basic_ios<CH, TR>::openmode mode);

    typename std::basic_ios<CH, TR>::openmode get_mode () const;

    virtual int_type overflow (int_type c);
    virtual int sync ();

    void reset_buffers ();

  private:
    int flush_buffer ();

    void log_record ();

    char_type* _buffer () { return &this->buffer_[0]; }

    static constexpr uint32_t BUFFER_SIZE { 128 };
    static constexpr uint32_t MAXLOGMSG { ACE_MAXLOGMSGLEN / sizeof(char_type) };

    logprio_type priority_;
    char_type buffer_[BUFFER_SIZE];
    typename std::basic_ios<CH, TR>::openmode mode_;
    std::basic_stringstream<CH, TR> logmsg_;
    Log_Type const * const * lm_typeref_ {};

    log_buffer_t(const log_buffer_t&) = delete;
    log_buffer_t(log_buffer_t&&) = delete;
    log_buffer_t& operator = (const log_buffer_t&) = delete;
    log_buffer_t& operator = (log_buffer_t&&) = delete;
  };

  /**
  * @class log_ios_t
  *
  * @brief TAOX11 specialization of basic_ios
  */
  template <typename CH, typename TR = std::char_traits<CH> >
  class log_ios_t
    : public virtual std::basic_ios<CH, TR>
  {
  public:
    typedef std::basic_ios<CH, TR> ios_base;
    typedef log_buffer_t<CH, TR> buffer_type;
    typedef typename buffer_type::openmode openmode;
    typedef typename buffer_type::logprio_type logprio_type;

    log_ios_t (logprio_type prio,
               openmode mode);
    ~log_ios_t ();

    buffer_type* rdbuf ();

    const buffer_type& stream () const;

  protected:
    buffer_type streambuf_;
  };

  /**
  * @class log_ostream_t
  *
  * @brief TAOX11 basic_ostream specializaton
  */
  template <typename CH, typename TR = std::char_traits<CH> >
  class log_ostream_t
    : public log_ios_t<CH, TR>,
      public std::basic_ostream<CH, TR>
  {
  public:
    typedef log_ios_t<CH, TR> ios_base;
    typedef typename ios_base::logprio_type logprio_type;

    explicit log_ostream_t(logprio_type prio);
    ~log_ostream_t();
  };

} /* x11_logger */


#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "tao/x11/logger/logstream_t.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("logstream_t.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* !X11_NLOGGING */

#endif /* TAOX11_LOGGER_LOGSTREAM_T_H */
