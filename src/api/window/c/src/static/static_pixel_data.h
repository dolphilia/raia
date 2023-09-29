//
//  raia_pixel_data.h
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#ifndef static_pixel_data_h
#define static_pixel_data_h

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void init_pixel_data(int width, int height, int samples_per_pixel);
void free_pixel_data(void);
uint8_t* get_pixel_data(void);

#endif /* raia_pixel_data_h */
