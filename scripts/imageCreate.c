#include <stdio.h>
#include <stdlib.h>
#include "../include/imageCreate.h"
#include "../include/menumain.h"



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
        showMenuText(201);
        return NULL;
    }
    char chaine [3];
    int verif = fscanf(image,"%s", chaine);
    if (chaine[1] == '5') // Egal au format p5
    {
        fscanf(image, "%d %d", &ImagePGM->width, &ImagePGM->height);
        fscanf(image, "%d", &ImagePGM->vmax);
        ImagePGM->color=malloc(ImagePGM->height * sizeof(unsigned char*));
        
        if(ImagePGM->color == NULL){
            return NULL;
            // Allocation mémoire échouée.
        }
        int i;
        int j;
        for (i = 0; i < ImagePGM->height; i++) {
            ImagePGM->color[i]= malloc(ImagePGM->width * sizeof(unsigned char));
            if(ImagePGM->color[i] == NULL) printf("ERROR %d",i);
        }
        for (j = 0; j < ImagePGM->height; j++) {
            for (i = 0; i < ImagePGM->width; i++) {
                unsigned char tmp;
                fread(&tmp, sizeof(unsigned char), 1, image);
                ImagePGM->color[j][i] = tmp; 
            }
        }
    }
    else
        {
        printf("format inconnu\n");
        showMenuText("102");
        return NULL;
    }
    imageIsLoadedPGM = 1;
    return ImagePGM;
}

imagePPM* createImagePPM(FILE* image) {
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

    char magicNumber[3];
    if (fscanf(image, "%2s", magicNumber) != 1 || magicNumber[0] != 'P' || magicNumber[1] != '6') {
        // Format inconnu
        free(Imageppm);
        showMenuText(102);
        return NULL;
    }

    // On scan la taille de l'image
     if (fscanf(image, "%d %d", &Imageppm->width, &Imageppm->height) != 2) {
        free(Imageppm);
        showMenuText(108);
        return NULL;
    }

    // Allocation de mémoire pour les channels de couleur
    Imageppm->red = (unsigned char**)malloc(Imageppm->height * sizeof(unsigned char*));
    Imageppm->green = (unsigned char**)malloc(Imageppm->height * sizeof(unsigned char*));
    Imageppm->blue = (unsigned char**)malloc(Imageppm->height * sizeof(unsigned char*));


    if (Imageppm->red == NULL || Imageppm->green == NULL || Imageppm->blue == NULL) {
        // Allocation de mémoire échouée
        free(Imageppm->red);
        free(Imageppm->green);
        free(Imageppm->blue);
        free(Imageppm);
        showMenuText(201);
        return NULL;
    }




    // Allocation de mémoire pour chaque ligne de pixels
    for (int i = 0; i < Imageppm->height; i++) {
        Imageppm->red[i] = (unsigned char*)malloc(Imageppm->width * sizeof(unsigned char));
        Imageppm->green[i] = (unsigned char*)malloc(Imageppm->width * sizeof(unsigned char));
        Imageppm->blue[i] = (unsigned char*)malloc(Imageppm->width * sizeof(unsigned char));

        if (Imageppm->red[i] == NULL || Imageppm->green[i] == NULL || Imageppm->blue[i] == NULL) {
            // Allocation de mémoire échouée
            for (int j = 0; j < i; j++) {
                free(Imageppm->red[j]);
                free(Imageppm->green[j]);
                free(Imageppm->blue[j]);
            }
            free(Imageppm->red);
            free(Imageppm->green);
            free(Imageppm->blue);
            free(Imageppm);
            showMenuText(201);
            return NULL;
        }
    }
    // Lécture des données pixels
    for (int i = 0; i < Imageppm->height; i++) {
        for (int j = 0; j < Imageppm->width; j++) {
            // Lecture des valeurs rgb
            fread(&Imageppm->red[i][j], sizeof(unsigned char), 1, image);
            fread(&Imageppm->green[i][j], sizeof(unsigned char), 1, image);
            fread(&Imageppm->blue[i][j], sizeof(unsigned char), 1, image);
        }
    }
    imageIsLoadedPPM = 1;
    return Imageppm;
}