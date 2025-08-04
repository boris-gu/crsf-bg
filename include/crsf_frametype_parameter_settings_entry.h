/**
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_PARAMETER_SETTINGS_ENTRY
 */
#pragma once

#include "crsf_frametype_default.h"

// XXX: Взято наугад
#define CRSF_LEN_PARAMETER_SETTINGS_ENTRY_SOME_CHAR 15

typedef struct {
  uint8_t val_current;
  uint8_t val_min;
  uint8_t val_max;
  char units[CRSF_LEN_PARAMETER_SETTINGS_ENTRY_SOME_CHAR];
} crsf_settings_entry_value_uint8;

typedef struct {
  int8_t val_current;
  int8_t val_min;
  int8_t val_max;
  char units[CRSF_LEN_PARAMETER_SETTINGS_ENTRY_SOME_CHAR];
} crsf_settings_entry_value_int8;

typedef struct {
  uint16_t val_current;
  uint16_t val_min;
  uint16_t val_max;
  char units[CRSF_LEN_PARAMETER_SETTINGS_ENTRY_SOME_CHAR];
} crsf_settings_entry_value_uint16;

typedef struct {
  int16_t val_current;
  int16_t val_min;
  int16_t val_max;
  char units[CRSF_LEN_PARAMETER_SETTINGS_ENTRY_SOME_CHAR];
} crsf_settings_entry_value_int16;

typedef struct {
  int32_t val_current;
  int32_t val_min;
  int32_t val_max;
  uint8_t precision;
  uint32_t step;
  char units[CRSF_LEN_PARAMETER_SETTINGS_ENTRY_SOME_CHAR];
} crsf_settings_entry_value_float;

typedef struct {
  uint8_t val_current;
  char option[CRSF_LEN_PAYLOAD_MAX]; // XXX: Не факт, что хватит всегда!
  char units[CRSF_LEN_PARAMETER_SETTINGS_ENTRY_SOME_CHAR];
} crsf_settings_entry_value_select;

typedef struct {
  char current_val[CRSF_LEN_PAYLOAD_MAX];
  uint8_t length_max;
} crsf_settings_entry_value_string;

typedef struct {
  char name[CRSF_LEN_PARAMETER_SETTINGS_ENTRY_SOME_CHAR];
} crsf_settings_entry_value_folder;

typedef struct {
  char display[CRSF_LEN_PAYLOAD_MAX];
} crsf_settings_entry_value_info;

typedef struct {
  crsf_parameter_settings_entry_cmd_step step;
  uint8_t timeout;
  char info[CRSF_LEN_PARAMETER_SETTINGS_ENTRY_SOME_CHAR];
} crsf_settings_entry_value_command;

typedef struct {
} crsf_settings_entry_value_vtx;

// TODO: В документации неверное описание!
//       Проверить на железе!!!
typedef struct {
  uint8_t sync;
  uint8_t len;
  uint8_t ext_dest;
  uint8_t ext_src;

  uint8_t field_index;
  uint8_t remaining_chunks;
  uint8_t parent;
  crsf_parameter_settings_entry_type type;
  char label[CRSF_LEN_PAYLOAD_MAX];
  uint8_t value[CRSF_LEN_PAYLOAD_MAX];
} crsf_parameter_settings_entry;

// uint8_t crsf_default2parameter_settings_entry(crsf_default* in_pkt, crsf_parameter_settings_entry* out_pkt);
