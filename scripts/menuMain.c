#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/menuMain.h"


int showMenuText(int errorCode){
    // Clear la console
    int choixMenu;
    
    if (errorCode == 0){
        printf("Bonjour! Veuillez choisir une option : \n");
    }
    else {
        printf("%s\n", errorCodeDisplay(errorCode));
    }
    showChoiceMenu();
    scanf("%d", &choixMenu);
    int imageLoaded = 1; //loadImage(); 
    if (imageLoaded == 1){
        // L'image est chargée correctement
    }
    else {
        // L'image n'est pas chargée
        errorCode = 101; 
        
        showMenuText(errorCode); 
    }
    return 0;
}

char* errorCodeDisplay(int errorCode){
    char* response = NULL;
    if (errorCode == 101){
        response = "L'image n'a pas pu être chargée correctement";
    }
    else if (errorCode == 102){
        response = "L'image n'est pas du format attendu (utiliser des .ppm ou .pgm)";
    }
    return response;
}
void showChoiceMenu(){
    printf("1 : Choisir une image\n");
    printf("2 : Ajouter des filtres à votre image\n");
    printf("3 : Sauvegarder votre image\n");
    printf("0 : Quitter l'application\n");
}
