// ======================================================================
// \title  ADCComponentImpl.cpp
// \author benjamin
// \brief  cpp file for ADC component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <RPI/ADC/ADCComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Rpi {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ADCComponentImpl ::
#if FW_OBJECT_NAMES == 1
    ADCComponentImpl(
        const char *const compName
    ) :
      ADCComponentBase(compName)
#else
    ADCComponentImpl(void)
#endif
  {

  }

  void ADCComponentImpl ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    ADCComponentBase::init(instance);
  }

  ADCComponentImpl ::
    ~ADCComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ADCComponentImpl ::
    ConfigPort_handler(
        const NATIVE_INT_TYPE portNum,
        F64 VoltageGain,
        I32 SampleRate
    )
  {
	//insert driver code here
    this->tlmWrite_ADC_VoltageGain(VoltageGain);
    this->tlmWrite_ADC_SampleRate(SampleRate);
    this->log_ACTIVITY_HI_ADC_CONFIGURED(VoltageGain, SampleRate);
  }

  F64 ADCComponentImpl ::
    TemperaturePort_handler(
        const NATIVE_INT_TYPE portNum,
        F64 AmbientTemp
    )
  {
    //insert driver code here
    F64 ret = 42.42;
    this->tlmWrite_ADC_Temperature(ret);
    this->log_ACTIVITY_HI_ADC_READ(TEMP_EV, ret);
    return ret;
  }

  F64 ADCComponentImpl ::
    PressurePort_handler(
        const NATIVE_INT_TYPE portNum
    )
  {
    //insert driver code here
    F64 ret = 21.21;
    this->tlmWrite_ADC_Pressure(ret);
    this->log_ACTIVITY_HI_ADC_READ(PRESSURE_EV, ret);
    return ret;
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void ADCComponentImpl ::
    ADC_CONFIGURE_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F64 VoltageGain,
        I32 SampleRate
    )
  {
    // insert driver code here
    this->tlmWrite_ADC_VoltageGain(VoltageGain);
    this->tlmWrite_ADC_SampleRate(SampleRate);
    this->log_ACTIVITY_HI_ADC_CONFIGURED(VoltageGain, SampleRate);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Rpi
