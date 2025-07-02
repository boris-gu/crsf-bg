/**
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_PARAMETER_WRITE
 */
#pragma once

#include "crsf_frametype_default.h"

#define CRSF_LEN_PARAMETER_WRITE_VALUE_MAX (CRSF_LEN_PAYLOAD_MAX - 10)

typedef struct {
  uint8_t sync;
  uint8_t ext_dest;
  uint8_t ext_src;

  uint8_t field_index;
  uint8_t value[CRSF_LEN_PARAMETER_WRITE_VALUE_MAX];
} crsf_parameter_write;

uint8_t crsf_default2parameter_write(crsf_default* in_pkt, crsf_parameter_write* out_pkt);

uint8_t crsf_parameter_write2array(crsf_parameter_write* in_pkt, uint8_t* out_pkt);
