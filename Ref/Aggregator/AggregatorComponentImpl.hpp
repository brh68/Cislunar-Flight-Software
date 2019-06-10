// ======================================================================
// \title  AggregatorComponentImpl.hpp
// \author benjamin
// \brief  hpp file for Aggregator component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef Aggregator_HPP
#define Aggregator_HPP

#include "Ref/Aggregator/AggregatorComponentAc.hpp"

namespace Ref {

  class AggregatorComponentImpl :
    public AggregatorComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object Aggregator
      //!
      AggregatorComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object Aggregator
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object Aggregator
      //!
      ~AggregatorComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for GET_RTC_DATA command handler
      //! get time
      void GET_RTC_DATA_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );

      //! Implementation for SET_RTC_DATA command handler
      //! set time
      void SET_RTC_DATA_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          U32 time 
      );


    };

} // end namespace Ref

#endif
