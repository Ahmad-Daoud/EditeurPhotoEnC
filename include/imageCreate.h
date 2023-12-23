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

imagePGM* createImagePGM(int height, int width);
imagePPM* createImagePPM(int height, int width);


#endif