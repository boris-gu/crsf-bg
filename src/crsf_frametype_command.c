#include "crsf_frametype_command.h"

uint8_t crsf_default2command(crsf_default* in_pkt, crsf_command* out_pkt){
  if (in_pkt->type != CRSF_FRAMETYPE_COMMAND) {
    return 0;
  }
  out_pkt->sync = in_pkt->sync;
  out_pkt->ext_dest = in_pkt->payload[0];
  out_pkt->ext_src = in_pkt->payload[1];
  out_pkt->command_type = in_pkt->payload[2];
  out_pkt->command_data_size = in_pkt->len - 2 - 5; // - type, [ext_dest, ext_src, CRSF_COMMAND_SUBCMD_RX, CRSF_COMMAND_SUBCMD_GENERAL, crc8_ba], crc8
  for (uint8_t i = 0; i < out_pkt->command_data_size && i < 10; i++) {
    out_pkt->command_data[i] = in_pkt->payload[3 + i];
  }
}

// TODO: Переписань нормально для любых команд
uint8_t crsf_command2array(crsf_command* in_pkt, uint8_t* out_pkt) {
  out_pkt[0] = in_pkt->sync;
  out_pkt[1] = 0x08;
  out_pkt[2] = CRSF_FRAMETYPE_COMMAND;
  out_pkt[3] = in_pkt->ext_dest;
  out_pkt[4] = in_pkt->ext_src;

  out_pkt[5] = in_pkt->command_type;
  out_pkt[6] = in_pkt->command_id;
  out_pkt[7] = in_pkt->command_data[0]; // FIXME: данные могут быть больше  1 байта
  out_pkt[8] = crc8_ba_calc(out_pkt + 2, 6);
  out_pkt[9] = crc8_d5_calc(out_pkt + 2, 7);
  return out_pkt[1] + 2;
}
