/**
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_PARAMETER_SETTINGS_ENTRY
 */
#pragma once

#include "crsf_frametype_default.h"

#define CRSF_LEN_PARAMETER_SETTINGS_ENTRY_LABEL_MAX (CRSF_LEN_PAYLOAD_MAX - 10)

// Low 7 bits & high bit(hidden)
typedef enum {
  CRSF_PARAM_TYPE_UINT8 = 0x00,
  CRSF_PARAM_TYPE_INT8 = 0x01,
  CRSF_PARAM_TYPE_UINT16 = 0x02,
  CRSF_PARAM_TYPE_INT16 = 0x03,
  // 0x04 - 0x07 = larger ints??
  CRSF_PARAM_TYPE_FLOAT = 0x08,  // 4 byte
  CRSF_PARAM_TYPE_SELECT = 0x09,
  CRSF_PARAM_TYPE_STRING = 0x0A,
  CRSF_PARAM_TYPE_FOLDER = 0x0B,
  CRSF_PARAM_TYPE_INFO = 0x0C,
  CRSF_PARAM_TYPE_COMMAND = 0x0D,
  CRSF_PARAM_TYPE_VTX = 0x0F,  // ???
  CRSF_PARAM_TYPE_HIDDEN = 128  // 0b10000000 - if set, parameter is not to be displayed by the destination
} crsf_parameter_settings_entry_type;

typedef struct {
  uint8_t sync;
  uint8_t ext_dest;
  uint8_t ext_src;

  uint8_t field_index;
  uint8_t remaining_chunks;
  uint8_t parent;
  uint8_t type;
  char label[CRSF_LEN_PARAMETER_SETTINGS_ENTRY_LABEL_MAX];
} crsf_parameter_settings_entry;

uint8_t crsf_default2parameter_settings_entry(crsf_default* in_pkt, crsf_parameter_settings_entry* out_pkt);

uint8_t crsf_parameter_settings_entry2array(crsf_parameter_settings_entry* in_pkt, uint8_t* out_pkt);
