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
        printf("Veuillez choisir un effet parmis les effets suivants : \n");
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
            int newWidth = (loadedImagePGM->width + pixelStrength - 1) / pixelStrength; // nouvelle largeur
            int newHeight = (loadedImagePGM->height + pixelStrength - 1) / pixelStrength; // nouvelle hauteur
            unsigned char *newPixels = (unsigned char *)malloc(newWidth * newHeight * sizeof(unsigned char));
            for(int y = 0 ; y < newHeight; y++){
                for (int x = 0; x < newWidth; x++){
                    int total = 0;
                    for (int j = 0; j < pixelStrength && (y * pixelStrength + j) < loadedImagePGM->height; j++) {
                        for (int i = 0; i < pixelStrength && (x * pixelStrength + i) < loadedImagePGM->width; i++) {
                            int srcX = x * pixelStrength + i;
                            int srcY = y * pixelStrength + j;
                            if (srcX < loadedImagePGM->width && srcY < loadedImagePGM->height) {
                                total += loadedImagePGM->pixels[srcY * loadedImagePGM->width + srcX];
                                
                            }
                        }
                    }
                    int avg = total / (pixelStrength * pixelStrength);
                    for (int j = 0; j< pixelStrength; j++){
                        for (int i = 0; i<pixelStrength; i++){
                            int destX = x * pixelStrength +i ;
                            int destY = y * pixelStrength +j ;
                            if (destX < loadedImagePGM->width && destY < loadedImagePGM->height){
                                newPixels[destY * newWidth + destX] = avg;
                            }
                            
                        }
                    }
                }
                if (y == 13){
                    printf("We have sucessfully finished the pixelisation %d", newHeight);
                    scanf("%d",errorCode);
                }
            }
            printf("We have sucessfully finished the pixelisation");
            scanf("%d",errorCode);
            free(loadedImagePGM->pixels);
            loadedImagePGM->pixels = newPixels;
            loadedImagePGM->height = newHeight;
            loadedImagePGM->width = newWidth;
            
        }
        else {
            // L'image est une PPM

        }
    }
}