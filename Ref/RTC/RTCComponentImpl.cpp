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


#include <Ref/RTC/RTCComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

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
    TimePort_handler(
        const NATIVE_INT_TYPE portNum,
        U32 time,
        RTCOp operation
    )
  {
    // TODO
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void RTCComponentImpl ::
    RTC_COMMAND_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        U32 time
    )
  {
    // TODO
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref
