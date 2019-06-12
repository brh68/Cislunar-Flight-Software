// ======================================================================
// \title  IMUComponentImpl.cpp
// \author benjamin
// \brief  cpp file for IMU component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/IMU/IMUComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  IMUComponentImpl ::
#if FW_OBJECT_NAMES == 1
    IMUComponentImpl(
        const char *const compName
    ) :
      IMUComponentBase(compName)
#else
    IMUComponentImpl(void)
#endif
  {

  }

  void IMUComponentImpl ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    IMUComponentBase::init(instance);
  }

  IMUComponentImpl ::
    ~IMUComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void IMUComponentImpl ::
    ConfigPort_handler(
        const NATIVE_INT_TYPE portNum,
        I32 configVal1,
        I32 configVal2
    )
  {
    //do configuration stuffs with actual driver
    this->tlmWrite_IMU_Config1(configVal1);
    this->tlmWrite_IMU_Config2(configVal2);
    this->log_ACTIVITY_HI_IMU_CONFIGURED(configVal1, configVal2);
  }

  F64 *IMUComponentImpl ::
    ReadPort_handler(
        const NATIVE_INT_TYPE portNum
    )
  {
    static F64 vals[6];
    vals[0]=100;// gyrox, replace with actual gyro driver code
    vals[1]=200;//gyroy
    vals[2]=300;//gyroz
    vals[3]=400;//accx, replace with actual acc driver code
    vals[4]=500;//accy
    vals[5]=600;//accz
    this->tlmWrite_IMU_GYROX(vals[0]);
    this->tlmWrite_IMU_GYROY(vals[1]);
    this->tlmWrite_IMU_GYROZ(vals[2]);
    this->tlmWrite_IMU_ACCX(vals[3]);
    this->tlmWrite_IMU_ACCY(vals[4]);
    this->tlmWrite_IMU_ACCZ(vals[5]);
    this->log_ACTIVITY_HI_IMU_READ(vals[0], vals[1], vals[2], vals[3], vals[4], vals[5]);
    
    return vals;
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void IMUComponentImpl ::
    IMU_CONFIGURE_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        I32 configVal1,
        I32 configVal2
    )
  {
    //do configuration stuffs with actual driver
    this->tlmWrite_IMU_Config1(configVal1);
    this->tlmWrite_IMU_Config2(configVal2);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
    this->log_ACTIVITY_HI_IMU_CONFIGURED(configVal1, configVal2);
  }

} // end namespace Ref
