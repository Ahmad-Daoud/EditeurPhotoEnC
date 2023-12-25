#ifndef OPENIMAGE_H
#define OPENIMAGE_H
#include "imageCreate.h"


extern imagePPM* loadedImagePPM;
extern imagePGM* loadedImagePGM;

char* getFileExtension(char* imageName);
int loadImage();

#endif
