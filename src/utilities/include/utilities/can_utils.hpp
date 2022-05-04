//
// Created by ryuzo on 2022/05/04.
//

#ifndef BUILD_CAN_UTILS_HPP
#define BUILD_CAN_UTILS_HPP

#include <cstdint>

double convert_byte_to_double(uint8_t (&bytes)[8]);
float convert_byte_to_float(uint8_t (&bytes)[4]);
short convert_byte_to_f16(uint8_t(&bytes)[2]);

void convert_float_to_byte(float data, uint8_t (&bytes)[4]);
void convert_double_to_byte(double data, uint8_t (&bytes)[8]);
void convert_f16_to_byte(short data, uint8_t(&bytes)[2]);

short f32tof16(float a);
float f16tof32(short a);

#endif //BUILD_CAN_UTILS_HPP
