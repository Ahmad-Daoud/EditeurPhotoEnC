#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* getFileExtension(char* imageName){
    const char *dot = strrchr(imageName, ".");
    if (!dot || dot == imageName){
        // Pas d'extension ou l'image commence avec un .
        return "";
    }
    return (char*)(dot + 1);
    // On return le nom de l'image après le .
}

int loadImage(){
    char imageName[100];
    printf("Veuillez déposer votre image dans le dossier images (format .ppm ou .pgm)");
    scanf("%s", imageName);
    char* extension = getFileExtension(imageName);
    if (strcmp(extension, "") == 0){
        // Pas d'extension ou le fichier 
        return 103;
    }
    else {
        // image chargée correctement
        if ( extension == "ppm" ||  extension == "pgm"){
            FILE *imageLoad = fopen(imageName, "rb");
            if (imageLoad == NULL){
                // image introuvable
                return 104;
            }
            else {
                // Image ouverte correctement
                return 0;
            }
        }
        else {
            return 102;
        }
    }
    
}



