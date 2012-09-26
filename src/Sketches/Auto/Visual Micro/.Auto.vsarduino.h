//Board = Arduino Uno
#define ARDUINO 101
#define __AVR_ATmega328P__
#define F_CPU 16000000L
#define __AVR__
#define __cplusplus
#define __attribute__(x)
#define __inline__
#define __asm__(x)
#define __extension__
#define __ATTR_PURE__
#define __ATTR_CONST__
#define __inline__
#define __asm__ 
#define __volatile__
#define __builtin_va_list
#define __builtin_va_start
#define __builtin_va_end
#define __DOXYGEN__
#define prog_void
#define PGM_VOID_P int
#define NOINLINE __attribute__((noinline))

typedef unsigned char byte;
extern "C" void __cxa_pure_virtual() {}

void setupDisplay();
void updateDisplay();
void testSet(int state);
void testSetDelay(int state);
void testToogle();
void testToogleDelay();
//already defined in arduno.h
//already defined in arduno.h
void driveTest();
void driveTurn(int angle);
void driveStraight(unsigned long distance);
void driveTest();

#include "C:\Program Files (x86)\arduino-1.0.1\hardware\arduino\variants\standard\pins_arduino.h" 
#include "C:\Program Files (x86)\arduino-1.0.1\hardware\arduino\cores\arduino\arduino.h"
#include "C:\Users\Andreas\Dropbox\Car\src\Sketches\Auto\Auto.ino"
