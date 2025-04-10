#pragma once

#include <stdint.h>
#include "crsf_enum.h"

/**
 * @brief Enum used to track reading of packets
 * 
 * When creating a status variable, equate it with READ_SYNC,
 * because the values [0, CRSF_LEN_PAYLOAD_MAX-1] are used to track payload reading
 */
typedef enum {
  CRSF_READ_SYNC = CRSF_LEN_PAYLOAD_MAX,
  CRSF_READ_LEN,
  CRSF_READ_TYPE,
  CRSF_READ_CRC8
} crsf_read_status;

/**
 * @brief Packet with raw payload
 */
typedef struct {
  uint8_t sync; // CRSF_ADDRESS
  uint8_t len;  // len <= CRSF_LEN_SECOND_BYTE_MAX

  uint8_t type;                          // CRSF_FRAMETYPE
  uint8_t payload[CRSF_LEN_PAYLOAD_MAX]; // Raw payload
  uint8_t crc8;                          // checksum CRC8 using poly 0xD5
} crsf_default;

/**
 * @brief Parsing received bytes and assembling crsf_default
 * @param rx_byte   New received byte
 * @param rx_pkt    Assembled packet
 * @param rx_status Packet assembly control
 * @return 
 */
uint8_t crsf_parse_char(uint8_t rx_byte, crsf_default* rx_pkt, uint8_t* rx_status);

/**
 * @brief Calculating the checksum CRC8, poly 0xD5
 * @param array Data array
 * @param len   Length of the data array
 * @return 
 */
uint8_t crc8_d5_calc(uint8_t* array, uint8_t len);

/**
 * @brief Calculating the checksum CRC8, poly 0xBA, for extended packet
 * @param array Data array
 * @param len   Length of the data array
 * @return 
 */
uint8_t crc8_ba_calc(uint8_t* array, uint8_t len);
