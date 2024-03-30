//
// Created by dolphilia on 2023/04/05.
//

#include "util_primitive3d.h"

double ginfo_winx;
double ginfo_winy;
double wincx;
double wincy;

static double ax = 0.0;
static double ay = 0.0;
static double az = 0.0;
static double af = 0.0;
static double bx = 0.0;
static double by = 0.0;
static double bz = 0.0;
static double cx = 0.0;
static double cy = 0.0;
static double cz = 0.0;
static double ex = 0.0;
static double ey = 0.0;
static double ez = 0.0;
static double ef = 0.0;
static double dx = 0.0;
static double dy = 0.0;
static double dz = 0.0;
static double df = 0.0;
static double cos0 = 0.0;
static double sin0 = 0.0;
static double cos1 = 0.0;
static double sin1 = 0.0;
static double l_cos1 = 0.0;
static double LGSm00 = 0.0;
static double LGSm10 = 0.0;
static double LGSm20 = 0.0;
static double LGSmpx = 0.0;
static double LGSm01 = 0.0;
static double LGSm11 = 0.0;
static double LGSm21 = 0.0;
static double LGSmpy = 0.0;
static double LGSm02 = 0.0;
static double LGSm12 = 0.0;
static double LGSm22 = 0.0;
static double LGSmpz = 0.0;
static double GSm00 = 0.0;
static double GSm10 = 0.0;
static double GSmpx = 0.0;
static double GSm01 = 0.0;
static double GSm11 = 0.0;
static double GSm21 = 0.0;
static double GSmpy = 0.0;
static double GSm02 = 0.0;
static double GSm12 = 0.0;
static double GSm22 = 0.0;
static double GSmpz = 0.0;



void d3set_winx(double x) {
    ginfo_winx = x;
    wincx = ginfo_winx / 2;
}

void d3set_winy(double y) {
    ginfo_winy = y;
    wincy = ginfo_winy / 2;
}

double d3dist(double p1, double p2, double p3) {
    return sqrt((p1) * (p1) + (p2) * (p2) + (p3) * (p3));
}

double d3dist_2(double p1, double p2) {
    return d3dist(p1, p2, 0);
}

double d3dist_3(double p1) {
    return d3dist(p1, 0, 0);
}

// d3rotate 平面座標回転演算 (x1, y1,  x0, y0,  va)
// 出力変数 x1 y1, 入力値 x0 y0, 回転角度 va
double d3rotateX(double x0, double y0, double va) {
    return x0 * cos(va) - y0 * sin(va);
}

double d3rotateY(double x0, double y0, double va) {
    return x0 * sin(va) + y0 * cos(va);
}

// d3vrotate 任意軸周りの空間回転演算 (x1, y1, z1,  x0, y0, z0,  vx, vy, vz, va)
//出力変数 x1 y1 z1, 入力値 x0 y0 z0, 回転軸ベクトル vx vy vz, 回転角度 va
double d3vrotateX(double x0, double y0, double z0, double vx, double vy, double vz, double va) {
    // 回転軸の単位ベクトル化
    double r = d3dist(vx, vy, vz);
    ax = vx / r;
    ay = vy / r;
    az = vz / r;

    // 回転演算
    sin1 = sin(va);
    cos1 = cos(va);
    l_cos1 = 1.0 - cos1;

    return (ax * ax * l_cos1 + cos1) * x0 + (ax * ay * l_cos1 - az * sin1) * y0 +
           (az * ax * l_cos1 + ay * sin1) * z0;
}

double d3vrotateY(double x0, double y0, double z0, double vx, double vy, double vz, double va) {
    // 回転軸の単位ベクトル化
    double r = d3dist(vx, vy, vz);
    ax = vx / r;
    ay = vy / r;
    az = vz / r;

    // 回転演算
    sin1 = sin(va);
    cos1 = cos(va);
    l_cos1 = 1.0 - cos1;

    return (ax * ay * l_cos1 + az * sin1) * x0 + (ay * ay * l_cos1 + cos1) * y0 +
           (ay * az * l_cos1 - ax * sin1) * z0;
}

double d3vrotateZ(double x0, double y0, double z0, double vx, double vy, double vz, double va) {
    // 回転軸の単位ベクトル化
    double r = d3dist(vx, vy, vz);
    ax = vx / r;
    ay = vy / r;
    az = vz / r;

    // 回転演算
    sin1 = sin(va);
    cos1 = cos(va);
    l_cos1 = 1.0 - cos1;

    return (az * ax * l_cos1 - ay * sin1) * x0 +
           (ay * az * l_cos1 + ax * sin1) * y0 + (az * az * l_cos1 + cos1) * z0;
}

// d3setlocalmx ローカル座標系設定 平行移動量 + 3x3 変形マトリクス (px, py, pz,
// m00, m01, m02,  m10, m11, m12,  m20, m21, m22)
void d3setlocalmx(double LGmpx, double LGmpy, double LGmpz, double LGm00, double LGm10, double LGm20, double LGm01, double LGm11, double LGm21, double LGm02, double LGm12, double LGm22) {

    // Local->Global->Screen Matrix Setup
    // 座標変換演算用マトリクス設定 (Local->Global Matrix と Global->Screen Matrix
    // を合成演算)
    LGSm00 = GSm00 * LGm00 + GSm10 * LGm01;
    LGSm10 = GSm00 * LGm10 + GSm10 * LGm11;
    LGSm20 = GSm00 * LGm20 + GSm10 * LGm21;
    LGSmpx = GSm00 * LGmpx + GSm10 * LGmpy + GSmpx;

    LGSm01 = GSm01 * LGm00 + GSm11 * LGm01 + GSm21 * LGm02;
    LGSm11 = GSm01 * LGm10 + GSm11 * LGm11 + GSm21 * LGm12;
    LGSm21 = GSm01 * LGm20 + GSm11 * LGm21 + GSm21 * LGm22;
    LGSmpy = GSm01 * LGmpx + GSm11 * LGmpy + GSm21 * LGmpz + GSmpy;

    LGSm02 = GSm02 * LGm00 + GSm12 * LGm01 + GSm22 * LGm02;
    LGSm12 = GSm02 * LGm10 + GSm12 * LGm11 + GSm22 * LGm12;
    LGSm22 = GSm02 * LGm20 + GSm12 * LGm21 + GSm22 * LGm22;
    LGSmpz = GSm02 * LGmpx + GSm12 * LGmpy + GSm22 * LGmpz + GSmpz;
}

// d3setcamx カメラ位置設定 (cx, cy, cz,  tx, ty, tz)
void d3setcamx(double cpx, double cpy, double cpz, double ppx, double ppy, double ppz, double ppv) {
    //パラメータ設定
    wincx = ginfo_winx / 2;
    wincy = ginfo_winy / 2;

    //カメラ方向三角比計算
    ax = cpx - ppx;
    ay = cpy - ppy;
    az = cpz - ppz;

    double r0 = sqrt(ax * ax + ay * ay);
    double r1 = sqrt(r0 * r0 + az * az);

    if (r0 != 0.0) {
        cos0 = -ax / r0;
        sin0 = -ay / r0;
    }
    if (r1 != 0.0) {
        cos1 = r0 / r1;
        sin1 = az / r1;
    }

    // Global->Screen Matrix Setup
    //グローバル座標 → スクリーン座標 変換マトリクス

    az = ppv / (0.01 + ginfo_winy); // 視野角

    GSm00 = sin0;
    GSm10 = -cos0; // GSm20 =  0.0
    GSm01 = cos0 * cos1 * az;
    GSm11 = sin0 * cos1 * az;
    GSm21 = -sin1 * az;
    GSm02 = cos0 * sin1;
    GSm12 = sin0 * sin1;
    GSm22 = cos1;

    GSmpx = -(GSm00 * cpx + GSm10 * cpy);
    GSmpy = -(GSm01 * cpx + GSm11 * cpy + GSm21 * cpz);
    GSmpz = -(GSm02 * cpx + GSm12 * cpy + GSm22 * cpz);

    // Local->Global->Screen Matrix Setup
    // 座標変換演算用マトリクス設定 (Global->Screen Matrix で初期化)
    d3setlocalmx(0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
}

// d3setcam カメラ位置設定 (cx, cy, cz,  tx, ty, tz, tv)
// パラメータ省略用マクロ
void d3setcam(double cpx, double cpy, double cpz, double tx, double ty, double tz, double tv) {
    d3setcamx(cpx, cpy, cpz, tx, ty, tz, tv);
}

void d3setcam_2(double cpx, double cpy, double cpz, double tx, double ty, double tz) {
    d3setcamx(cpx, cpy, cpz, tx, ty, tz, 1.0);
}

void d3setcam_3(double cpx, double cpy, double cpz, double tx, double ty) {
    d3setcamx(cpx, cpy, cpz, tx, ty, 0.0, 1.0);
}

void d3setcam_4(double cpx, double cpy, double cpz, double tx) {
    d3setcamx(cpx, cpy, cpz, tx, 0.0, 0.0, 1.0);
}

void d3setcam_5(double cpx, double cpy, double cpz) {
    d3setcamx(cpx, cpy, cpz, 0.0, 0.0, 0.0, 1.0);
}

void d3setcam_6(double cpx, double cpy) {
    d3setcamx(cpx, cpy, 0.0, 0.0, 0.0, 0.0, 1.0);
}

void d3setcam_7(double cpx) {
    d3setcamx(cpx, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
}

void d3setcam_8() {
    d3setcamx(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
}

// d3setlocal ローカル座標系設定 (px, py, pz,  m00, m01, m02,  m10, m11, m12,
// m20, m21, m22)
//パラメータ省略用マクロ (パラメータを省略した場合、ローカル座標系 ==
//グローバル座標系となる)
void d3setlocal(double p1, double p2, double p3, double p4, double p5, double p6, double p7, double p8, double p9, double p10, double p11, double p12) {
    d3setlocalmx(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
}

void d3setlocal_2(double p1, double p2, double p3, double p4, double p5, double p6, double p7, double p8, double p9, double p10, double p11) {
    d3setlocalmx(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, 1.0);
}

void d3setlocal_3(double p1, double p2, double p3, double p4, double p5, double p6, double p7, double p8, double p9, double p10) {
    d3setlocalmx(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, 0.0, 1.0);
}
void d3setlocal_4(double p1, double p2, double p3, double p4, double p5, double p6, double p7, double p8, double p9) {
    d3setlocalmx(p1, p2, p3, p4, p5, p6, p7, p8, p9, 0.0, 0.0, 1.0);
}
void d3setlocal_5(double p1, double p2, double p3, double p4, double p5, double p6, double p7, double p8) {
    d3setlocalmx(p1, p2, p3, p4, p5, p6, p7, p8, 0.0, 0.0, 0.0, 1.0);
}
void d3setlocal_6(double p1, double p2, double p3, double p4, double p5, double p6, double p7) {
    d3setlocalmx(p1, p2, p3, p4, p5, p6, p7, 1.0, 0.0, 0.0, 0.0, 1.0);
}
void d3setlocal_7(double p1, double p2, double p3, double p4, double p5, double p6) {
    d3setlocalmx(p1, p2, p3, p4, p5, p6, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
}
void d3setlocal_8(double p1, double p2, double p3, double p4, double p5) {
    d3setlocalmx(p1, p2, p3, p4, p5, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
}
void d3setlocal_9(double p1, double p2, double p3, double p4) {
    d3setlocalmx(p1, p2, p3, p4, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
}
void d3setlocal_10(double p1, double p2, double p3) {
    d3setlocalmx(p1, p2, p3, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
}
void d3setlocal_11(double p1, double p2) {
    d3setlocalmx(p1, p2, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
}
void d3setlocal_12(double p1) {
    d3setlocalmx(p1, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
}
void d3setlocal_13() {
    d3setlocalmx(0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
}
// d3trans 座標変換 macro (inx, iny, inz,  oux, ouy, ouz, ouf)
void d3trans(double inx, double iny, double inz) {
    dz = LGSm01 * inx + LGSm11 * iny + LGSm21 * inz + LGSmpy;
    df = 0.0;
    if (dz > 0.0) {
        dx = wincx + (LGSm00 * inx + LGSm10 * iny + LGSm20 * inz + LGSmpx) / dz;
        dy = wincy - (LGSm02 * inx + LGSm12 * iny + LGSm22 * inz + LGSmpz) / dz;
        if (dx / 8000 == 1.0 || dy / 8000 == 1.0) {
            df = 1.0;
        }
    }
}

void d3transTypeE(double inx, double iny, double inz) {
    ez = LGSm01 * inx + LGSm11 * iny + LGSm21 * inz + LGSmpy;
    af = 0.0;
    if (ez > 0.0) {
        ex = wincx + (LGSm00 * inx + LGSm10 * iny + LGSm20 * inz + LGSmpx) / ez;
        ey = wincy - (LGSm02 * inx + LGSm12 * iny + LGSm22 * inz + LGSmpz) / ez;
        if (ex / 8000 == 1.0 || ey / 8000 == 1.0) {
            af = 1.0;
        }
    }
}

// d3vpos 座標変換 (x, y, z) -> dx, dy, dz, df
void d3vpos(double v01, double v02, double v03) {
    // bkup last-data
    ex = dx;
    ey = dy;
    ef = df;
    d3trans(v01, v02, v03);
}

double d3getposX(double x, double y, double z) {
    d3vpos(x, y, z);
    if (df == 1.0) {
    } else {
    }
    return dx;
}

double d3getposY(double x, double y, double z) {
    d3vpos(x, y, z);
    if (df == 1.0) {
    } else {
    }
    return dy;
}

double d3getdx() {
    return dx;
}
double d3getdy() {
    return dy;
}
double d3getdz() {
    return dz;
}
double d3getex() {
    return ex;
}
double d3getey() {
    return ey;
}
double d3getez() {
    return ez;
}

