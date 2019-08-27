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
#include <gyro_valueswipi.h>
#include <gyro_valueswipi.cpp>

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
	GyrScale = GyroConfig;
	AccScale = AccConfig;
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
    static float * vals;
	double ret[3];
    imuTypeEV op;
	calculate();//update constants in case they have changed
    switch(dataType){
	case IMU_GYRO:
		vals = gyr_data();//get gyro data from driver
	    this->tlmWrite_IMU_GYROX(vals[0]);
	    this->tlmWrite_IMU_GYROY(vals[1]);
	    this->tlmWrite_IMU_GYROZ(vals[2]);
	    op = GYRO_EV;
	    break;
	case IMU_ACC:
		vals = acc_data();//get accelerometer data from driver
	    this->tlmWrite_IMU_ACCX(vals[0]);
	    this->tlmWrite_IMU_ACCY(vals[1]);
	    this->tlmWrite_IMU_ACCZ(vals[2]);
	    op = ACC_EV;
	    break;
	case IMU_MAG:
		vals = mag_data();//get magenometer data from driver
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
    ret[0] = (double) vals[0];
    ret[1] = (double) vals[1];
    ret[2] = (double) vals[2];
    return ret;
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
