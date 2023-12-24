#ifndef IMAGECREATE_H
#define IMAGECREATE_H


typedef struct {
    int width;
    int height;
    unsigned char* data;
} imagePPM;
typedef struct {
    int width;
    int height;
    unsigned char* data;
} imagePGM;

imagePGM* createImagePGM(FILE* image);
imagePPM* createImagePPM(FILE* image);


#endif