// ======================================================================
// \title  RTCComponentImpl.hpp
// \author benjamin
// \brief  hpp file for RTC component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef RTC_HPP
#define RTC_HPP

#include "Ref/RTC/RTCComponentAc.hpp"

namespace Ref {

  class RTCComponentImpl :
    public RTCComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object RTC
      //!
      RTCComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object RTC
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object RTC
      //!
      ~RTCComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for TimePort
      //!
      void TimePort_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 time, 
          RTCOp operation 
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for RTC_COMMAND command handler
      //! set time
      void RTC_COMMAND_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          U32 time /*!< The first value*/
      );


    };

} // end namespace Ref

#endif
