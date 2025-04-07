#pragma once

#include "crsf_frametype_default.h"

/**
 * @brief Channels data (both handset to TX and RX to flight controller)
 */
typedef struct {
  uint8_t sync;    ///< CRSF_ADDRESS
  uint16_t ch[16]; ///< 16 RC channels
} crsf_rc_channels_packed;


/**
 * @brief Get a packet with RC channels from a packet with a raw payload
 * @param in_pkt  Default packet
 * @param out_pkt Packet with RC channels
 * @return 1 if successful, else 0
 */
uint8_t crsf_default2rc_channels_packed(crsf_default* in_pkt, crsf_rc_channels_packed* out_pkt);

/**
 * @brief 
 * @param in_pkt  Packet with RC channels
 * @param out_pkt Byte array
 * @return Number of bytes in out_pkt
 */
uint8_t crsf_rc_channels_packed2array(crsf_rc_channels_packed* in_pkt, uint8_t* out_pkt);

/**
 * @brief Convert ticks to us
 * 
 * Ticks is internal CRSF format, range: 0-1984
 * Us is format that handset works with and which is more understandable to the user
 * 172 ticks = 988 us
 * 192 ticks = 1000 us
 * 992 ticks = 1500 us
 * 1792 ticks = 2000 us
 * 1811 ticks = 2012 us
 * @param value Value in ticks
 * @return Value in us
 */
uint16_t ticks2us(uint16_t value);

/**
 * @brief Convert us to ticks
 * 
 * Ticks is internal CRSF format, range: 0-1984 
 * Us is format that handset works with and which is more understandable to the user
 * 988 us = 172 ticks
 * 1000 us = 192 ticks
 * 1500 us = 992 ticks
 * 2000 us = 1792 ticks
 * 2012 us = 1811 ticks
 * @param value Value in us
 * @return Value in ticks
 */
uint16_t us2ticks(uint16_t value);
