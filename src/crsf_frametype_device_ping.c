#include "crsf_frametype_device_ping.h"

uint8_t crsf_device_ping_array(uint8_t* out_pkt) {
  // XXX: По документации CRSF_ADDRESS_FLIGHT_CONTROLLER, но по коду EdgeTX CRSF_ADDRESS_CRSF_TRANSMITTER
  //      https://github.com/EdgeTX/edgetx/blob/a1cf7564a572ac24ea1ca11504729c0c2b19378b/radio/src/lua/api_general.cpp#L1213
  //      https://github.com/EdgeTX/edgetx/blob/a1cf7564a572ac24ea1ca11504729c0c2b19378b/radio/src/telemetry/crossfire.h#L30
  out_pkt[0] = CRSF_ADDRESS_CRSF_TRANSMITTER;
  out_pkt[1] = 0x04; // LEN 24 byte = 22(16ch, 11 bit) + type + crc8
  out_pkt[2] = CRSF_FRAMETYPE_DEVICE_PING;
  out_pkt[3] = CRSF_ADDRESS_BROADCAST;
  out_pkt[4] = CRSF_ADDRESS_RADIO_TRANSMITTER;
  // TODO: Проверить, что не нужно crc8_ba_calc
  // XXX: Похоже, не нужно
  //      https://github.com/EdgeTX/edgetx/blob/a1cf7564a572ac24ea1ca11504729c0c2b19378b/radio/src/lua/api_general.cpp#L1234
  out_pkt[5] = crc8_d5_calc(out_pkt + 2, 3);
  return 0x06;
}
