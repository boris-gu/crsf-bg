#pragma once

#include "crsf_frametype_default.h"

typedef struct {
  uint8_t sync;

  uint8_t ext_dest; // 0xEE CRSF_ADDRESS_CRSF_TRANSMITTER
  uint8_t ext_src;  // 0xEF CRSF_ADDRESS_ELRS_LUA

  /**
   * The first field index is 01
   * However there is also a field index 00 which is a folder-type parameter which lists the top level configuration items
   */
  uint8_t field_index;
  /**
   * The first chunk index is 00
   * Splitting the configuration item across multiple packets requires it be split into chunks
   */
  uint8_t chunk_index;

} crsf_parameter_read;

uint8_t crsf_default2parameter_read(crsf_default* in_pkt, crsf_parameter_read* out_pkt);

uint8_t crsf_parameter_read2array(crsf_parameter_read* in_pkt, uint8_t* out_pkt);
