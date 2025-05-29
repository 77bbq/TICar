#ifndef _ENCONDER_H
#define _ENCONDER_H
#include <stdint.h>
void enconder_init(void);
void GROUP1_IRQHandler(void);
extern volatile int32_t conter1 ;
extern volatile int32_t conter2 ;
extern volatile int32_t conter3 ;
extern volatile int32_t conter4 ;
#endif
