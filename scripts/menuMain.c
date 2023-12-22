#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int showMenuText(int errorCode){
    // Clear la console
    int choixMenu;
    printf("Bonjour! Veuillez choisir une option : ");
    showMenu();
    scanf("%d", choixMenu);
    int imageLoaded = loadImage();
    if (imageLoaded == 1){
        // L'image est chargée correctement
        
    }
    else {
        // L'image n'est pas chargée
        int errorCode = 101;
        showMenuText(errorCode);
    }
}

char* errorCodeDisplay(int errorCode){
    char* response = NULL ;
    if (errorCode == 101){
        // Image not loaded
        response = "L'image n'as pas pu être chargée correctement" ;
    }
    else if (errorCode == 102){
        // File is of wrong format
        response = "L'image n'est pas du format attendu (utiliser des .ppm ou .pgm)";
    }
    return response;
}


void showChoiceMenu(){
    printf("1 : Choisir une image");
    printf("2 : Ajouter des filtres à votre image");
    printf("3 : Sauvegarder votre image");
    printf("4 : Quitter l'application");
}