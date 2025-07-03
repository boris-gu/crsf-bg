/**
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_LINK_STATISTICS
 */
#pragma once

#include "crsf_frametype_default.h"

typedef struct {
  uint8_t sync;

  uint8_t up_rssi1;   // Uplink RSSI Ant. 1 ( dBm * -1 )
  uint8_t up_rssi2;   // Uplink RSSI Ant. 2 ( dBm * -1 )
  uint8_t up_quality; // Uplink Package success rate / Link quality ( % )
  int8_t up_snr;      // Uplink SNR ( dB, or dB*4 for TBS I believe )
  uint8_t diversity_act_ant; // Diversity active antenna ( enum ant. 1 = 0, ant. 2 = 1 )
  uint8_t rf_mode;      // RF Mode ( 500Hz, 250Hz etc, varies based on ELRS Band or TBS )
  uint8_t up_tx_power;  // Uplink TX Power ( enum 0mW = 0, 10mW, 25 mW, 100 mW, 500 mW, 1000 mW, 2000mW, 50mW )
  uint8_t down_rssi;    // Downlink RSSI ( dBm * -1 )
  uint8_t down_quality; // Downlink package success rate / Link quality ( % )
  int8_t down_snr;      // Downlink SNR ( dB )
} crsf_link_statistics;

uint8_t crsf_default2link_statistics(crsf_default* in_pkt, crsf_link_statistics* out_pkt);

uint8_t crsf_link_statistics2array(crsf_link_statistics* in_pkt, uint8_t* out_pkt);
