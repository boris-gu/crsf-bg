/** 
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_PARAMETER_READ
 */
#pragma once

#include "crsf_frametype_default.h"

typedef struct {
  uint8_t sync;
  uint8_t ext_dest;
  uint8_t ext_src;

  uint8_t field_index;
  uint8_t chunk_index;
} crsf_parameter_read;

uint8_t crsf_parameter_read_array(uint8_t field_index, uint8_t chunk_index, uint8_t* out_pkt);
