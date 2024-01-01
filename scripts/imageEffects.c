#include <stdlib.h>
#include <stdio.h>
#include "../include/imageEffects.h"
#include "../include/imageCreate.h"
#include "../include/menumain.h"
#include "../include/openImage.h"

void effectChoose(int errorCode){
    if (imageIsLoadedPGM == 1 || imageIsLoadedPPM == 1){
        // Image chargée
        int effectChoice = 0 ;
        printf("\033[2J\033[1;1H");
        if (errorCode == 1){
            printf("Mauvais choix Menu! \n");
        }
        else if(errorCode == 5){
            printf("Effet en developpement ! \n");
        }
        else if(errorCode == -2){
            printf("pixélisation appliquée!\n");
        }
        else {
            printf("Veuillez choisir un effet parmis les effets suivants : \n");
        }
        showEffectMenu();
        scanf("%d", &effectChoice);
        effectMenuChoice(effectChoice);
    }
    else {
        // image non chargée
        showMenuText(4);
    }
}

void showEffectMenu(){
    printf("1 : Pixeliser. \n");
    printf("2 : Effet Négatif. \n");
    printf("3 : Niveau de gris\n");
    printf("4 : Distorsion \n");
    printf("0 : Quitter \n");
}
void effectMenuChoice(int Choice){
    if(Choice == 1){
        // Effet pixeliser
        pixelEffect(0);
    }
    else if (Choice == 2 ){
        // Effet négatif
        effectChoose(5);
    }
    else if (Choice == 3){
        // Niveau de gris
        effectChoose(5);
    }
    else if (Choice == 4){
        // Distorsion
        effectChoose(5);
    }
    else if (Choice == 0){
        // Quitter
        showMenuText(0);
    }
    else {
        effectChoose(1);
    }
}

void pixelEffect(int errorCode){
    if (errorCode == 1){
        printf("Veuillez choisir une intensite valide (1-10) : ");
    }
    else {
        printf("Choisir l'intensité de l'effet (1-10, entiers uniquement) : ");
    }
    int pixelStrength = 0;
    scanf("%d", &pixelStrength);
    
    if (pixelStrength < 1 || pixelStrength > 10){
        pixelEffect(1);
    }
    else {
        // La valeur choisie est bonne.
        if (imageIsLoadedPGM){
            // L'image est une PGM
            int blockSize = 2 * pixelStrength + 1;
            unsigned char* newPixels = (unsigned char *)malloc(loadedImagePGM->width * loadedImagePGM->height * sizeof(unsigned char) * 6);
            for (int row = (blockSize / 2); row < loadedImagePGM->height - (blockSize/2); ++row) {
                for (int col = blockSize / 2; col < loadedImagePGM->width - (blockSize/2); ++col) {
                    unsigned int avg = 0;
                    for (int i = -(blockSize / 2); i <= (blockSize / 2); ++i) {
                        for (int j = -(blockSize / 2); j <= (blockSize / 2); ++j) {
                            avg += loadedImagePGM->pixels[(row + i) * loadedImagePGM->width + (col + j)];
                        }
                    }
                    newPixels[row * loadedImagePGM->width + col] = avg / (blockSize * blockSize);
                }
            }
            for (int i = 0; i < loadedImagePGM->width * loadedImagePGM->height; ++i) {
                loadedImagePGM->pixels[i] = newPixels[i];
            }


            free(loadedImagePGM->pixels);
            loadedImagePGM->pixels = newPixels;
            effectChoose(-2);
        }
        else {
            // L'image est une PPM

        }
    }
}