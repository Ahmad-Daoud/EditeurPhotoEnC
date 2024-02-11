#include <stdlib.h>
#include <stdio.h>
#include "../include/imageEffects.h"
#include "../include/imageCreate.h"
#include "../include/menumain.h"

void filterChoice(int errorCode){
    if (imageIsLoadedPGM == 1 || imageIsLoadedPPM){
        // Image chargée
        printf("Veuillez choisir un filtre parmis les filtres suivants : \n");
        showFilterMenu();
    }
    else {
        // image non chargée
        showMenuText(4);
    }


    return NULL;
}
void showFilterMenu(){
    printf("1 : Seuillage. \n");
    printf("2 : Blur. \n");
    printf("3 : Pixelisation.\n");
    printf("4 :  \n");
}