//
// Created by dolphilia on 2023/04/05.
//

#ifndef RAIA_DRAW_UTIL_PRIMITIVE3D_H
#define RAIA_DRAW_UTIL_PRIMITIVE3D_H

#include <math.h>
#include <stdint.h>

//typedef struct {
//    double x;
//    double y;
//} raia_point2d_t;
//
//typedef struct {
//    double x;
//    double y;
//    double z;
//} raia_point3d_t;
//
//typedef struct {
//    double x;
//    double y;
//    double z;
//    double angle;
//} raia_vector_t;
//
//typedef struct {
//    int x;
//    int y;
//} raia_point_t;
//
//typedef struct {
//    int width;
//    int height;
//} raia_size_t;

//typedef struct {
//    raia_size_t canvas;
//    raia_size_t canvas_half;
//    //double ginfo_winx;
//    //double ginfo_winy;
//    //double wincx;
//    //double wincy;
//    double ax; // カメラなどの角度
//    double ay;
//    double az;
//    double af; // 0.0 or 1.0
//    double bx;
//    double by;
//    double bz;
//    double cx;
//    double cy;
//    double cz;
//    double ex;
//    double ey;
//    double ez;
//    double ef;
//    double dx;
//    double dy;
//    double dz;
//    double df;
//    double cos0;
//    double sin0;
//    double cos1;
//    double sin1;
//    double l_cos1;
//    double LGSm00; // Local->Global->Screen Matrix
//    double LGSm10;
//    double LGSm20;
//    double LGSmpx;
//    double LGSm01;
//    double LGSm11;
//    double LGSm21;
//    double LGSmpy;
//    double LGSm02;
//    double LGSm12;
//    double LGSm22;
//    double LGSmpz;
//    double GSm00; // Global->Screen Matrix
//    double GSm10;
//    double GSmpx;
//    double GSm01;
//    double GSm11;
//    double GSm21;
//    double GSmpy;
//    double GSm02;
//    double GSm12;
//    double GSm22;
//    double GSmpz;
//} raia_d3m_t;

void d3set_winx(double x);
void d3set_winy(double y);
double d3dist(double p1, double p2, double p3);
double d3dist_2(double p1, double p2);
double d3dist_3(double p1);
double d3rotateX(double x0, double y0, double va);
double d3rotateY(double x0, double y0, double va);
double d3vrotateX(double x0, double y0, double z0, double vx, double vy, double vz, double va);
double d3vrotateY(double x0, double y0, double z0, double vx, double vy, double vz, double va);
double d3vrotateZ(double x0, double y0, double z0, double vx, double vy, double vz, double va);
void d3setlocalmx(double LGmpx, double LGmpy, double LGmpz, double LGm00, double LGm10, double LGm20, double LGm01, double LGm11, double LGm21, double LGm02, double LGm12, double LGm22);
void d3setcamx(double cpx, double cpy, double cpz, double ppx, double ppy, double ppz, double ppv);
void d3setcam(double cpx, double cpy, double cpz, double tx, double ty, double tz, double tv);
void d3setcam_2(double cpx, double cpy, double cpz, double tx, double ty, double tz);
void d3setcam_3(double cpx, double cpy, double cpz, double tx, double ty);
void d3setcam_4(double cpx, double cpy, double cpz, double tx);
void d3setcam_5(double cpx, double cpy, double cpz);
void d3setcam_6(double cpx, double cpy);
void d3setcam_7(double cpx);
void d3setcam_8();
void d3setlocal(double p1, double p2, double p3, double p4, double p5, double p6, double p7, double p8, double p9, double p10, double p11, double p12);
void d3setlocal_2(double p1, double p2, double p3, double p4, double p5, double p6, double p7, double p8, double p9, double p10, double p11);
void d3setlocal_3(double p1, double p2, double p3, double p4, double p5, double p6, double p7, double p8, double p9, double p10);
void d3setlocal_4(double p1, double p2, double p3, double p4, double p5, double p6, double p7, double p8, double p9);
void d3setlocal_5(double p1, double p2, double p3, double p4, double p5, double p6, double p7, double p8);
void d3setlocal_6(double p1, double p2, double p3, double p4, double p5, double p6, double p7);
void d3setlocal_7(double p1, double p2, double p3, double p4, double p5, double p6);
void d3setlocal_8(double p1, double p2, double p3, double p4, double p5);
void d3setlocal_9(double p1, double p2, double p3, double p4);
void d3setlocal_10(double p1, double p2, double p3);
void d3setlocal_11(double p1, double p2);
void d3setlocal_12(double p1);
void d3setlocal_13();
void d3trans(double inx, double iny, double inz);
void d3transTypeE(double inx, double iny, double inz);
void d3vpos(double v01, double v02, double v03);
double d3getposX(double x, double y, double z);
double d3getposY(double x, double y, double z);
double d3getdx();
double d3getdy();
double d3getdz();
double d3getex();
double d3getey();
double d3getez();

#endif //RAIA_DRAW_UTIL_PRIMITIVE3D_H
