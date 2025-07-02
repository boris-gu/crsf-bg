#include "crsf_frametype_radio_id.h"

uint8_t crsf_default2radio_id(crsf_default* in_pkt, crsf_radio_id* out_pkt, uint8_t fix_big_endian) {
  out_pkt->sync = in_pkt->sync;
  if (in_pkt->type != CRSF_FRAMETYPE_RADIO_ID) {
    return 0;
  }
  out_pkt->ext_dest = in_pkt->payload[0];
  out_pkt->ext_src = in_pkt->payload[1];
  if (fix_big_endian) {
    out_pkt->packet_rate = (uint32_t)in_pkt->payload[5] | in_pkt->payload[4] |
                           in_pkt->payload[3] | in_pkt->payload[2];
    out_pkt->shift_corr = (uint32_t)in_pkt->payload[9] | in_pkt->payload[8] |
                          in_pkt->payload[7] | in_pkt->payload[6];
  } else {
    out_pkt->packet_rate = (uint32_t)in_pkt->payload[2];  // TODO: Проверить
    out_pkt->shift_corr = (uint32_t)in_pkt->payload[6];
  }
  return 1;
}
