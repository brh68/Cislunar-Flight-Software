// ======================================================================
// \title  RTCComponentImpl.cpp
// \author benjamin
// \brief  cpp file for RTC component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <RPI/RTC/RTCComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Rpi {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  RTCComponentImpl ::
#if FW_OBJECT_NAMES == 1
    RTCComponentImpl(
        const char *const compName
    ) :
      RTCComponentBase(compName)
#else
    RTCComponentImpl(void)
#endif
  {

  }

  void RTCComponentImpl ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    RTCComponentBase::init(instance);
  }

  RTCComponentImpl ::
    ~RTCComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void RTCComponentImpl ::
    WritePort_handler(
        const NATIVE_INT_TYPE portNum,
        U32 time
    )
  {
    //driver code to actually change RTC time
    this->tlmWrite_RTC_TIME(time);
    this->log_ACTIVITY_HI_RTC_PORT_CALL(time, SET_EV);
  }

  U32 RTCComponentImpl ::
    ReadPort_handler(
        const NATIVE_INT_TYPE portNum
    )
  {
    //driver code to retrieve time value
    uint32_t time = 1192948012; //should be actual value, currently random
    this->tlmWrite_RTC_TIME(time);
    this->log_ACTIVITY_HI_RTC_PORT_CALL(time, GET_EV);
    return time;
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void RTCComponentImpl ::
    RTC_CMD_TIME_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        U32 time
    )
  {
    //driver code ot change RTC value
    this->tlmWrite_RTC_TIME(time);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Rpi
