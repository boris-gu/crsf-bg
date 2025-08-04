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

uint8_t crsf_parameter_write_UINT8_array(uint8_t field_index, uint8_t value, uint8_t* out_pkt);

uint8_t crsf_parameter_write_INT8_array(uint8_t field_index, int8_t value, uint8_t* out_pkt);

uint8_t crsf_parameter_write_UINT16_array(uint8_t field_index, uint16_t value, uint8_t* out_pkt);

uint8_t crsf_parameter_write_INT16_array(uint8_t field_index, int16_t value, uint8_t* out_pkt);

uint8_t crsf_parameter_write_FLOAT_array(uint8_t field_index, int32_t value, uint8_t* out_pkt);

uint8_t crsf_parameter_write_SELECT_array(uint8_t field_index, char * value, uint8_t len, uint8_t* out_pkt);

uint8_t crsf_parameter_write_STRING_array(uint8_t field_index, char * value, uint8_t len, uint8_t* out_pkt);

// XXX: Нужны ли остальные settings_entry_type?
