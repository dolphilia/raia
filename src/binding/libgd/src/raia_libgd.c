#include "raia_libgd.h"

//
// コンテキスト
//

//RAIA_API void raia_glfw_make_context_current(GLFWwindow *window) {
//}

#include "gd.h"
#include <stdio.h>
#include <stdlib.h>

void raia_gdImageDestroy(gdImagePtr im) {
    gdImageDestroy(im);
}

gdImagePtr raia_gdImageCreateTrueColor(int sx, int sy) {
    return gdImageCreateTrueColor(sx, sy);
}

void raia_gdImageLine(gdImagePtr im, int x1, int y1, int x2, int y2, int color) {
    gdImageLine(im, x1, y1, x2, y2, color);
}

void raia_gdImageFilledRectangle(gdImagePtr im, int x1, int y1, int x2, int y2, int color) {
    gdImageFilledRectangle(im, x1, y1, x2, y2, color);
}

void raia_gdImageFilledArc(gdImagePtr im, int cx, int cy, int w, int h, int s, int e, int color, int style) {
    gdImageFilledArc(im, cx, cy, w, h, s, e, color, style);
}

// util

void * raia_getPixels_gdImage(gdImagePtr im) {
    return im->pixels;
}

void raia_getPixels_gdImage_RGBA(gdImagePtr im, uint8_t * rgba) {
    int width = im->sx;
    int height = im->sy;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel = im->tpixels[y][x];
            int index = (y * width + x) * 4;
            rgba[index + 0] = gdTrueColorGetRed(pixel);   // R
            rgba[index + 1] = gdTrueColorGetGreen(pixel); // G
            rgba[index + 2] = gdTrueColorGetBlue(pixel);  // B
            rgba[index + 3] = gdTrueColorGetAlpha(pixel); // A
        }
    }
}


int main() {
    gdImagePtr im;
    FILE *fp;
    int cor_rad = 60;

    im = gdImageCreateTrueColor(400, 400);
    gdImageFilledRectangle(im, 0, 0, 399, 399, 0x00FFFFFF);

    gdImageFilledArc (im, cor_rad, 399 - cor_rad, cor_rad *2, cor_rad *2, 90, 180, 0x0, gdPie);

    fp = fopen("b.bmp", "wb");
    if (!fp) {
        fprintf(stderr, "Can't save png image.\n");
        gdImageDestroy(im);
        return 1;
    }
    gdImageBmp(im, fp, 0);
    //gdImageJpeg(im, fp, 80);
    fclose(fp);

    gdImageDestroy(im);
    return 0;
}