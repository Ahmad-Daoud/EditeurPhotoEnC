#include <stdlib.h>
#include <stdio.h>
#include "../include/imageEffects.h"
#include "../include/imageCreate.h"
#include "../include/menumain.h"

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
        pixelEffect();
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

void pixelEffect(){
    
}