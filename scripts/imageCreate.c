#include <stdio.h>
#include <stdlib.h>
#include "../include/imageCreate.h"

imagePPM *ppm = NULL;
imagePGM *pgm = NULL;

imageIsLoadedPGM = 0;
imageIsLoadedPPM = 0;

void allocatePixelsPPM(imagePPM *image){
    image->pixels = (unsigned char *)malloc(image->width * image->height * 3 * sizeof(unsigned char));
}

void freePixelsPPM(imagePPM *image) {
    free(image->pixels);
}


int createImagePGM(FILE* image) {
    int errorCode = 0;


    return 0;
}

int createImagePPM(FILE* image) {
    int errorCode = 0;
    if (image == NULL){
        return 101;
    }
    imagePPM *ppm = (imagePPM *)malloc(sizeof(imagePPM));
    if (ppm == NULL){
        // Allocation mémoire échouée
        free(ppm);
        return 201;
    }
    if (fscanf(image, "P6 %d %d %d", &ppm->width, &ppm->height, &ppm->max_color_value) != 3){
        // Erreur dans le header PPM
        free(ppm);
        return 105;
    }

    allocatePixelsPPM(ppm);
    if(fread(ppm->pixels,sizeof(unsigned char), ppm->width * ppm->height * 3, image) != ppm->width * ppm->height * 3){
        // Erreur lors de la lecture des données de pixels
        freePixelsPPM(ppm);
        free(ppm);
        return 106;
    }
    imageIsLoadedPPM = 1;
    return 0;
}