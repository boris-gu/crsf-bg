#include "crsf_frametype_parameter_write.h"

uint8_t crsf_parameter_write_UINT8_array(uint8_t field_index, uint8_t value, uint8_t* out_pkt) {
  out_pkt[0] = CRSF_ADDRESS_CRSF_TRANSMITTER;
  out_pkt[1] = 0x06;
  out_pkt[2] = CRSF_FRAMETYPE_PARAMETER_WRITE;
  out_pkt[3] = CRSF_ADDRESS_CRSF_TRANSMITTER;
  out_pkt[4] = CRSF_ADDRESS_ELRS_LUA;
  out_pkt[5] = field_index;
  out_pkt[6] = value;
  out_pkt[7] = crc8_d5_calc(out_pkt + 2, 5);
  return 0x08;
}

uint8_t crsf_parameter_write_INT8_array(uint8_t field_index, int8_t value, uint8_t* out_pkt) {
  out_pkt[0] = CRSF_ADDRESS_CRSF_TRANSMITTER;
  out_pkt[1] = 0x06;
  out_pkt[2] = CRSF_FRAMETYPE_PARAMETER_WRITE;
  out_pkt[3] = CRSF_ADDRESS_CRSF_TRANSMITTER;
  out_pkt[4] = CRSF_ADDRESS_ELRS_LUA;
  out_pkt[5] = field_index;
  out_pkt[6] = value;
  out_pkt[7] = crc8_d5_calc(out_pkt + 2, 5);
  return 0x08;
}

uint8_t crsf_parameter_write_UINT16_array(uint8_t field_index, uint16_t value, uint8_t* out_pkt) {
  out_pkt[0] = CRSF_ADDRESS_CRSF_TRANSMITTER;
  out_pkt[1] = 0x07;
  out_pkt[2] = CRSF_FRAMETYPE_PARAMETER_WRITE;
  out_pkt[3] = CRSF_ADDRESS_CRSF_TRANSMITTER;
  out_pkt[4] = CRSF_ADDRESS_ELRS_LUA;
  out_pkt[5] = field_index;
  out_pkt[6] = (value >> 8) & 0xFF;
  out_pkt[7] = value & 0xFF;
  out_pkt[8] = crc8_d5_calc(out_pkt + 2, 6);
  return 0x09;
}

uint8_t crsf_parameter_write_INT16_array(uint8_t field_index, int16_t value, uint8_t* out_pkt) {
  out_pkt[0] = CRSF_ADDRESS_CRSF_TRANSMITTER;
  out_pkt[1] = 0x07;
  out_pkt[2] = CRSF_FRAMETYPE_PARAMETER_WRITE;
  out_pkt[3] = CRSF_ADDRESS_CRSF_TRANSMITTER;
  out_pkt[4] = CRSF_ADDRESS_ELRS_LUA;
  out_pkt[5] = field_index;
  out_pkt[6] = (value >> 8) & 0xFF;
  out_pkt[7] = value & 0xFF;
  out_pkt[8] = crc8_d5_calc(out_pkt + 2, 6);
  return 0x09;
}

uint8_t crsf_parameter_write_FLOAT_array(uint8_t field_index, int32_t value, uint8_t* out_pkt) {
  out_pkt[0] = CRSF_ADDRESS_CRSF_TRANSMITTER;
  out_pkt[1] = 0x09;
  out_pkt[2] = CRSF_FRAMETYPE_PARAMETER_WRITE;
  out_pkt[3] = CRSF_ADDRESS_CRSF_TRANSMITTER;
  out_pkt[4] = CRSF_ADDRESS_ELRS_LUA;
  out_pkt[5] = field_index;
  out_pkt[6] = (value >> 24) & 0xFF;
  out_pkt[7] = (value >> 16) & 0xFF;
  out_pkt[6] = (value >> 8) & 0xFF;
  out_pkt[7] = value & 0xFF;
  out_pkt[8] = crc8_d5_calc(out_pkt + 2, 8);
  return 0x0B;
}

uint8_t crsf_parameter_write_SELECT_array(uint8_t field_index, char* value, uint8_t len, uint8_t* out_pkt) {
  out_pkt[0] = CRSF_ADDRESS_CRSF_TRANSMITTER;
  out_pkt[1] = len + 5;
  out_pkt[2] = CRSF_FRAMETYPE_PARAMETER_WRITE;
  out_pkt[3] = CRSF_ADDRESS_CRSF_TRANSMITTER;
  out_pkt[4] = CRSF_ADDRESS_ELRS_LUA;
  out_pkt[5] = field_index;

  for (uint8_t i = 0; i < len; i++) {
    out_pkt[i + 6] = value[i];
  }
  out_pkt[len + 6] = crc8_d5_calc(out_pkt + 2, len + 4);
  return len + 7;
}

uint8_t crsf_parameter_write_STRING_array(uint8_t field_index, char* value, uint8_t len, uint8_t* out_pkt) {
  out_pkt[0] = CRSF_ADDRESS_CRSF_TRANSMITTER;
  out_pkt[1] = len + 5;
  out_pkt[2] = CRSF_FRAMETYPE_PARAMETER_WRITE;
  out_pkt[3] = CRSF_ADDRESS_CRSF_TRANSMITTER;
  out_pkt[4] = CRSF_ADDRESS_ELRS_LUA;
  out_pkt[5] = field_index;

  for (uint8_t i = 0; i < len; i++) {
    out_pkt[i + 6] = value[i];
  }
  out_pkt[len + 6] = crc8_d5_calc(out_pkt + 2, len + 4);
  return len + 7;
}