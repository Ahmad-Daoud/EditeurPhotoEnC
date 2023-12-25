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


extern int imageIsLoadedPGM;
extern int imageIsLoadedPPM;
int createImagePGM(FILE* image);
imagePPM* createImagePPM(FILE* image);


#endif