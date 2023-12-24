#ifndef OPENIMAGE_H
#define OPENIMAGE_H
#include "imageCreate.h"

extern int isLoadedPGM;
extern int isLoadedPPM;
extern imagePGM* loadedImagePPM;
extern imagePPM* loadedImagePGM;

char* getFileExtension(char* imageName);
int loadImage();

#endif
