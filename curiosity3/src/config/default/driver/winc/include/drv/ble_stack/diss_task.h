// DOM-IGNORE-BEGIN
/*
Copyright (c) RivieraWaves 2009-2014
Copyright (C) 2017, Microchip Technology Inc., and its subsidiaries. All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

The software and documentation is provided by microchip and its contributors
"as is" and any express, implied or statutory warranties, including, but not
limited to, the implied warranties of merchantability, fitness for a particular
purpose and non-infringement of third party intellectual property rights are
disclaimed to the fullest extent permitted by law. In no event shall microchip
or its contributors be liable for any direct, indirect, incidental, special,
exemplary, or consequential damages (including, but not limited to, procurement
of substitute goods or services; loss of use, data, or profits; or business
interruption) however caused and on any theory of liability, whether in contract,
strict liability, or tort (including negligence or otherwise) arising in any way
out of the use of the software and documentation, even if advised of the
possibility of such damage.

Except as expressly permitted hereunder and subject to the applicable license terms
for any third-party software incorporated in the software and any applicable open
source software license terms, no license or other rights, whether express or
implied, are granted under any patent or other intellectual property rights of
Microchip or any third party.
*/
// DOM-IGNORE-END
/*
 * diss_task.h
 *
 *  Created on: Sep 16, 2013
 *      Author: delsissy
 */
#ifndef DISS_TASK_H_
#define DISS_TASK_H_

#include "nmi_types.h"
#include "cmn_defs.h"
#include "msg_if.h"

/*SRC: TASK_APP DEST:TASK_DISS*/
uint8_t diss_create_db_req_handler (uint16_t features);
uint8_t diss_set_char_val_req_handler (uint8_t char_code, uint8_t val_len, uint8_t *val);
void diss_enable_req_hanlder(uint16_t conhdl, uint8_t sec_lvl, uint8_t con_type);
/*SRC: TASK_DISS DEST:TASK_APP*/
//DISS_DISABLE_IND
//DISS_ERROR_IND


/*Messages for Device Information Service Server */
enum
{
    ///Add a DIS instance into the database
    DISS_CREATE_DB_REQ = 0x7000,
    ///Inform APP of database creation status
    DISS_CREATE_DB_CFM,
    ///Set the value of an attribute
    DISS_SET_CHAR_VAL_REQ,

    ///Start the Device Information Service Task - at connection
    DISS_ENABLE_REQ,

    /// Inform the application that the profile service role task has been disabled after a disconnection
    DISS_DISABLE_IND,

    ///Error indication to Host
    DISS_ERROR_IND
};

/*
 * API MESSAGES STRUCTURES
 ****************************************************************************************
 */

/// Maximal length for Characteristic values - 25
#define DIS_VAL_MAX_LEN                         (0x19)

///System ID string length
#define DIS_SYS_ID_LEN                          (0x08)
///IEEE Certif length (min 6 bytes)
#define DIS_IEEE_CERTIF_MIN_LEN                 (0x06)
///PnP ID length
#define DIS_PNP_ID_LEN                          (0x07)

/*
 * ENUMERATIONS
 ****************************************************************************************
 */

///Attributes State Machine
enum
{
    DIS_IDX_SVC,

    DIS_IDX_MANUFACTURER_NAME_CHAR,
    DIS_IDX_MANUFACTURER_NAME_VAL,

    DIS_IDX_MODEL_NB_STR_CHAR,
    DIS_IDX_MODEL_NB_STR_VAL,

    DIS_IDX_SERIAL_NB_STR_CHAR,
    DIS_IDX_SERIAL_NB_STR_VAL,

    DIS_IDX_HARD_REV_STR_CHAR,
    DIS_IDX_HARD_REV_STR_VAL,

    DIS_IDX_FIRM_REV_STR_CHAR,
    DIS_IDX_FIRM_REV_STR_VAL,

    DIS_IDX_SW_REV_STR_CHAR,
    DIS_IDX_SW_REV_STR_VAL,

    DIS_IDX_SYSTEM_ID_CHAR,
    DIS_IDX_SYSTEM_ID_VAL,

    DIS_IDX_IEEE_CHAR,
    DIS_IDX_IEEE_VAL,

    DIS_IDX_PNP_ID_CHAR,
    DIS_IDX_PNP_ID_VAL,

    DIS_IDX_NB
};

///Attribute Table Indexes
enum
{
    DIS_MANUFACTURER_NAME_CHAR,
    DIS_MODEL_NB_STR_CHAR,
    DIS_SERIAL_NB_STR_CHAR,
    DIS_HARD_REV_STR_CHAR,
    DIS_FIRM_REV_STR_CHAR,
    DIS_SW_REV_STR_CHAR,
    DIS_SYSTEM_ID_CHAR,
    DIS_IEEE_CHAR,
    DIS_PNP_ID_CHAR,

    DIS_CHAR_MAX
};

///Database Configuration Flags
enum
{
    ///Indicate if Manufacturer Name String Char. is supported
    DIS_MANUFACTURER_NAME_CHAR_SUP       = 0x0001,
    ///Indicate if Model Number String Char. is supported
    DIS_MODEL_NB_STR_CHAR_SUP            = 0x0002,
    ///Indicate if Serial Number String Char. is supported
    DIS_SERIAL_NB_STR_CHAR_SUP           = 0x0004,
    ///Indicate if Hardware Revision String Char. supports indications
    DIS_HARD_REV_STR_CHAR_SUP            = 0x0008,
    ///Indicate if Firmware Revision String Char. is writable
    DIS_FIRM_REV_STR_CHAR_SUP            = 0x0010,
    ///Indicate if Software Revision String Char. is writable
    DIS_SW_REV_STR_CHAR_SUP              = 0x0020,
    ///Indicate if System ID Char. is writable
    DIS_SYSTEM_ID_CHAR_SUP               = 0x0040,
    ///Indicate if IEEE Char. is writable
    DIS_IEEE_CHAR_SUP                    = 0x0080,
    ///Indicate if PnP ID Char. is writable
    DIS_PNP_ID_CHAR_SUP                  = 0x0100,

    ///All features are supported
    DIS_ALL_FEAT_SUP                     = 0x01FF
};

#endif // DISS_TASK_H_
