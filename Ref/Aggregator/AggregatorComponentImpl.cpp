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
    uint32_t time = this->RTCRead_out(0);
    this->tlmWrite_AGG_TIME(time);
    this->log_ACTIVITY_HI_RTC_COMMAND_SENT(time, GET_EV);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void AggregatorComponentImpl ::
    SET_RTC_DATA_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        U32 time
    )
  {
    this->RTCWrite_out(0,time);
    this->tlmWrite_AGG_TIME(time);
    this->log_ACTIVITY_HI_RTC_COMMAND_SENT(time, SET_EV);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void AggregatorComponentImpl ::
    AGG_CONFIG_IMU_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        I32 configVal1,
        I32 configVal2
    )
  {
    this->IMUConfig_out(0, configVal1, configVal2);
    this->tlmWrite_AGG_IMU_Config1(configVal1);
    this->tlmWrite_AGG_IMU_Config2(configVal2);
    this->log_ACTIVITY_HI_IMU_COMMAND_SENT(IMU_CONFIG);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void AggregatorComponentImpl ::
    AGG_GET_IMU_DATA_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    F64 *ret = this->IMURead_out(0);
    this->tlmWrite_AGG_GyroX(ret[0]);
    this->tlmWrite_AGG_GyroY(ret[1]);
    this->tlmWrite_AGG_GyroZ(ret[2]);
    this->tlmWrite_AGG_AccX(ret[3]);
    this->tlmWrite_AGG_AccY(ret[4]);
    this->tlmWrite_AGG_AccZ(ret[5]);
    this->log_ACTIVITY_HI_IMU_COMMAND_SENT(IMU_READ);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }




} // end namespace Ref
