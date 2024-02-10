#ifndef IMAGECREATE_H
#define IMAGECREATE_H


typedef struct {
    int width;
    int height;
    unsigned char ** red;
    unsigned char ** green;
    unsigned char ** blue;
} imagePPM;
typedef struct {
    int width;
    int height;
    unsigned char** color;
    int vmax;
} imagePGM;


extern int imageIsLoadedPGM;
extern int imageIsLoadedPPM;
imagePGM* createImagePGM(FILE* image);
imagePPM* createImagePPM(FILE* image);


#endif