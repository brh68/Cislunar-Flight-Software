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


#include <RPI/Aggregator/AggregatorComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Rpi {

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
        I32 GyroConfig,
        I32 AccConfig
    )
  {
    this->IMUConfig_out(0, GyroConfig, AccConfig);
    this->tlmWrite_AGG_IMU_GyroConfig(GyroConfig);
    this->tlmWrite_AGG_IMU_AccConfig(AccConfig);
    this->log_ACTIVITY_HI_IMU_COMMAND_SENT(IMU_CONFIG);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void AggregatorComponentImpl ::
    AGG_GET_IMU_DATA_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
	SensorType Sensor
    )
  {
    F64 *ret;
    data op;
    IMUEventEnum opEv;
    switch(Sensor){
	case GYRO:
	    op = IMU_GYRO;
	    opEv = IMU_READ_GYRO;
	    ret=this->IMURead_out(0, op);
	    this->tlmWrite_AGG_GyroX(ret[0]);
	    this->tlmWrite_AGG_GyroY(ret[1]);
	    this->tlmWrite_AGG_GyroZ(ret[2]);
	    break;
	case ACC:
	    op= IMU_ACC;
	    opEv=IMU_READ_ACC;
	    ret=this->IMURead_out(0, op);
	    this->tlmWrite_AGG_AccX(ret[0]);
	    this->tlmWrite_AGG_AccY(ret[1]);
	    this->tlmWrite_AGG_AccZ(ret[2]);
	    break;
	case MAG:
	    op = IMU_MAG;
	    opEv=IMU_READ_MAG;
	    ret=this->IMURead_out(0, op);
	    this->tlmWrite_AGG_MagX(ret[0]);
	    this->tlmWrite_AGG_MagY(ret[1]);
	    this->tlmWrite_AGG_MagZ(ret[2]);
	    break;
	default:
	    FW_ASSERT(Sensor, 0);
    }

    this->log_ACTIVITY_HI_IMU_COMMAND_SENT(opEv);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void AggregatorComponentImpl ::
    AGG_CONFIG_ADC_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F64 VoltageGain,
        I32 SampleRate
    )
  {
    this->ADCConfig_out(0, VoltageGain, SampleRate);
    this->tlmWrite_AGG_ADC_VGAIN(VoltageGain);
    this->tlmWrite_AGG_ADC_SAMPLE_RATE(SampleRate);
    this->log_ACTIVITY_HI_ADC_COMMAND_SENT(ADC_CONFIG);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void AggregatorComponentImpl ::
    AGG_GET_ADC_TEMP_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F64 AmbientTemp
    )
  {
    F64 ret = this->ADCTemp_out(0, AmbientTemp);
    this->tlmWrite_AGG_ADC_TEMP(ret);
    this->log_ACTIVITY_HI_ADC_COMMAND_SENT(ADC_READ_TEMP);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void AggregatorComponentImpl ::
    AGG_GET_ADC_PRESSURE_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    F64 ret=this->ADCPressure_out(0);
    this->tlmWrite_AGG_ADC_PRESSURE(ret);
    this->log_ACTIVITY_HI_ADC_COMMAND_SENT(ADC_READ_PRESSURE);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void AggregatorComponentImpl ::
    AGG_SET_PWR_TOGGLE_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        outOptions out,
        bool status
    )
  {
    devices dev;
    PWREventEnum event;
    switch(out){
      case COMMS:
        dev=PWR_OUT1;
        event = PWR_OUTPUT;
        this->tlmWrite_AGG_PWR_COMMS(status);
        break;
      case ANT_BURN:
        dev=PWR_OUT2;
        event = PWR_OUTPUT;
        this->tlmWrite_AGG_PWR_ANTENNA_BURN(status);
        break;
      case GLOWPLUG:
        dev=PWR_OUT3;
        event = PWR_OUTPUT;
        this->tlmWrite_AGG_PWR_GLOWPLUG(status);
        break;
      case SEP_BURN:
        dev=PWR_OUT4;
        event = PWR_OUTPUT;
        this->tlmWrite_AGG_PWR_SEPARATION_BURN(status);
        break;
      case SOLENOID:
        dev=PWR_OUT5;
        event = PWR_OUTPUT;
        this->tlmWrite_AGG_PWR_SOLENOID(status);
        break;
      case ELECTROLYZER:
        dev=PWR_OUT6;
        event = PWR_OUTPUT;
        this->tlmWrite_AGG_PWR_ELECTROLYZER(status);
        break;
      case PV4:
        dev=PWR_PV4;
        event = PWR_PV4SET;
        this->tlmWrite_AGG_PWR_PV4(status);
        break;
      case HEATER1:
        dev=PWR_HEAT1;
        event = PWR_HEATER;
        this->tlmWrite_AGG_PWR_HEAT1(status);
        break;
      case HEATER2:
        dev=PWR_HEAT2;
        event = PWR_HEATER;
        this->tlmWrite_AGG_PWR_HEAT2(status);
        break;
      default:
        FW_ASSERT(out, 0);
        break;
    }
    this->PWRToggle_out(0, dev, status);
    this->log_ACTIVITY_HI_PWR_COMMAND_SENT(event);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void AggregatorComponentImpl ::
    AGG_SEND_PWR_PING_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        U32 timerNum
    )
  {
    this->PWRPing_out(0, timerNum);
    this->log_ACTIVITY_HI_PWR_COMMAND_SENT(PWR_WATCHDOG_CONFIG);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }




} // end namespace Rpi
