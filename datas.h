#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H
#define SIGNAL_TIME 100
#define _XTAL_FREQ 4000000

#include <xc.h> // include processor files - each processor file is guarded.  
#include "lcdlib_xc8_v03.h"

//#define CLOCK(x) {(x) = 0; __delay_ms(PLUS_TIME); (x) = 1;}
#define LAT(sym,num) LAT##sym ##bits.L##sym ##num 
#define P(sym,num) PORT##sym ##bits.R##sym ##num 
#define TRIS(sym,num) TRIS##sym ##bits.TRIS##sym ##num 

typedef unsigned short int DATA_TYPE;

extern const unsigned char bits[];
extern const DATA_TYPE char_datas[];
extern const DATA_TYPE symbol[];
extern const DATA_TYPE num_datas[];
extern const int code_size[];

extern const DATA_TYPE END;

#endif	/* XC_HEADER_TEMPLATE_H */
