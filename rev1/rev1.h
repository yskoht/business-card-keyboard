#pragma once

#include "pakbd.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"


#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

#define LAYOUT( \
  L00, L01,    R00, R01,\
  L10, L11,    R10, R11\
  ) \
  { \
    { L00, L01 },\
    { L10, L11 },\
    { R00, R01 },\
    { R10, R11 }\
  }

