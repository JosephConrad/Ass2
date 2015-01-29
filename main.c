#include <stdio.h>
#include <stdlib.h>

//#include "zad2.c"
#include "zad2.h"

extern void sztokfisz (Kula_t * kule, Pixel * obraz, int szer, int wys, int liczbaKul);
  
int main ( int argc, char *argv[] ) {
    printf("\nSecond assignment - Assebler\n\n");

    if ( argc != 2 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s filename", argv[0] );
        return 0;
    }
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    // We assume argv[1] is a filename to open
    FILE *file = fopen( argv[1], "r" );

    /* fopen returns 0, the NULL pointer, on failure */
    if ( file == 0 )
    {
        printf( "Could not open file\n" );
        exit(EXIT_FAILURE);
    }


    while ((read = getline(&line, &len, file)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        char* ch = strtok(line, " ");
        while (ch != NULL) {
          printf("%s\n", ch);
          ch = strtok(NULL, " ");
        }
        printf("%s\n", line);
    }

    fclose(file);
    if (line)
        free(line);

    int wys = 20;
    int szer = 100;
    int liczbaKul = 3;

    Pixel p = { .red = 255.0, .green = 0.0, .blue = 0.0, .nazwa = '1'};
    Kula_t kula = { .x = 70.0, .y = 10.0, .z = 50.0, .r = 8.0, .kolor = p};

    Pixel p2 = { .red = 0.0, .green = 255.0, .blue = 0.0, .nazwa = '2'};
    Kula_t kula2 = { .x = 13.0, .y = 1.0, .z = 50.0, .r = 10.0  , .kolor = p2};
    
    Pixel p3 = { .red = 0.0, .green = 255.0, .blue = 0.0, .nazwa = '3'};
    Kula_t kula3 = { .x = 20.0, .y = 5.0, .z = 49.0, .r = 10.0 , .kolor = p3};



    Pixel bialy = { .red = 0.0, .green = 0.0, .blue = 0.0, .nazwa = '.'};

    Kula_t * kule;
    kule = malloc(sizeof(Kula_t) * liczbaKul);
    
    kule[0] = kula;
    kule[1] = kula2;
    kule[2] = kula3;

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

    for (y = 0; y < wys; y++) {
        for (x = 0; x < szer; x++) {
            printf("%c ", obraz[y + wys * x].nazwa);
        }
        printf("\n");
    }
    return 0;
}