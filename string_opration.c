/*
 * File:   string_opration.c
 * Author: kouda
 *
 * Created on 2022/09/04, 20:13
 */

#include "datas.h"
#define ST_SIZE 100

const unsigned char mask[] = {
    0b11111110, 0b11111100, 0b11111000, 0b11110000,
    0b11100000, 0b11000000, 0b10000000
};

//1010100110110110010101000

//  10101001-10110110-01010100-0
//   10-1010011-0110110-01010100
//    00-0101010-01101101-10010101

unsigned char st_data[ST_SIZE] = {0};
unsigned char st_buf[ST_SIZE] = {0};
unsigned long long index = 0;
const unsigned long long MAX_SIZE = ST_SIZE * 8;
const int data_size = sizeof(DATA_TYPE) * 8;

int get_size(char c){
    if(c >= 'A' && c <= 'Z'){
        return size_char[c - 'A'];
    } else if(c >= '0' && c <= '9'){
        return size_num[c - '0'];
    } else{
        for(int i = 0;i < SYMBOL_KIND;i++){
            if(symbols[i] == c){
                return size_symbol[i];
            }
        }
    }
    return -1;
}

int next(char c){
    int size;
    if((size = get_size(c)) > 0){
        index += size + 2;
    } else {
        LCD_Clear();
        LCD_Character(c);
        LCD_String(" is Error");
    }
    if(index + data_size + 3 < MAX_SIZE){
        return 1;
    } 
    return 0;
}

int char_add(DATA_TYPE c, int size){
    if((index + size + 2) >= MAX_SIZE){
        return -1;
    }
    for(int i = 0;i < size;i++){
        if(c & 1){
            st_buf[index / 8] |= bits[index % 8];
        }
        c >>= 1;
        index++;
    }
    index += 2;
    return 0;
}

int change_morce(char st[] ,int size){
    int bit_size = 0;
    for(int i = 0;i < size;i++){
        bit_size +=  get_size(st[i]);
    }
}

