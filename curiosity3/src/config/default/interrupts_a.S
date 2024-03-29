/*******************************************************************************
  System Interrupts File

  Company:
    Microchip Technology Inc.

  File Name:
    interrupt_a.S

  Summary:
    Raw ISR definitions.

  Description:
    This file maps all the interrupt vectors to their corresponding
    implementations. If a particular module interrupt is used, then its ISR
    definition can be found in corresponding PLIB source file. If a module
    interrupt is not used, then its ISR implementation is mapped to dummy
    handler.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <xc.h>
#include "ISR_Support.h"

    .extern  CORE_TIMER_Handler

    .section   .vector_0,code, keep
    .equ     __vector_dispatch_0, IntVectorCORE_TIMER_Handler
    .global  __vector_dispatch_0
    .set     nomicromips
    .set     noreorder
    .set     nomips16
    .set     noat
    .ent  IntVectorCORE_TIMER_Handler

IntVectorCORE_TIMER_Handler:
    portSAVE_CONTEXT
    la    s6,  CORE_TIMER_Handler
    jalr  s6
    nop
    portRESTORE_CONTEXT
    .end   IntVectorCORE_TIMER_Handler
    .extern  TIMER_9_Handler

    .section   .vector_40,code, keep
    .equ     __vector_dispatch_40, IntVectorTIMER_9_Handler
    .global  __vector_dispatch_40
    .set     nomicromips
    .set     noreorder
    .set     nomips16
    .set     noat
    .ent  IntVectorTIMER_9_Handler

IntVectorTIMER_9_Handler:
    portSAVE_CONTEXT
    la    s6,  TIMER_9_Handler
    jalr  s6
    nop
    portRESTORE_CONTEXT
    .end   IntVectorTIMER_9_Handler
    .extern  SPI1_FAULT_Handler

    .section   .vector_109,code, keep
    .equ     __vector_dispatch_109, IntVectorSPI1_FAULT_Handler
    .global  __vector_dispatch_109
    .set     nomicromips
    .set     noreorder
    .set     nomips16
    .set     noat
    .ent  IntVectorSPI1_FAULT_Handler

IntVectorSPI1_FAULT_Handler:
    portSAVE_CONTEXT
    la    s6,  SPI1_FAULT_Handler
    jalr  s6
    nop
    portRESTORE_CONTEXT
    .end   IntVectorSPI1_FAULT_Handler
    .extern  SPI1_RX_Handler

    .section   .vector_110,code, keep
    .equ     __vector_dispatch_110, IntVectorSPI1_RX_Handler
    .global  __vector_dispatch_110
    .set     nomicromips
    .set     noreorder
    .set     nomips16
    .set     noat
    .ent  IntVectorSPI1_RX_Handler

IntVectorSPI1_RX_Handler:
    portSAVE_CONTEXT
    la    s6,  SPI1_RX_Handler
    jalr  s6
    nop
    portRESTORE_CONTEXT
    .end   IntVectorSPI1_RX_Handler
    .extern  SPI1_TX_Handler

    .section   .vector_111,code, keep
    .equ     __vector_dispatch_111, IntVectorSPI1_TX_Handler
    .global  __vector_dispatch_111
    .set     nomicromips
    .set     noreorder
    .set     nomips16
    .set     noat
    .ent  IntVectorSPI1_TX_Handler

IntVectorSPI1_TX_Handler:
    portSAVE_CONTEXT
    la    s6,  SPI1_TX_Handler
    jalr  s6
    nop
    portRESTORE_CONTEXT
    .end   IntVectorSPI1_TX_Handler
    .extern  CHANGE_NOTICE_F_Handler

    .section   .vector_123,code, keep
    .equ     __vector_dispatch_123, IntVectorCHANGE_NOTICE_F_Handler
    .global  __vector_dispatch_123
    .set     nomicromips
    .set     noreorder
    .set     nomips16
    .set     noat
    .ent  IntVectorCHANGE_NOTICE_F_Handler

IntVectorCHANGE_NOTICE_F_Handler:
    portSAVE_CONTEXT
    la    s6,  CHANGE_NOTICE_F_Handler
    jalr  s6
    nop
    portRESTORE_CONTEXT
    .end   IntVectorCHANGE_NOTICE_F_Handler
    .extern  CHANGE_NOTICE_G_Handler

    .section   .vector_124,code, keep
    .equ     __vector_dispatch_124, IntVectorCHANGE_NOTICE_G_Handler
    .global  __vector_dispatch_124
    .set     nomicromips
    .set     noreorder
    .set     nomips16
    .set     noat
    .ent  IntVectorCHANGE_NOTICE_G_Handler

IntVectorCHANGE_NOTICE_G_Handler:
    portSAVE_CONTEXT
    la    s6,  CHANGE_NOTICE_G_Handler
    jalr  s6
    nop
    portRESTORE_CONTEXT
    .end   IntVectorCHANGE_NOTICE_G_Handler
    .extern  UART2_FAULT_Handler

    .section   .vector_145,code, keep
    .equ     __vector_dispatch_145, IntVectorUART2_FAULT_Handler
    .global  __vector_dispatch_145
    .set     nomicromips
    .set     noreorder
    .set     nomips16
    .set     noat
    .ent  IntVectorUART2_FAULT_Handler

IntVectorUART2_FAULT_Handler:
    portSAVE_CONTEXT
    la    s6,  UART2_FAULT_Handler
    jalr  s6
    nop
    portRESTORE_CONTEXT
    .end   IntVectorUART2_FAULT_Handler
    .extern  UART2_RX_Handler

    .section   .vector_146,code, keep
    .equ     __vector_dispatch_146, IntVectorUART2_RX_Handler
    .global  __vector_dispatch_146
    .set     nomicromips
    .set     noreorder
    .set     nomips16
    .set     noat
    .ent  IntVectorUART2_RX_Handler

IntVectorUART2_RX_Handler:
    portSAVE_CONTEXT
    la    s6,  UART2_RX_Handler
    jalr  s6
    nop
    portRESTORE_CONTEXT
    .end   IntVectorUART2_RX_Handler
    .extern  UART2_TX_Handler

    .section   .vector_147,code, keep
    .equ     __vector_dispatch_147, IntVectorUART2_TX_Handler
    .global  __vector_dispatch_147
    .set     nomicromips
    .set     noreorder
    .set     nomips16
    .set     noat
    .ent  IntVectorUART2_TX_Handler

IntVectorUART2_TX_Handler:
    portSAVE_CONTEXT
    la    s6,  UART2_TX_Handler
    jalr  s6
    nop
    portRESTORE_CONTEXT
    .end   IntVectorUART2_TX_Handler

