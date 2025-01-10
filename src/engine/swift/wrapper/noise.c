// noise.c

#include <stdlib.h>
#include <stdint.h>

/*
  Swift から呼ばれる関数。 
  ピクセル配列 (unsigned char = GLubyte) をランダム値で埋める。
  
  - pixels: ピクセル配列
  - length: 要素数 (pixelCount)
*/
void swift_generate_random_noise(uint8_t *pixels, int length) {
    for (int i = 0; i < length; i++) {
        // 0～255 の乱数を格納
        // rand() % 256 でもいいが、 rand() & 0xFF でも可
        pixels[i] = (uint8_t)(rand() & 0xFF);
    }
}