#include <stdio.h>
#include <stdlib.h>
#include "../include/imageCreate.h"



imageIsLoadedPGM = 0;
imageIsLoadedPPM = 0;




int createImagePGM(FILE* image) {
    int errorCode = 0;


    return 0;
}

imagePPM* createImagePPM(FILE* image) {
    int errorCode = 0;
    if (image == NULL){
        showMenuText(101);
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