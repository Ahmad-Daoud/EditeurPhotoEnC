#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/menumain.h"
#include "../include/openImage.h"
#include "../include/imageRender.h"
#include "../include/imageFilters.h"
#include "../include/imageEffects.h"


int showMenuText(int errorCode){
    // Clear la console
    if (errorCode != -1){
        printf("\033[2J\033[1;1H");
    }
    int choixMenu;
    
    if (imageIsLoadedPGM == 1 || imageIsLoadedPPM == 1){
        
        if (errorCode == 0){
            printf("Que voulez vous faire avec l'image? \n");
        }
        else {
            printf("%s\n", errorCodeDisplay(errorCode));
        }
    }
    else {
        if (errorCode == 0){
            printf("Bonjour! Veuillez choisir une option : \n");
        }
        else {
            printf("%s\n", errorCodeDisplay(errorCode));
        }
    }
    showChoiceMenu();
    scanf("%d", &choixMenu);
    funChoixMenu(choixMenu);
    return 0;
}

char* errorCodeDisplay(int errorCode){
    char* response = NULL;
    if (errorCode == 1){
        response ="Veuillez choisir une option valide!";
    }
    else if (errorCode == 101){
        response = "L'image n'a pas pu être chargée correctement. Code d'erreur 101.";
    }
    else if (errorCode == 102){
        response = "L'image n'est pas du format attendu (utiliser des .ppm ou .pgm) Code d'erreur 102.";
    }
    else if (errorCode == 103){
        response = "Problème extension. Code d'erreur 103.";
    }
    else if (errorCode == 104){
        response = "Image introuvable. Code d'erreur 104";
    }
    else if (errorCode == 105){
        response = "Erreur dans le Header de votre image. Code d'erreur 105";
    }
    else if (errorCode == 106){
        response = "Erreur données de votre image. Code d'erreur 106";
    }
    else if (errorCode == 201){
        response = "Allocation mémoire échouée. Code d'erreur 201";
    }
    else if (errorCode == -1){
        response = "";
    }
    else {
        char codeString[20];
        sprintf(codeString, "%d", errorCode);
        response = (char *)malloc(strlen("Erreur inconnue, code d'erreur : ") + strlen(codeString) + 1);
        strcpy(response,"Erreur inconnue, code d'erreur : ");
        strcat(response, codeString);
    }
    errorCode = 0;
    return response;
}




void showChoiceMenu(){
    if(imageIsLoadedPGM == 1 || imageIsLoadedPPM == 1){

    }
    else {
        printf("1 : Choisir une image\n");
    }
    printf("2 : Ajouter des filtres à votre image\n");
    printf("3 : Ajouter des effets\n");
    printf("4 : Sauvegarder votre image\n");
    printf("0 : Quitter l'application\n");
}
void funChoixMenu(int choixMenu){
    
    if (choixMenu == 0){
        int errorCode;
        exit(EXIT_SUCCESS);
        
    }
    else if (imageIsLoadedPGM == 0 && imageIsLoadedPPM == 0){
        if(choixMenu == 1){
            // Choisir une image
            int ret = loadImage();
            if (ret == 0){
                // image chargée correctement
            }
            else {
                // affichage du menu avec code d'erreur
                showMenuText(ret);
            }
        }
    }
    if(choixMenu == 2){
        // ajouter des filtres
        
    }
    if(choixMenu == 3){
        // ajouter des effets
        effectChoose(0);
    }
    else if(choixMenu == 4){
        /// Sauvegarder image
        int errorCode = 0;
        printf("hello");
        scanf("%d", errorCode);
        saveImage(0);
    }
    else {
        // Mauvais choix
        showMenuText(1);
    }
}