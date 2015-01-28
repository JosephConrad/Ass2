#ifndef ZAD2_H
#define ZAD2_H
 
typedef struct {
     unsigned char red,green,blue;
     char nazwa;
} Pixel;

typedef struct {
	float x;
	float y;
	float z;
	float r;
	Pixel kolor;
} Kula_t;

#endif
