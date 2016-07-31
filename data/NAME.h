
/****************************************************************************************************//**
 * @file     NAME.h
 *
 * @brief    CMSIS Cortex-M3 Peripheral Access Layer Header File for
 *           NAME from XXX.
 *
 * @version  V1.2
 * @date     31. July 2016
 *
 * @note     Generated with SVDConv V2.87l 
 *           from CMSIS SVD File 'NAME.svd' Version 1.2,
 *******************************************************************************************************/



/** @addtogroup XXX
  * @{
  */

/** @addtogroup NAME
  * @{
  */

#ifndef NAME_H
#define NAME_H

#ifdef __cplusplus
extern "C" {
#endif


/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum {
/* -------------------  Cortex-M3 Processor Exceptions Numbers  ------------------- */
  Reset_IRQn                    = -15,              /*!<   1  Reset Vector, invoked on Power up and warm reset                 */
  NonMaskableInt_IRQn           = -14,              /*!<   2  Non maskable Interrupt, cannot be stopped or preempted           */
  HardFault_IRQn                = -13,              /*!<   3  Hard Fault, all classes of Fault                                 */
  MemoryManagement_IRQn         = -12,              /*!<   4  Memory Management, MPU mismatch, including Access Violation
                                                         and No Match                                                          */
  BusFault_IRQn                 = -11,              /*!<   5  Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory
                                                         related Fault                                                         */
  UsageFault_IRQn               = -10,              /*!<   6  Usage Fault, i.e. Undef Instruction, Illegal State Transition    */
  SVCall_IRQn                   =  -5,              /*!<  11  System Service Call via SVC instruction                          */
  DebugMonitor_IRQn             =  -4,              /*!<  12  Debug Monitor                                                    */
  PendSV_IRQn                   =  -2,              /*!<  14  Pendable request for system service                              */
  SysTick_IRQn                  =  -1,              /*!<  15  System Tick Timer                                                */
/* -----------------------  NAME Specific Interrupt Numbers  ---------------------- */
  TIMER0_IRQn                   =   0               /*!<   0  TIMER0                                                           */
} IRQn_Type;


/** @addtogroup Configuration_of_CMSIS
  * @{
  */


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* ----------------Configuration of the Cortex-M3 Processor and Core Peripherals---------------- */
#define __CM3_REV                 0x0100            /*!< Cortex-M3 Core Revision                                               */
#define __MPU_PRESENT                  1            /*!< MPU present or not                                                    */
#define __NVIC_PRIO_BITS               3            /*!< Number of Bits used for Priority Levels                               */
#define __Vendor_SysTickConfig         0            /*!< Set to 1 if different SysTick Config is used                          */
/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_cm3.h"                               /*!< Cortex-M3 processor and core peripherals                              */
#include "system_SP.h"                              /*!< NAME System                                                           */


/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */


/** @addtogroup Device_Peripheral_Registers
  * @{
  */


/* -------------------  Start of section using anonymous unions  ------------------ */
#if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif



/* ================================================================================ */
/* ================                     TIMER0                     ================ */
/* ================================================================================ */


/**
  * @brief 32 Timer / Counter, counting up or down from different sources (TIMER0)
  */

typedef struct {                                    /*!< TIMER0 Structure                                                      */
  
  union {
    __IO uint32_t  MY_CR;                           /*!< Test 1                                                                */
    
    struct {
      __IO uint32_t  EN         :  1;               /*!< Enable                                                                */
           uint32_t             : 15;
      __IO uint32_t  CAPEDGE    :  2;               /*!< Capture Edge, select which Edge should result in a counter increment
                                                         or decrement                                                          */
           uint32_t             :  2;
      __IO uint32_t  TRGEXT     :  2;               /*!< Triggers an other Peripheral                                          */
           uint32_t             :  2;
      __I  uint32_t  RELOAD     :  2;               /*!< Select RELOAD Register n to reload Timer on condition                 */
      __I  uint32_t  IDR        :  2;               /*!< Selects, if Reload Register number is incremented, decremented
                                                         or not modified                                                       */
           uint32_t             :  3;
      __I  uint32_t  S          :  1;               /*!< Starts and Stops the Timer / Counter                                  */
    } MY_CR_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MY_SR;                           /*!< Test 2                                                                */
    
    struct {
      __I  uint32_t  A2         : 10;               /*!< test a2                                                               */
      __IO uint32_t  A3         :  6;               /*!< test a3                                                               */
      __I  uint32_t  A4         : 16;               /*!< test a4                                                               */
    } MY_SR_b;                                      /*!< BitSize                                                               */
  };
  __IO uint32_t  reload;                            /*!< Test 3 - to reload                                                    */
} TIMER0_Type;


/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif



/* ================================================================================ */
/* ================         struct 'TIMER0' Position & Mask        ================ */
/* ================================================================================ */


/* --------------------------------  TIMER0_MY_CR  -------------------------------- */
#define TIMER0_MY_CR_EN_Pos                   (0UL)                     /*!< TIMER0 MY_CR: EN (Bit 0)                                    */
#define TIMER0_MY_CR_EN_Msk                   (0x1UL)                   /*!< TIMER0 MY_CR: EN (Bitfield-Mask: 0x01)                      */
#define TIMER0_MY_CR_CAPEDGE_Pos              (16UL)                    /*!< TIMER0 MY_CR: CAPEDGE (Bit 16)                              */
#define TIMER0_MY_CR_CAPEDGE_Msk              (0x30000UL)               /*!< TIMER0 MY_CR: CAPEDGE (Bitfield-Mask: 0x03)                 */
#define TIMER0_MY_CR_TRGEXT_Pos               (20UL)                    /*!< TIMER0 MY_CR: TRGEXT (Bit 20)                               */
#define TIMER0_MY_CR_TRGEXT_Msk               (0x300000UL)              /*!< TIMER0 MY_CR: TRGEXT (Bitfield-Mask: 0x03)                  */
#define TIMER0_MY_CR_RELOAD_Pos               (24UL)                    /*!< TIMER0 MY_CR: RELOAD (Bit 24)                               */
#define TIMER0_MY_CR_RELOAD_Msk               (0x3000000UL)             /*!< TIMER0 MY_CR: RELOAD (Bitfield-Mask: 0x03)                  */
#define TIMER0_MY_CR_IDR_Pos                  (26UL)                    /*!< TIMER0 MY_CR: IDR (Bit 26)                                  */
#define TIMER0_MY_CR_IDR_Msk                  (0xc000000UL)             /*!< TIMER0 MY_CR: IDR (Bitfield-Mask: 0x03)                     */
#define TIMER0_MY_CR_S_Pos                    (31UL)                    /*!< TIMER0 MY_CR: S (Bit 31)                                    */
#define TIMER0_MY_CR_S_Msk                    (0x80000000UL)            /*!< TIMER0 MY_CR: S (Bitfield-Mask: 0x01)                       */

/* --------------------------------  TIMER0_MY_SR  -------------------------------- */
#define TIMER0_MY_SR_A2_Pos                   (0UL)                     /*!< TIMER0 MY_SR: A2 (Bit 0)                                    */
#define TIMER0_MY_SR_A2_Msk                   (0x3ffUL)                 /*!< TIMER0 MY_SR: A2 (Bitfield-Mask: 0x3ff)                     */
#define TIMER0_MY_SR_A3_Pos                   (10UL)                    /*!< TIMER0 MY_SR: A3 (Bit 10)                                   */
#define TIMER0_MY_SR_A3_Msk                   (0xfc00UL)                /*!< TIMER0 MY_SR: A3 (Bitfield-Mask: 0x3f)                      */
#define TIMER0_MY_SR_A4_Pos                   (16UL)                    /*!< TIMER0 MY_SR: A4 (Bit 16)                                   */
#define TIMER0_MY_SR_A4_Msk                   (0xffff0000UL)            /*!< TIMER0 MY_SR: A4 (Bitfield-Mask: 0xffff)                    */



/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

#define TIMER0_BASE                     0x40010000UL


/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

#define TIMER0                          ((TIMER0_Type             *) TIMER0_BASE)


/** @} */ /* End of group Device_Peripheral_Registers */
/** @} */ /* End of group NAME */
/** @} */ /* End of group XXX */

#ifdef __cplusplus
}
#endif


#endif  /* NAME_H */

