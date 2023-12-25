#ifndef OPENIMAGE_H
#define OPENIMAGE_H
#include "imageCreate.h"

extern int isLoadedPGM;
extern int isLoadedPPM;
extern imagePPM* loadedImagePPM;
extern imagePGM* loadedImagePGM;

char* getFileExtension(char* imageName);
int loadImage();

#endif
