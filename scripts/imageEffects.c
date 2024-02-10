#include <stdlib.h>
#include <stdio.h>
#include "../include/imageEffects.h"
#include "../include/imageCreate.h"
#include "../include/menumain.h"

void effectChoose(int errorCode){
    if (imageIsLoadedPGM == 1 || imageIsLoadedPPM){
        // Image chargée
        printf("Veuillez choisir un effet parmis les effets suivants : \n");
        showEffectMenu();
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
}