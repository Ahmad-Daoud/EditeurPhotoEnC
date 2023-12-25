#ifndef IMAGECREATE_H
#define IMAGECREATE_H


typedef struct {
    int width;
    int height;
    int max_color_value;
    unsigned char *pixels;
} imagePPM;
typedef struct {
    char format[3];  // Format (P2=ASCII P5= Binaire)
    int width;       
    int height;      
    int max_gray;    
    unsigned char *pixels;
} imagePGM;


extern int imageIsLoadedPGM;
extern int imageIsLoadedPPM;
int createImagePGM(FILE* image);
imagePPM* createImagePPM(FILE* image);


#endif