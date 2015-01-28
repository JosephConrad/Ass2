#include <math.h>
#include "zad2.h"


float distance (float kx, float ky, float kz, float r, float x, float y) {
    float k = (kx-x)*(kx-x) + (ky-y)*(ky-y);
    return kz - sqrtf(r*r - k);
}


float ifCut (float kx, float ky, float r, float x, float y) {
    return (kx-x)*(kx-x) + (ky-y)*(ky-y) <= r*r;
}


void sztokfisz (Kula_t * kule, Pixel * obraz, int szer, int wys, int liczbaKul) {
    int x, y, i;
    int bestNo, globalCut, cut;
    float best, dist;

    for (y = 0; y < wys; y++) {
        for (x = 0; x < szer; x++) { 
            bestNo = 0;
            best = 1000000.0;
            globalCut = 0;
            for (i = 0; i < liczbaKul; i++) {
                cut = ifCut(kule[i].x, kule[i].y, kule[i].r, x, y);
                if (cut) {
                    globalCut = 1;
                    dist = distance(kule[i].x, kule[i].y, kule[i].z, kule[i].r, x, y); 
                    if (dist < best) {
                        best = dist;
                        bestNo = i;
                    }
                }
            }
            if (globalCut) {
                obraz[y + wys * x] = kule[bestNo].kolor;
            }
        }
    }
}