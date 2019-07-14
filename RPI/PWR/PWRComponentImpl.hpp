// ======================================================================
// \title  PWRComponentImpl.hpp
// \author benjamin
// \brief  hpp file for PWR component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef PWR_HPP
#define PWR_HPP

#include "RPI/PWR/PWRComponentAc.hpp"

namespace Rpi {

  class PWRComponentImpl :
    public PWRComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object PWR
      //!
      PWRComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object PWR
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object PWR
      //!
      ~PWRComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for OutputTogglePort
      //!
      void OutputTogglePort_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          devices toggleTarget, 
          bool action 
      );

      //! Handler implementation for WatchdogPort
      //!
      void WatchdogPort_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 timerNum 
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for PWR_SET_OUTPUT command handler
      //! 
      void PWR_SET_OUTPUT_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          targets target, 
          bool enabled 
      );


    };

} // end namespace Rpi

#endif
