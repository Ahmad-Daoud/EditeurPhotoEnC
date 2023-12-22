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

void showChoiceMenu(){
    printf("1 : Choisir une image");
    printf("2 : Ajouter des filtres à votre image");
    printf("3 : Sauvegarder votre image");
    printf("4 : Quitter l'application");
}