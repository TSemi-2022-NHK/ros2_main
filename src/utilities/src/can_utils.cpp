//
// Created by ryuzo on 2022/05/04.
//
#include "utilities/can_utils.hpp"

double convert_byte_to_double(uint8_t (&bytes)[8]) {
    union {
        uint8_t bytes[8];
        double data;
    }Data{};
    for (int i = 0; i < 8; ++i) {
        Data.bytes[i] = bytes[i];
    }
    return Data.data;
}

float convert_byte_to_float(uint8_t (&bytes)[4]) {
    union {
        uint8_t bytes[4];
        float data;
    }Data{};
    for (int i = 0; i < 4; ++i) {
        Data.bytes[i] = bytes[i];
    }
    return Data.data;
}

void convert_float_to_byte(float data, uint8_t (&bytes)[4]) {
    union {
        uint8_t bytes[4];
        float data;
    }Data{};
    Data.data = data;
    for (int i = 0; i < 4; ++i) {
        bytes[i] = Data.bytes[i];
    }
}

void convert_double_to_byte(double data, uint8_t (&bytes)[8]) {
    union {
        uint8_t bytes[8];
        double data;
    }Data{};
    Data.data = data;
    for (int i = 0; i < 8; ++i) {
        bytes[i] = Data.bytes[i];
    }
}

short f32tof16(float a){
    return
            (*(int*)&a >> 31 & 0b1) << 15 |
            ((*(int*)&a >> 23 & 0b11111111) - 127 + 15) << 10 |
            (*(int*)&a >> 13 & 0b1111111111);
}

float f16tof32(short a){
    int b =
            (a >> 15 & 0b1) << 31 |
            ((a >> 10 & 0b11111) - 15 + 127 ) << 23 |
            (a & 0b1111111111) << 13;
    return *(float*)&b;
}

short convert_byte_to_f16(uint8_t(&bytes)[2]){
    union {
        uint8_t bytes[2];
        short data;
    }Data{};
    for (int i = 0; i < 2; ++i) {
        Data.bytes[i] = bytes[i];
    }
    return Data.data;
}

void convert_f16_to_byte(short data, uint8_t(&bytes)[2]){
    union {
        uint8_t bytes[2];
        short data;
    }Data{};
    Data.data = data;
    for (int i = 0; i < 2; ++i) {
        bytes[i] = Data.bytes[i];
    }
}