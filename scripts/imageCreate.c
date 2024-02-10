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

    char chaine [3];
    int verif = fscanf(image,"%s", chaine);

    if (chaine[1] == '5') // Egal au format p5
        {
            fscanf(image, "%d %d", ImagePGM->width, ImagePGM->height);
            fscanf(image, "%d", ImagePGM->vmax);
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

            for (i=0; i < ImagePGM->width; i++ ){
                for (j=0; j<ImagePGM->height; j++){
                    unsigned char tmp;
                    fread(&tmp, sizeof(unsigned char), 1, image);
                    ImagePGM->color[i][j] = tmp;
                }
            }
    }
    else
        {
        printf(" format inconnu\n");
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