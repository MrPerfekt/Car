/*!
Copyright 2013 Andreas Gruber
*/

#include<DefineLib.h>


uint16_t freeSRam () {
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}