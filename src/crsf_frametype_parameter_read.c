#include "crsf_frametype_parameter_read.h"

uint8_t crsf_parameter_read_array(uint8_t field_index, uint8_t chunk_index, uint8_t* out_pkt) {
  out_pkt[0] = CRSF_ADDRESS_CRSF_TRANSMITTER;
  out_pkt[1] = 0x06; // LEN 24 byte = 22(16ch, 11 bit) + type + crc8
  out_pkt[2] = CRSF_FRAMETYPE_PARAMETER_READ;
  out_pkt[3] = CRSF_ADDRESS_CRSF_TRANSMITTER;
  out_pkt[4] = CRSF_ADDRESS_ELRS_LUA;
  out_pkt[5] = field_index;
  out_pkt[6] = chunk_index;
  out_pkt[7] = crc8_d5_calc(out_pkt + 2, 5);
  return 0x08;
}
