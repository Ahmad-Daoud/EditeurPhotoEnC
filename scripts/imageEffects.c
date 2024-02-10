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
    printf("1 : Rotate. \n");
    printf("2 : Mirroir. \n");
    printf("3 : Translation.\n");
    printf("4 : Scale \n");
}