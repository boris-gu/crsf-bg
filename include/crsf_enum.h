/**
 * https://github.com/ExpressLRS/ExpressLRS/wiki/CRSF-Protocol/aab6bdf4b6828cbb2512755b82f23d1d9e55b854
 */
#pragma once

/**
 * @brief CRSF_ADDRESS, first byte in packet
 */
typedef enum {
  CRSF_ADDRESS_FLIGHT_CONTROLLER = 0xC8,
  CRSF_ADDRESS_RADIO_TRANSMITTER = 0xEA,
  CRSF_ADDRESS_CRSF_RECEIVER = 0xEC,
  CRSF_ADDRESS_CRSF_TRANSMITTER = 0xEE,
  CRSF_ADDRESS_ELRS_LUA = 0xEF
} crsf_address;

/**
 * @brief CRSF_LEN
 */
typedef enum {
  CRSF_LEN_PAYLOAD_MAX = 60, ///< Maximum payload size
  CRSF_LEN_SECOND_BYTE_MAX = (CRSF_LEN_PAYLOAD_MAX + 2), ///< Maximum size recorded in the second byte of packet
  CRSF_LEN_PKT_MAX = (CRSF_LEN_PAYLOAD_MAX + 4) ///< Maximum packet size
} crsf_payload;

/**
 * @brief CRSF_FRAMETYPE, third byte in packet
 */
typedef enum {
  CRSF_FRAMETYPE_RC_CHANNELS_PACKED = 0x16,
  CRSF_FRAMETYPE_COMMAND = 0x32,
  CRSF_FRAMETYPE_RADIO_ID = 0x3A
} crsf_frametype; 
