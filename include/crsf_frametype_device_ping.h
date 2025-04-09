#pragma once

#include "crsf_frametype_default.h"

typedef struct {
  uint8_t sync;

  uint8_t ext_dest; // 0x00 CRSF_ADDRESS_BROADCAST
  uint8_t ext_src;  // 0xEA CRSF_ADDRESS_RADIO_TRANSMITTER
} crsf_device_ping;

uint8_t crsf_default2device_ping(crsf_default* in_pkt, crsf_device_ping* out_pkt);

uint8_t crsf_device_ping2array(crsf_device_ping* in_pkt, uint8_t* out_pkt);