/**
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_RC_CHANNELS_PACKED
 */
#pragma once

#include "crsf_frametype_default.h"

typedef struct {
  uint8_t sync;
  uint16_t ch[16];
} crsf_rc_channels_packed;

uint8_t crsf_default2rc_channels_packed(crsf_default* in_pkt, crsf_rc_channels_packed* out_pkt);

uint8_t crsf_rc_channels_packed2array(crsf_rc_channels_packed* in_pkt, uint8_t* out_pkt);

uint16_t ticks2us(uint16_t value);

uint16_t us2ticks(uint16_t value);
