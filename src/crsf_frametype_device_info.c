#include "crsf_frametype_device_info.h"

uint8_t crsf_default2device_info(crsf_default* in_pkt, crsf_device_info* out_pkt) {
  out_pkt->sync = in_pkt->sync;
  out_pkt->ext_dest = in_pkt->payload[0];
  out_pkt->ext_src = in_pkt->payload[1];

  uint8_t temp_counter = 2;
  for (uint8_t i = 0; i < CRSF_LEN_DEVICE_INFO_NAME_MAX; i++, temp_counter++) {
    out_pkt->name[i] = in_pkt->payload[temp_counter];
    if (out_pkt->name[i] == 0x00) {
      break;
    }
  }
  // TODO: Т.к. строка переменной длины, надо проверить, что ее составитель
  //       точно завершил ее 0x00, иначе мы выйдем за пределы in_pkt->payload
  //       Поэтому необходимо проверить получившуюся общую длину
  // TODO: Проверить
  out_pkt->serial_num = (uint32_t)in_pkt->payload[++temp_counter] << 24 |
                        (uint32_t)in_pkt->payload[++temp_counter] << 16 |
                        (uint32_t)in_pkt->payload[++temp_counter] << 8  |
                        (uint32_t)in_pkt->payload[++temp_counter];

  out_pkt->hard_ver = (uint32_t)in_pkt->payload[++temp_counter] << 24 |
                      (uint32_t)in_pkt->payload[++temp_counter] << 16 |
                      (uint32_t)in_pkt->payload[++temp_counter] << 8  |
                      (uint32_t)in_pkt->payload[++temp_counter];
  
  out_pkt->soft_ver = (uint32_t)in_pkt->payload[++temp_counter] << 24 |
                      (uint32_t)in_pkt->payload[++temp_counter] << 16 |
                      (uint32_t)in_pkt->payload[++temp_counter] << 8  |
                      (uint32_t)in_pkt->payload[++temp_counter];
  
  out_pkt->config_count = in_pkt->payload[++temp_counter];
  out_pkt->protocol_ver = in_pkt->payload[++temp_counter];
  return 1;
}
