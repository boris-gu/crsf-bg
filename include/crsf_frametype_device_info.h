/**
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_DEVICE_INFO
 */
#pragma once

#include "crsf_frametype_default.h"

#define CRSF_LEN_DEVICE_INFO_NAME_MAX (CRSF_LEN_PAYLOAD_MAX - 16)

typedef struct {
  uint8_t sync;
  uint8_t ext_dest;
  uint8_t ext_src;

  char name[CRSF_LEN_DEVICE_INFO_NAME_MAX];
  uint32_t serial_num;
  uint32_t hard_ver;
  uint32_t soft_ver;
  uint8_t config_count;
  uint8_t protocol_ver;
} crsf_device_info;

uint8_t crsf_default2device_info(crsf_default* in_pkt, crsf_device_info* out_pkt);

uint8_t crsf_device_info2array(crsf_device_info* in_pkt, uint8_t* out_pkt);
