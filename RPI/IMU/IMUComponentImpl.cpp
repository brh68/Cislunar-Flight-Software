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


#include <RPI/IMU/IMUComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Rpi {

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
        I32 GyroConfig,
        I32 AccConfig
    )
  {
	//inser driver code here
    this->tlmWrite_IMU_GyroConfig(GyroConfig);
    this->tlmWrite_IMU_AccConfig(AccConfig);
    this->log_ACTIVITY_HI_IMU_CONFIGURED(GyroConfig, AccConfig);
  }

  F64 *IMUComponentImpl ::
    ReadPort_handler(
        const NATIVE_INT_TYPE portNum,
        data dataType
    )
  {
    static F64 vals[3];
    imuTypeEV op;
    switch(dataType){
	case IMU_GYRO:
	    //put actual driver code for gyro values
	    vals[0] = 100;
	    vals[1] = 200;
    	    vals[2] = 300;
	    this->tlmWrite_IMU_GYROX(vals[0]);
	    this->tlmWrite_IMU_GYROY(vals[1]);
	    this->tlmWrite_IMU_GYROZ(vals[2]);
	    op = GYRO_EV;
	    break;
	case IMU_ACC:
	    vals[0] = 400;
	    vals[1] = 500;
    	    vals[2] = 600;
	    this->tlmWrite_IMU_ACCX(vals[0]);
	    this->tlmWrite_IMU_ACCY(vals[1]);
	    this->tlmWrite_IMU_ACCZ(vals[2]);
	    op = ACC_EV;
	    break;
	case IMU_MAG:
	    vals[0] = 700;
	    vals[1] = 800;
    	    vals[2] = 900;
	    this->tlmWrite_IMU_MAGX(vals[0]);
	    this->tlmWrite_IMU_MAGY(vals[1]);
	    this->tlmWrite_IMU_MAGZ(vals[2]);
	    op = MAG_EV;
	    break;
	default:
	    FW_ASSERT(dataType, 0);
	    break;
    }
    this-> log_ACTIVITY_HI_IMU_READ(op, vals[0], vals[1], vals[2]);
    return vals;
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void IMUComponentImpl ::
    IMU_CONFIGURE_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        I32 gyroConfig,
        I32 accConfig
    )
  {
	//insert driver code here
    this->tlmWrite_IMU_GyroConfig(gyroConfig);
    this->tlmWrite_IMU_AccConfig(accConfig);
    this->log_ACTIVITY_HI_IMU_CONFIGURED(gyroConfig, accConfig);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Rpi
