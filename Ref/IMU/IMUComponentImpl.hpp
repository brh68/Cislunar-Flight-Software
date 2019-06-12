// ======================================================================
// \title  IMUComponentImpl.hpp
// \author benjamin
// \brief  hpp file for IMU component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef IMU_HPP
#define IMU_HPP

#include "Ref/IMU/IMUComponentAc.hpp"

namespace Ref {

  class IMUComponentImpl :
    public IMUComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object IMU
      //!
      IMUComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object IMU
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object IMU
      //!
      ~IMUComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for ConfigPort
      //!
      void ConfigPort_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          I32 configVal1, 
          I32 configVal2 
      );

      //! Handler implementation for ReadPort
      //!
      F64 *ReadPort_handler(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for IMU_CONFIGURE command handler
      //! set time
      void IMU_CONFIGURE_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          I32 configVal1, 
          I32 configVal2 
      );


    };

} // end namespace Ref

#endif
