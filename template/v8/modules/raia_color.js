

export class Color {
    constructor() {
        this.r = 0.0;
        this.g = 0.0;
        this.b = 0.0;
        this.a = 1.0;
    }
    initRGBA(r, g, b, a = 255) {
        return {
            r: r,
            g: g,
            b: b,
            a: a
        };
    }
    /**
     * 
     * @param {int} r - (int) 0 ~ 255
     * @param {int} g - (int) 0 ~ 255
     * @param {int} b - (int) 0 ~ 255
     * @param {int} a - (int) 0 ~ 255. default = 255
     * @returns {{r:real, g:real, b:real, a:real}}
     */
    intToReal(r, g, b, a = 255) {
        return {
            r: r / 255.0,
            g: g / 255.0, 
            b: b / 255.0,
            a: a / 255.0
        };
    }
    /**
     * 
     * @param {real} r - (real) 0.0 ~ 1.0
     * @param {real} g - (real) 0.0 ~ 1.0
     * @param {real} b - (real) 0.0 ~ 1.0
     * @param {real} a - (real) 0.0 ~ 1.0. default = 1.0
     * @returns {{r:int, g:int, b:int, a:int}}
     */
    realToInt(r, g, b, a = 1.0) {
        return {
            r: Math.round(r * 255),
            g: Math.round(g * 255),
            b: Math.round(b * 255),
            a: Math.round(a * 255)
        };
    }
    /**
     * 
     * @param {real} r - (real) 0.0 ~ 1.0
     * @param {real} g - (real) 0.0 ~ 1.0
     * @param {real} b - (real) 0.0 ~ 1.0
     * @returns {{h:real, s:real, v:real}}
     */
    rgbToHsv(r, g, b) {
        let max = Math.max(r, g, b), min = Math.min(r, g, b);
        let h, s, v = max;
      
        let d = max - min;
        s = max === 0 ? 0 : d / max;
      
        if (max === min) {
            h = 0; // ちょうど灰色
        } else {
            switch (max) {
                case r: h = (g - b) / d + (g < b ? 6 : 0); break;
                case g: h = (b - r) / d + 2; break;
                case b: h = (r - g) / d + 4; break;
            }
            h /= 6;
        }
        return {h:h, s:s, v:v};
    }
    /**
     * 
     * @param {real} h - (real) 0.0 ~ 1.0
     * @param {real} s - (real) 0.0 ~ 1.0
     * @param {real} v - (real) 0.0 ~ 1.0
     * @returns {{r:real, g:real, b:real}}
     */
    hsvToRgb(h, s, v) {
        let r, g, b;
        let i = Math.floor(h * 6);
        let f = h * 6 - i;
        let p = v * (1 - s);
        let q = v * (1 - f * s);
        let t = v * (1 - (1 - f) * s);
        switch (i % 6) {
            case 0: r = v, g = t, b = p; break;
            case 1: r = q, g = v, b = p; break;
            case 2: r = p, g = v, b = t; break;
            case 3: r = p, g = q, b = v; break;
            case 4: r = t, g = p, b = v; break;
            case 5: r = v, g = p, b = q; break;
        }
        return {r:r, g:g, b:b};
    }
}