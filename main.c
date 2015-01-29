#include <stdio.h>
#include <stdlib.h>

//#include "zad2.c"
#include "zad2.h"

extern void sztokfisz (Kula_t * kule, Pixel * obraz, int szer, int wys, int liczbaKul);
  
int main ( int argc, char *argv[] ) {
    printf("\nSecond assignment - Assebler\n\n");

    if ( argc != 2 ) { 
        printf( "usage: %s filename", argv[0] );
        return 0;
    }
    
    FILE *file = fopen( argv[1], "r" );

    if ( file == 0 ) {
        printf( "Could not open file\n" );
        exit(EXIT_FAILURE);
    }

    int liczbaKul, szer, wys;
    int i;
    int r, g, b, x, y, z, radius;
    char name;
    int c1, c2, c3;

    fscanf(file, "%d", &wys); 
    fscanf(file, "%d", &szer); 
    fscanf(file, "%d", &liczbaKul);  

    Pixel * obraz;
    obraz = malloc(sizeof(Pixel) * (wys * szer)); 
    Kula_t * kule;
    kule = malloc(sizeof(Kula_t) * liczbaKul);

    for(i=0; i < liczbaKul; i++) {
        fscanf(file, "%d %d %d %c", &c1, &c2, &c3, &name);  
        fscanf(file, "%d %d %d", &x, &y, &z); 
        fscanf(file, "%d", &radius);

        Pixel p = { .red = r, .green = g, .blue = b, .nazwa = name};
        Kula_t kula = { .x = x, .y = y, .z = x, .r = radius , .kolor = p};
        kule[i] = kula;
    }

    Pixel bialy = { .red = 0.0, .green = 0.0, .blue = 0.0, .nazwa = '.'}; 
    // for(i=0; i < liczbaKul; i++)
    //     printf("%d %d %d\n", kule[i].x, kule[i].y, kule[i].z);

    for (y = 0; y < wys; y++) {
        for (x = 0; x < szer; x++) {
            obraz[y + wys * x] = bialy;
        }
    }
    sztokfisz(kule, obraz, szer, wys, liczbaKul);

    for (y = 0; y < wys; y++) {
        for (x = 0; x < szer; x++) {
            printf("%c ", obraz[y + wys * x].nazwa);
        }
        printf("\n");
    }
    return 0;
}