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
/*
 * htpt_task.c
 *
 *  Created on: Feb 22, 2015
 *      Author: aabdelfattah
 */
#include "at_ble_api.h"
#include "platform.h"
#include "interface.h"

#include "htpt_task.h"
#include "profiles.h"

/*
 * msgs from APP to HTPT
 *
 *
 */
at_ble_status_t htpt_create_db_req_handler(uint8_t  temp_type,
                                            uint16_t valid_range_min,
                                            uint16_t valid_range_max,
                                            uint8_t features)
{
    //TODO: check on platform error
    at_ble_status_t status = AT_BLE_SUCCESS;
    INTERFACE_MSG_INIT(HTPT_CREATE_DB_REQ, TASK_HTPT);
    INTERFACE_PACK_ARG_UINT16(valid_range_min);
    INTERFACE_PACK_ARG_UINT16(valid_range_max);
    INTERFACE_PACK_ARG_UINT8(features);
    INTERFACE_SEND_NO_WAIT();
    INTERFACE_MSG_DONE();
    return status;

}

at_ble_status_t htpt_enable_req_handler(  at_ble_handle_t conn_handle,
                                        uint8_t sec_lvl,
                                        uint8_t con_type,
                                        uint16_t temp_meas_ind_en,
                                        uint16_t interm_temp_ntf_en,
                                        uint16_t meas_intv_ind_en,
                                        uint16_t meas_intv)
{
    //TODO: check on platform error
    at_ble_status_t status = AT_BLE_SUCCESS;
    INTERFACE_MSG_INIT(HTPT_ENABLE_REQ, TASK_HTPT);
    INTERFACE_PACK_ARG_UINT16(conn_handle);
    INTERFACE_PACK_ARG_UINT8(sec_lvl);
    INTERFACE_PACK_ARG_UINT8(con_type);
    INTERFACE_PACK_ARG_UINT16(temp_meas_ind_en);
    INTERFACE_PACK_ARG_UINT16(interm_temp_ntf_en);
    INTERFACE_PACK_ARG_UINT16(meas_intv_ind_en);
    INTERFACE_PACK_ARG_UINT16(meas_intv);
    INTERFACE_SEND_NO_WAIT();
    INTERFACE_MSG_DONE();
    return status;
}



at_ble_status_t htpt_temp_send_req_handler(     uint32_t temp,
                                                at_ble_prf_date_time_t* time_stamp,
                                                uint8_t  flags,
                                                uint8_t  type,
                                                at_ble_handle_t conn_handle,
                                                uint8_t flag_stable_meas)
{
    //TODO: check on platform error
    at_ble_status_t status = AT_BLE_SUCCESS;

    INTERFACE_MSG_INIT(HTPT_TEMP_SEND_REQ, TASK_HTPT);
    INTERFACE_PACK_ARG_UINT32(temp);
    INTERFACE_PACK_ARG_UINT16(time_stamp->year);
    INTERFACE_PACK_ARG_UINT8(time_stamp->month);
    INTERFACE_PACK_ARG_UINT8(time_stamp->day);
    INTERFACE_PACK_ARG_UINT8(time_stamp->hour);
    INTERFACE_PACK_ARG_UINT8(time_stamp->min);
    INTERFACE_PACK_ARG_UINT8(time_stamp->sec);
    INTERFACE_PACK_ARG_DUMMY(1);
    INTERFACE_PACK_ARG_UINT8(flags);
    INTERFACE_PACK_ARG_UINT8(type);
    INTERFACE_PACK_ARG_DUMMY(2);
    INTERFACE_PACK_ARG_UINT16(conn_handle);
    INTERFACE_PACK_ARG_UINT8(flag_stable_meas);
    INTERFACE_PACK_ARG_DUMMY(1);
    INTERFACE_SEND_NO_WAIT();
    INTERFACE_MSG_DONE();
    return status;
}

at_ble_status_t htpt_meas_intv_upd_req_handler(at_ble_handle_t conn_handle,
                                        uint16_t meas_intv)
{
    //TODO: check on platform error
    at_ble_status_t status = AT_BLE_SUCCESS;
    INTERFACE_MSG_INIT(HTPT_MEAS_INTV_UPD_REQ, TASK_HTPT);
    INTERFACE_PACK_ARG_UINT16(conn_handle);
    INTERFACE_PACK_ARG_UINT16(meas_intv);
    INTERFACE_SEND_NO_WAIT();
    INTERFACE_MSG_DONE();
    return status;
}

at_ble_status_t htpt_temp_type_upd_req_handler( at_ble_handle_t conn_handle,
                                               uint8_t value)
{
    //TODO: check on platform error
    at_ble_status_t status = AT_BLE_SUCCESS;
    INTERFACE_MSG_INIT(HTPT_TEMP_TYPE_UPD_REQ, TASK_HTPT);
    INTERFACE_PACK_ARG_UINT8(value);
    INTERFACE_SEND_NO_WAIT();
    INTERFACE_MSG_DONE();
    return status;
}

/*
 * events from HTPT to APP
 *
 *
 */
void htpt_disable_ind_handler(uint16_t src,uint8_t *data,at_ble_htpt_disable_ind_t *param)
{
    //param->conn_handle = KE_IDX_GET(src);

    INTERFACE_UNPACK_INIT(data);
    INTERFACE_UNPACK_UINT16(&param->conhdl);
    INTERFACE_UNPACK_UINT16(&param->temp_meas_ind_en);
    INTERFACE_UNPACK_UINT16(&param->interm_temp_ntf_en);
    INTERFACE_UNPACK_UINT16(&param->meas_intv_ind_en);
    INTERFACE_UNPACK_UINT16(&param->meas_intv);
    INTERFACE_UNPACK_DONE();
}

void htpt_error_ind_handler(uint16_t src,uint8_t *data,at_ble_prf_server_error_ind_t  *param)
{
    //param->conn_handle = KE_IDX_GET(src);

    INTERFACE_UNPACK_INIT(data);
    INTERFACE_UNPACK_UINT16(&param->conhdl);
    INTERFACE_UNPACK_UINT16(&param->msg_id);
    INTERFACE_UNPACK_UINT8(&param->status);
    INTERFACE_UNPACK_DONE();
}

void htpt_temp_send_cfm_handler(uint16_t src,uint8_t *data, at_ble_htpt_temp_send_cfm_t *param)
{
    //param->conn_handle = KE_IDX_GET(src);

    INTERFACE_UNPACK_INIT(data);
    INTERFACE_UNPACK_UINT16(&param->conhdl);
    INTERFACE_UNPACK_UINT8(&param->status);
    INTERFACE_UNPACK_UINT8(&param->cfm_type);
    INTERFACE_UNPACK_DONE();
}

void htpt_create_db_cfm_handler(uint16_t src,uint8_t *data, at_ble_htpt_create_db_cfm_t *param)
{
    //param->conn_handle = KE_IDX_GET(src);

    INTERFACE_UNPACK_INIT(data);
    INTERFACE_UNPACK_UINT8(&param->status);
    INTERFACE_UNPACK_DONE();
}

void htpt_meas_intv_chg_ind_handler(uint16_t src,uint8_t *data,at_ble_htpt_meas_intv_chg_ind_t *param)
{
    //param->conn_handle = KE_IDX_GET(src);

    INTERFACE_UNPACK_INIT(data);
    INTERFACE_UNPACK_UINT16(&param->intv);
    INTERFACE_UNPACK_DONE();
}

void htpt_cfg_indntf_ind_handler(uint16_t src,uint8_t *data,at_ble_htpt_cfg_indntf_ind_t *param)
{
    //param->conn_handle = KE_IDX_GET(src);

    INTERFACE_UNPACK_INIT(data);
    INTERFACE_UNPACK_UINT16(&param->conhdl);
    INTERFACE_UNPACK_UINT16(&param->cfg_val);
    INTERFACE_UNPACK_UINT8(&param->char_code);
    INTERFACE_UNPACK_DONE();
}
// DOM-IGNORE-END
