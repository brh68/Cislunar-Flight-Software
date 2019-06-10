// ======================================================================
// \title  AggregatorComponentImpl.cpp
// \author benjamin
// \brief  cpp file for Aggregator component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/Aggregator/AggregatorComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  AggregatorComponentImpl ::
#if FW_OBJECT_NAMES == 1
    AggregatorComponentImpl(
        const char *const compName
    ) :
      AggregatorComponentBase(compName)
#else
    AggregatorComponentImpl(void)
#endif
  {

  }

  void AggregatorComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    AggregatorComponentBase::init(queueDepth, instance);
  }

  AggregatorComponentImpl ::
    ~AggregatorComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void AggregatorComponentImpl ::
    GET_RTC_DATA_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    // TODO
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void AggregatorComponentImpl ::
    SET_RTC_DATA_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        U32 time
    )
  {
    // TODO
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref
