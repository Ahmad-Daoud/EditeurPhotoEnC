#include <stdio.h>
#include <stdlib.h>
#include "../include/imageCreate.h"



int imageIsLoadedPGM = 0;
int imageIsLoadedPPM = 0;




imagePGM* createImagePGM(FILE* image) {
    int errorCode = 0;
    if (image == NULL){
        return NULL;
    }
    imagePGM* ImagePGM = (imagePGM*)malloc(sizeof(imagePGM));
    if (ImagePGM == NULL){
        // Allocation mémoire échouée
        free(ImagePGM);
        return NULL;
    }

    // Lecture données HEADER Pgm
    fscanf(image, "%2s", ImagePGM->format);
    fscanf(image, "%d %d", &ImagePGM->width, &ImagePGM->height);
    fscanf(image, "%d", &ImagePGM->max_gray);

    // Allocation mémoire pour données pixels
    ImagePGM->pixels = (unsigned char*)malloc(ImagePGM->width * ImagePGM->height * sizeof(unsigned char));
    if (ImagePGM->pixels == NULL) {
        // Allocation mémoire échouée
        free(ImagePGM);
        showMenuText(201);
        return NULL;
    }
    // Lecture données pixels
    fread(ImagePGM->pixels, sizeof(unsigned char), ImagePGM->width * ImagePGM->height, image);

    imageIsLoadedPGM = 1;
    return ImagePGM;
}

imagePPM* createImagePPM(FILE* image) {
    int errorCode = 0;
    if (image == NULL){
        return NULL;
    }
    imagePPM* Imageppm = (imagePPM*)malloc(sizeof(imagePPM));
    if (Imageppm == NULL){
        // Allocation mémoire échouée
        free(Imageppm);
        showMenuText(201);
        return NULL;
    }
    if (fscanf(image, "P6 %d %d %d", &Imageppm->width, &Imageppm->height, &Imageppm->max_color_value) != 3){
        // Erreur dans le header PPM
        free(Imageppm);
        showMenuText(105);
        return NULL;
    }
    // On malloc pour les données des pixels.
    Imageppm->pixels = (unsigned char*)malloc(Imageppm->width * Imageppm->height * 3 * sizeof(unsigned char));
    if (Imageppm->pixels == NULL) {        
        // Erreur lors de la lecture des données de pixels
        free(Imageppm);
        showMenuText(106);
        return NULL;
    }

    if (fread(Imageppm->pixels, sizeof(unsigned char), Imageppm->width * Imageppm->height * 3, image) != Imageppm->width * Imageppm->height * 3) {
        // Les données de pixels sont corrompues
        free(Imageppm->pixels);
        free(Imageppm);
        showMenuText(107);
        return NULL;
    }

    imageIsLoadedPPM = 1;
    return Imageppm;
}