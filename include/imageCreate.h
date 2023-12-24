#ifndef IMAGECREATE_H
#define IMAGECREATE_H


typedef struct {
    int width;
    int height;
    int max_color_value;
    unsigned char *pixels;
} imagePPM;
typedef struct {
    int width;
    int height;
    unsigned char* data;
} imagePGM;

extern imagePPM *ppm;
extern imagePGM *pgm;

int createImagePGM(FILE* image);
int createImagePPM(FILE* image);


#endif