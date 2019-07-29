// ======================================================================
// \title  PWRComponentImpl.cpp
// \author benjamin
// \brief  cpp file for PWR component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <RPI/PWR/PWRComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Rpi {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  PWRComponentImpl ::
#if FW_OBJECT_NAMES == 1
    PWRComponentImpl(
        const char *const compName
    ) :
      PWRComponentBase(compName)
#else
    PWRComponentImpl(void)
#endif
  {

  }

  void PWRComponentImpl ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    PWRComponentBase::init(instance);
  }

  PWRComponentImpl ::
    ~PWRComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void PWRComponentImpl ::
    OutputTogglePort_handler(
        const NATIVE_INT_TYPE portNum,
        devices toggleTarget,
        bool action
    )
  {
    devicesEV op;
    switch(toggleTarget){
      case PWR_OUT1:
        //actual driver code here
        this->tlmWrite_OUTPUT1(action);
        op = OUT1_EV;
        break;
      case PWR_OUT2:
        //actual driver code here
        this->tlmWrite_OUTPUT2(action);
        op = OUT2_EV;
        break;
      case PWR_OUT3:
        //actual driver code here
        this->tlmWrite_OUTPUT3(action);
        op = OUT3_EV;
        break;
      case PWR_OUT4:
        //actual driver code here
        this->tlmWrite_OUTPUT4(action);
        op = OUT4_EV;
        break;
      case PWR_OUT5:
        //actual driver code here
        this->tlmWrite_OUTPUT5(action);
        op = OUT5_EV;
        break;
      case PWR_OUT6:
        //actual driver code here
        this->tlmWrite_OUTPUT6(action);
        op = OUT6_EV;
        break;
      case PWR_PV4:
        //actual driver code here
        this->tlmWrite_PV4_TLM(action);
        op = PV4_EV;
        break;
      case PWR_HEAT1:
        //actual driver code here
        this->tlmWrite_HEATER1(action);
        op = HEAT1_EV;
        break;
      case PWR_HEAT2:
        //actual driver code here
        this->tlmWrite_HEATER2(action);
        op = HEAT2_EV;
        break;
      default:
        FW_ASSERT(toggleTarget, 0);
        break;
    }
    this->log_ACTIVITY_HI_PWR_OUTPUT_SET(op, action);
  }

  void PWRComponentImpl ::
    WatchdogPort_handler(
        const NATIVE_INT_TYPE portNum,
        U32 timerNum
    )
  {
    //insert driver code here
    this->log_ACTIVITY_LO_PWR_WATCHDOG_PING(timerNum);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void PWRComponentImpl ::
    PWR_SET_OUTPUT_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        targets target,
        bool enabled
    )
  {
    devicesEV op;
    switch(target){
      case out1:
        //actual driver code here
        this->tlmWrite_OUTPUT1(enabled);
        op = OUT1_EV;
        break;
      case out2:
        //actual driver code here
        this->tlmWrite_OUTPUT2(enabled);
        op = OUT2_EV;
        break;
      case out3:
        //actual driver code here
        this->tlmWrite_OUTPUT3(enabled);
        op = OUT3_EV;
        break;
      case out4:
        //actual driver code here
        this->tlmWrite_OUTPUT4(enabled);
        op = OUT4_EV;
        break;
      case out5:
        //actual driver code here
        this->tlmWrite_OUTPUT5(enabled);
        op = OUT5_EV;
        break;
      case out6:
        //actual driver code here
        this->tlmWrite_OUTPUT6(enabled);
        op = OUT6_EV;
        break;
      case PV4:
        //actual driver code here
        this->tlmWrite_PV4_TLM(enabled);
        op = PV4_EV;
        break;
      case heat1:
        //actual driver code here
        this->tlmWrite_HEATER1(enabled);
        op = HEAT1_EV;
        break;
      case heat2:
        //actual driver code here
        this->tlmWrite_HEATER2(enabled);
        op = HEAT2_EV;
        break;
      default:
        FW_ASSERT(target, 0);
        break;
    }
    this->log_ACTIVITY_HI_PWR_OUTPUT_SET(op, enabled);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Rpi
