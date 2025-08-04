/**
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_COMMAND
 */
#pragma once

#include "crsf_frametype_default.h"

//  CRSF_COMMAND_SUBCMD_RX - CRSF_COMMAND_SUBCMD_RX_BIND
uint8_t crsf_cmd_rx_bind_array(uint8_t sync,
                               uint8_t ext_dest,
                               uint8_t ext_src,
                               uint8_t* out_pkt);

//  CRSF_COMMAND_SUBCMD_RX -> COMMAND_MODEL_SELECT_ID
uint8_t crsf_cmd_model_select_id_array(uint8_t sync,
                                 uint8_t ext_dest,
                                 uint8_t ext_src,
                                 uint8_t model_id,
                                 uint8_t* out_pkt);

// TODO: CRSF_COMMAND_SUBCMD_GENERAL - CRSF_COMMAND_SUBCMD_GENERAL_CRSF_SPEED_PROPOSAL

// TODO: CRSF_COMMAND_SUBCMD_GENERAL - CRSF_COMMAND_SUBCMD_GENERAL_CRSF_SPEED_RESPONSE
