#include <stdlib.h>
#include <stdio.h>
#include "../include/imageEffects.h"
#include "../include/imageCreate.h"
#include "../include/menumain.h"
#include "../include/openImage.h"



void effectChoose(int errorCode){
    if (imageIsLoadedPGM == 1 || imageIsLoadedPPM){
        int effectChoice = 0;
        // Image chargée
        printf("Veuillez choisir un effet parmis les effets suivants : \n");
        showEffectMenu();
        scanf("%d", &effectChoice);
        chosenEffect(effectChoice);
    }
    else {
        // image non chargée
        showMenuText(4);
    }
}

void showEffectMenu(){
    printf("1 : Rotation. \n");
    printf("2 : Mirroir. \n");
    printf("3 : Translation.\n");
    printf("4 : Scale \n");
    printf("0 : Quitter \n");
}
void chosenEffect(int choice){
    if (choice == 1){
        // Rotation
    }
    else if (choice == 2)
    {
        // Mirroir
    }
    else if (choice == 3)
    {
        // Translation
        if (imageIsLoadedPGM == 1){
            translationPGM();
        }
        else if(imageIsLoadedPPM == 1){
            translationPPM();
        }
        else{
            showMenuText(104);
        }
    }
    else if (choice == 4)
    {
        // Scale
    }
    else if (choice == 0)
    {
        // Quitter
    }
    else {
        // Erreur
    }
}
void translationPPM(){

}
void translationPGM(){
    int decal = 100;
    
    imagePGM tr;
    tr.width = loadedImagePGM->width;
    tr.height = loadedImagePGM->height;
    tr.vmax = loadedImagePGM->vmax;
    tr.color=malloc(tr.height * sizeof(unsigned char*));
    
    int ii, i,j;
     for (ii = 0; ii < tr.height; ii++) {
        tr.color[ii]= malloc(tr.width * sizeof(unsigned char));
    }
     for(i=0;i< loadedImagePGM->width;i++)
    {
        for(j=0;j<loadedImagePGM->height;j++)
        {
            tr.color[j][i] = loadedImagePGM->color[j][i];
            if(i+3 <loadedImagePGM->width)
            {
                tr.color[j][i+decal] = loadedImagePGM->color[j][i];
            }
            else
            {
                tr.color[j][i+decal-loadedImagePGM->width] = loadedImagePGM->color[j][i];
            }
        }
    }
    // Sucess
    loadedImagePGM->color = tr.color;
    showMenuText(0);
}