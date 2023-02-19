/*
 * File:   variable.c
 * Author: kouda
 *
 * Created on 2022/09/04, 19:32
 */

#include "datas.h"

unsigned short int a;
int A = 0b1011;

int kakko = 0b110101101101011;

const DATA_TYPE char_datas[] = {
    0b1011, 0b11010101, 0b110101101, 0b110101, 0b110101, 0b1, 0b10101101, 0b1101101,
    0b1010101, 0b101, 0b1011011011, 0b1101011, 0b10110101, 0b11011, 0b1101, 0b11011011, 
    0b101101101, 0b1101101011, 0b101101, 0b10101, 0b11, 0b101011, 0b10101011, 0b1011011,
    0b110101011, 0b1101011011, 0b110110101
};

const int size_char[] = {
    4, 8, 9, 6, 6 ,1, 8, 7, 
    7, 3, 10, 7, 8, 5, 4, 8,
    9, 10, 6, 5, 2, 6, 8, 7,
    9, 10, 9
};

const DATA_TYPE symbols[] = {
    0b10110101101011, 0b110110101011011, 0b11011011010101, 0b1010110110101,
    0b101101101101101, 0b1101010101011, 0b110101101101, 0b110101101101011, 
    0b11010101101, 0b11010101011, 0b10110101101, 0b1011010101101,
    0b110101011, 0b10110110101101              
};

const int size_symbol[] = {
    14, 15, 14, 13, 
    15, 13, 12, 15,
    11, 11, 11, 13,
    9, 14
};

const DATA_TYPE num_datas[] = {
    0b11011011011011, 0b1011011011011, 0b101011011011, 0b10101011011,
    0b1010101011, 0b101010101, 0b1101010101, 0b11011010101, 
    0b110110110101, 0b1101101101101
};

const int size_num[] = {
    14, 13, 12, 11,
    10, 9, 10, 11,
    12, 13
};

const DATA_TYPE delete = 0b101010101010101;

const DATA_TYPE END = 0;

const unsigned char bits[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};