#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int showMenuText(){
    int choixMenu;
    printf("Bonjour! Veuillez choisir une option : ");
    showMenu();
    scanf("%d", choixMenu);
    int imageLoaded = loadImage();
}

void showChoiceMenu(){
    printf("1 : Choisir une image");
    printf("2 : Ajouter des filtres à votre image");
    printf("3 : Sauvegarder votre image");
    printf("4 : Quitter l'application");
}