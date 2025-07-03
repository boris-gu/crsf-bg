#include "crsf_frametype_link_statistics.h"

uint8_t crsf_default2link_statistics(crsf_default* in_pkt, crsf_link_statistics* out_pkt) {
  out_pkt->sync = in_pkt->sync;
  out_pkt->up_rssi1 = in_pkt->payload[0];
  out_pkt->up_rssi2 = in_pkt->payload[1];
  out_pkt->up_quality = in_pkt->payload[2];
  out_pkt->up_snr = in_pkt->payload[3];
  out_pkt->diversity_act_ant = in_pkt->payload[4];
  out_pkt->rf_mode = in_pkt->payload[5];
  out_pkt->up_tx_power = in_pkt->payload[6];
  out_pkt->down_rssi = in_pkt->payload[7];
  out_pkt->down_quality = in_pkt->payload[8];
  out_pkt->down_snr = in_pkt->payload[9];
}

uint8_t crsf_link_statistics2array(crsf_link_statistics* in_pkt, uint8_t* out_pkt) {

}