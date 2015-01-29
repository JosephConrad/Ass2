#include <stdio.h>
#include <stdlib.h>

//#include "zad2.c"
#include "zad2.h"

extern void sztokfisz (Kula_t * kule, Pixel * obraz, int szer, int wys, int liczbaKul);
  
int main() {
    printf("\nSecond assignment - Assebler\n\n");

    int wys = 20;
    int szer = 100;
    int liczbaKul = 2;

    Pixel p = { .red = 255, .green = 0, .blue = 0, .nazwa = 'r'};
    Kula_t kula = { .x = 6, .y = 3, .z = 13, .r = 3, .kolor = p};

    Pixel p2 = { .red = 0, .green = 255, .blue = 0, .nazwa = 'g'};
    Kula_t kula2 = { .x = 13, .y = 10, .z = 10, .r = 7, .kolor = p2};


    Pixel bialy = { .red = 0, .green = 0, .blue = 0, .nazwa = '.'};

    Kula_t * kule;
    kule = malloc(sizeof(Kula_t) * liczbaKul);
    
    kule[0] = kula;
    kule[1] = kula2;

    Pixel * obraz;
    obraz = malloc(sizeof(Pixel) * (wys * szer)); 

    int x;
    int y;
    for (y = 0; y < wys; y++) {
        for (x = 0; x < szer; x++) {
            obraz[y + wys * x] = bialy;
        }
    }
    sztokfisz(kule, obraz, szer, wys, liczbaKul);
    // for (y = 0; y < wys; y++) {
        
    //  for (x = 0; x < szer; x++) {
    //      printf("%d \t", y + wys * x);

    //  }
    //  printf("\n");
    // }
    for (y = 0; y < wys; y++) {
        for (x = 0; x < szer; x++) {
            printf("%c ", obraz[y + wys * x].nazwa);
        }
        printf("\n");
    }
    return 0;
}