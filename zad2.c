#include <math.h>
#include "zad2.h"


float ifCut (float kx, float ky, float r, float x, float y);
float distance (float kx, float ky, float kz, float r, float x, float y);


void sztokfisz (Kula_t * kule, Pixel * obraz, int szer, int wys, int liczbaKul) {
    int x, y, i;
    int bestNo, globalCut, cut;
    float best, dist;

    for (y = 0; y < wys; y++) {
        for (x = 0; x < szer; x++) { 
            bestNo = 0;
            best = 1000000.0;
            globalCut = 1;
            if (globalCut) {
                obraz[0] = kule[bestNo].kolor;
            }
        }
    }
}

float distance (float kx, float ky, float kz, float r, float x, float y) {
    float k = (kx-x)*(kx-x) + (ky-y)*(ky-y);
    return kz - sqrtf(r*r - k);
}


float ifCut (float kx, float ky, float r, float x, float y) {
    return (kx-x)*(kx-x) + (ky-y)*(ky-y) <= r*r;
}
