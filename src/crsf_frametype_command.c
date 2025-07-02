#include "crsf_frametype_command.h"

// TODO: Проверить на реальном железе, получить эти пакеты от FC и Lua скрипта
//  CRSF_COMMAND_SUBCMD_RX - CRSF_COMMAND_SUBCMD_RX_BIND
uint8_t crsf_cmd_rx_bind2array(uint8_t sync,
                               uint8_t ext_dest,
                               uint8_t ext_src,
                               uint8_t* out_pkt) {
  out_pkt[0] = sync; // TODO: Определить, всегда 0xC8 или же один из CRSF_ADDRESS
  out_pkt[1] = 0x07;
  out_pkt[2] = CRSF_FRAMETYPE_COMMAND;
  out_pkt[3] = ext_dest;
  out_pkt[4] = ext_src;
  out_pkt[5] = CRSF_COMMAND_SUBCMD_RX;
  out_pkt[6] = CRSF_COMMAND_SUBCMD_RX_BIND;
  out_pkt[7] = crc8_ba_calc(out_pkt + 2, 5);
  out_pkt[8] = crc8_d5_calc(out_pkt + 2, 6);
  return 0x09;
}

//  CRSF_COMMAND_SUBCMD_RX - COMMAND_MODEL_SELECT_ID
uint8_t crsf_cmd_model_select_id(uint8_t sync,
                                 uint8_t ext_dest,
                                 uint8_t ext_src,
                                 uint8_t model_id,
                                 uint8_t* out_pkt) {
  out_pkt[0] = sync; // TODO: Определить, всегда 0xC8 или же один из CRSF_ADDRESS
  out_pkt[1] = 0x07;
  out_pkt[2] = CRSF_FRAMETYPE_COMMAND;
  out_pkt[3] = ext_dest; // XXX: Может, всегда CRSF_ADDRESS_CRSF_TRANSMITTER?
  out_pkt[4] = ext_src;  // XXX: Может, всегда CRSF_ADDRESS_RADIO_TRANSMITTER?
  out_pkt[5] = CRSF_COMMAND_SUBCMD_RX;
  out_pkt[6] = CRSF_COMMAND_MODEL_SELECT_ID;
  out_pkt[7] = model_id;
  out_pkt[8] = crc8_ba_calc(out_pkt + 2, 6);
  out_pkt[9] = crc8_d5_calc(out_pkt + 2, 7);
  return 0x0A;
}
