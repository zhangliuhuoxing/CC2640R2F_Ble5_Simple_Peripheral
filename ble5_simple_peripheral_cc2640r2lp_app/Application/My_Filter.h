#ifndef __FILTER_H
#define __FILTER_H

#include <sys/stdint.h>

uint32_t Moving_Average(uint8_t item, uint8_t width_num, uint32_t in);
float Moving_Median(uint8_t item, uint8_t width_num, float in);

#endif
