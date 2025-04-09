#pragma once

#include "crsf_frametype_default.h"

#define CRSF_LEN_DEVICE_INFO_NAME_MAX (CRSF_LEN_PAYLOAD_MAX - 16)

typedef struct {
  uint8_t sync;

  uint8_t ext_dest; // 0xEA CRSF_ADDRESS_RADIO_TRANSMITTER
  uint8_t ext_src;  // 0xEE CRSF_ADDRESS_CRSF_TRANSMITTER

  /**
   * display name, null terminated string
   * ExpressLRS / EdgeTX limited to 15 characters
   */
  char name[CRSF_LEN_DEVICE_INFO_NAME_MAX];
  uint32_t serial_num; // Always "ELRS"(45 4C 52 53) for ExpressLRS
  uint32_t hard_ver;
  /**
   * All 00 for ELRSv2, 00 MAJ MIN REV for ELRSv3
   * ExpressLRS may send 00 or FF for MIN and REV fields if the device is not running a tagged release version
   */
  uint32_t soft_ver;
  uint8_t config_count;
  uint8_t protocol_ver; // 0 for ELRS
} crsf_device_info;

uint8_t crsf_default2device_info(crsf_default* in_pkt, crsf_device_info* out_pkt);

uint8_t crsf_device_info2array(crsf_device_info* in_pkt, uint8_t* out_pkt);
