/*
 * File:   functions.c
 * Author: ElektroNeo
 *
 * Created on 01 A?ustos 2019 Per?embe, 12:37
 */


#include "config.h"

uint16_t map(uint16_t x, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
