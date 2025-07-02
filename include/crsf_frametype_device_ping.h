/** 
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_DEVICE_PING
 */
#pragma once

#include "crsf_frametype_default.h"

typedef struct {
  uint8_t sync;
  uint8_t ext_dest;
  uint8_t ext_src;
} crsf_device_ping;

uint8_t crsf_default2device_ping(crsf_default* in_pkt, crsf_device_ping* out_pkt);

uint8_t crsf_device_ping2array(crsf_device_ping* in_pkt, uint8_t* out_pkt);
