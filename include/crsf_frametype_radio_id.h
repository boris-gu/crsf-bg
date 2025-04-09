/**
 * Extended type used for OPENTX_SYNC
 */
#pragma once

#include "crsf_frametype_default.h"

typedef enum {
  CRSF_FRAMETYPE_OPENTX_SYNC = 0x10, ///< Maximum payload size
} crsf_radio_id_subtype ;


typedef struct {
  uint8_t sync;

  uint8_t ext_dest;  // 0xEA CRSF_ADDRESS_RADIO_TRANSMITTER
  uint8_t ext_src;   // 0xEE CRSF_ADDRESS_CRSF_TRANSMITTER
  uint8_t subtype;   // 0x10 CRSF_FRAMETYPE_OPENTX_SYNC

  // TODO: Проверить, беззнаковый ли
  uint32_t packet_rate; // us * 10 (Big endian)
  // TODO: Значение в десятой доле микросекунды
  // UPD Похоже, это значение никак не используется в EdgeTX
  // https://github.com/EdgeTX/edgetx/blob/50b32e6cfc37fe70a829e0c4b64f017993526f08/radio/src/telemetry/crossfire.cpp#L279
  // https://github.com/EdgeTX/edgetx/blob/50b32e6cfc37fe70a829e0c4b64f017993526f08/radio/src/telemetry/telemetry.cpp#L526C64-L526C75
  int32_t shift_corr;
} crsf_radio_id;


uint8_t crsf_default2radio_id(crsf_default* in_pkt, crsf_radio_id* out_pkt, uint8_t fix_big_endian);

uint8_t crsf_radio_id2array(crsf_radio_id* in_pkt, uint8_t* out_pkt, uint8_t fix_big_endian);
