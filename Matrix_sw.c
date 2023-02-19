/*
 * File:   variable.c
 * Author: kouda
 *
 * Created on 2022/09/04, 19:32
 */
#include "datas.h"


#define COL_PORT PORTA
#define COL_BIT 0b01110000
#define ROW_PORT LATA
#define ROW_BIT 0b00001111
#define MATRIX_TRIS TRISA

#define RED_LED   LAT(B,0)
#define GREEN_LED LAT(B,1)
#define SW1_LED   LAT(B,2)
#define SW2_LED   LAT(B,3)

_Bool sw_status[4][3] = { 0 };                  /* �X�C�b�`���V���ɉ����ꂽ��1������B */
_Bool sw_flg = 0;                               /* 1�ł������ꂽ�X�C�b�`�������1�ɂȂ�t���O */
unsigned char col_bits[] = { 0x10, 0x20, 0x40 };/* �}�g���N�X�X�C�b�`�𓮂����Ƃ��ɁA1?3�s�ɑΉ�����r�b�g */
unsigned char row_bits[] = { 1, 2, 4, 8 };      /* �X�C�b�`��ǂݎ��Ƃ��ɁA1?4��ɑΉ�����r�b�g */

static _Bool old_sw[4][3] = { 0 };
static _Bool old_state[4][3] = { 0 };

/**
 * sw_check : �}�g���N�X�X�C�b�`�̒l���`�F�b�N����
 * �Ă΂�邽�тɃX�C�b�`�̒l�����āA2��A����ON���肳�ꂽ��
 * sw_state�z��Ɋi�[
 * @return �����ꂽ�X�C�b�`����������1�A����������0
 */
int sw_check(){
    static int check_row = 0;
    int is_push = 0;
    LCD_Clear();
    
    /* �Ă΂�邽�тɁA1?3�s�� */
    if(++check_row > 3){
        check_row = 0;
    }
    LCD_Number(check_row);
    LCD_String("  ");
    if(COL_PORT & COL_BIT){
        sw_flg = 1;
        for(int i = 0;i < 3;i++){
            if((COL_PORT & col_bits[i]) == old_sw[check_row][i]){
                if(old_sw[check_row][i] && (old_state[check_row][i] == 0)){
                    sw_status[check_row][i] = 1;
                    is_push = 1;
                    LCD_String("push");
                }
                old_state[check_row][i] == old_sw[check_row][i];
            }
            
           
            old_sw[check_row][i] = (COL_PORT & col_bits[i]);
        }
    } else {
        for(int i = 0;i < 3;i++){
            old_sw[check_row][i] = 0;
        }
    }
    for(int i = 0;i < 3;i++){
        LCD_Number((old_sw[check_row][i]) != 0);
        LCD_Number((COL_PORT & col_bits[i]) != 0);
    }
     LCD_String("\n");
     for(int i = 0;i < 3;i++){
        LCD_Number((sw_status[check_row][i]) != 0);
        LCD_Number((old_state[check_row][i]) != 0);
    }
            
    ROW_PORT = row_bits[(check_row + 1 <= 3) ? check_row + 1 : 0];
    return is_push;
}

void sw_init(){
    MATRIX_TRIS &= (~ROW_BIT);
    MATRIX_TRIS |= COL_BIT;
    ROW_PORT = row_bits[0];
}