/**
 * CRSF command execute
 */
#pragma once

#include "crsf_frametype_default.h"

typedef enum {
  CRSF_COMMAND_SUBCMD_RX = 0x10,     ///< Receiver
  CRSF_COMMAND_SUBCMD_GENERAL = 0x0A ///< General
} crsf_command_realm ;

typedef enum {
  CRSF_COMMAND_SUBCMD_RX_BIND = 0x01, ///< Enter binding mode
  COMMAND_MODEL_SELECT_ID = 0x05      ///< Set Receiver / Model ID
} crsf_command_subcmd_rx_cmd ;

typedef enum {
  CRSF_COMMAND_SUBCMD_GENERAL_CRSF_SPEED_PROPOSAL = 0x70, ///< (CRSFv3) Proposed new CRSF port speed
  CRSF_COMMAND_SUBCMD_GENERAL_CRSF_SPEED_RESPONSE = 0x71  ///< (CRSFv3) response to the proposed CRSF port speed
} crsf_command_subcmd_general_cmd ;


// XXX: ТОЛЬКО MODEL ID
typedef struct {
  uint8_t sync; // 0xEE CRSF_ADDRESS_CRSF_TRANSMITTER

  uint8_t ext_dest;     // 0xEE CRSF_ADDRESS_CRSF_TRANSMITTER
  uint8_t ext_src;      // 0xEA CRSF_ADDRESS_RADIO_TRANSMITTER
  uint8_t command_type; // 0x10 CRSF_COMMAND_SUBCMD_RX
  uint8_t command_id; // 0x05 COMMAND_MODEL_SELECT_ID
  uint8_t command_data_size;
  uint8_t command_data[10];

  // uint8_t crc8;
} crsf_command;


uint8_t crsf_default2command(crsf_default* in_pkt, crsf_command* out_pkt);

uint8_t crsf_command2array(crsf_command* in_pkt, uint8_t* out_pkt);

