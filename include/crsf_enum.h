#pragma once

#define CRSF_LEN_PAYLOAD_MAX 60                             // Maximum payload size
#define CRSF_LEN_SECOND_BYTE_MAX (CRSF_LEN_PAYLOAD_MAX + 2) // Maximum size recorded in the second byte of packet
#define CRSF_LEN_PKT_MAX (CRSF_LEN_PAYLOAD_MAX + 4)         // Maximum packet size

// CRSF_ADDRESS, first byte in packet and extended dest/src
typedef enum {
  CRSF_ADDRESS_BROADCAST = 0x00,
  CRSF_ADDRESS_FLIGHT_CONTROLLER = 0xC8, // And default SYNC byte: https://github.com/crsf-wg/crsf/wiki/Message-Format#sync
  CRSF_ADDRESS_RADIO_TRANSMITTER = 0xEA,
  CRSF_ADDRESS_CRSF_RECEIVER = 0xEC,
  CRSF_ADDRESS_CRSF_TRANSMITTER = 0xEE,
  CRSF_ADDRESS_ELRS_LUA = 0xEF
} crsf_address;

// CRSF_FRAMETYPE, third byte in packet
typedef enum {
  CRSF_FRAMETYPE_LINK_STATISTICS = 0x14,
  CRSF_FRAMETYPE_RC_CHANNELS_PACKED = 0x16,
  CRSF_FRAMETYPE_DEVICE_PING = 0x28,
  CRSF_FRAMETYPE_DEVICE_INFO = 0x29,
  CRSF_FRAMETYPE_PARAMETER_SETTINGS_ENTRY = 0x2B,
  CRSF_FRAMETYPE_PARAMETER_READ = 0x2C,
  CRSF_FRAMETYPE_PARAMETER_WRITE = 0x2D,
  CRSF_FRAMETYPE_COMMAND = 0x32,
  CRSF_FRAMETYPE_RADIO_ID = 0x3A
} crsf_frametype; 

typedef enum {
  CRSF_COMMAND_SUBCMD_RX = 0x10,
  CRSF_COMMAND_SUBCMD_GENERAL = 0x0A
} crsf_command_realm ;

typedef enum {
  CRSF_COMMAND_SUBCMD_RX_BIND = 0x01,
  CRSF_COMMAND_MODEL_SELECT_ID = 0x05
} crsf_command_subcmd_rx_cmd ;

typedef enum {
  CRSF_COMMAND_SUBCMD_GENERAL_CRSF_SPEED_PROPOSAL = 0x70,
  CRSF_COMMAND_SUBCMD_GENERAL_CRSF_SPEED_RESPONSE = 0x71
} crsf_command_subcmd_general_cmd ;
