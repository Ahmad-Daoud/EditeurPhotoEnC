#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/menumain.h"
#include "../include/openImage.h"


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
    funChoixMenu(choixMenu);
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
void funChoixMenu(int choixMenu){
    if (choixMenu == 0){
        exit(EXIT_SUCCESS);
    }
    else if(choixMenu == 1){
        // Choisir une image
        loadImage();
    }
    else if(choixMenu == 2){
        // ajouter des filtres
    }
    else if(choixMenu == 3){
        /// Sauvegarder image
    }
    else {
        // Mauvais choix
        showMenuText(1);
    }
}