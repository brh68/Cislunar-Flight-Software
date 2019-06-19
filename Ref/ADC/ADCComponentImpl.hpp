// ======================================================================
// \title  ADCComponentImpl.hpp
// \author benjamin
// \brief  hpp file for ADC component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef ADC_HPP
#define ADC_HPP

#include "Ref/ADC/ADCComponentAc.hpp"

namespace Ref {

  class ADCComponentImpl :
    public ADCComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object ADC
      //!
      ADCComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object ADC
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object ADC
      //!
      ~ADCComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for ConfigPort
      //!
      void ConfigPort_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F64 VoltageGain, 
          I32 SampleRate 
      );

      //! Handler implementation for TemperaturePort
      //!
      F64 TemperaturePort_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F64 AmbientTemp 
      );

      //! Handler implementation for PressurePort
      //!
      F64 PressurePort_handler(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for ADC_CONFIGURE command handler
      //! 
      void ADC_CONFIGURE_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F64 VoltageGain, 
          I32 SampleRate 
      );


    };

} // end namespace Ref

#endif
