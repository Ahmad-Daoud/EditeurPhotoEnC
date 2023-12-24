#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/openImage.h"
#include "../include/imageCreate.h"


int isLoadedPGM = 0;
int isLoadedPPM = 0;
imagePGM* loadedImagePPM = NULL;
imagePPM* loadedImagePGM = NULL;






char* getFileExtension(char* imageName){
    const char *dot = strrchr(imageName, '.'); 
    if (!dot || dot == imageName || dot == imageName + 1) {
        // Pas d'extension ou l'image commence avec un .
        return "";
    }
    return (char*)(dot + 1);
    // On return le nom de l'image après le .
}

int loadImage(){
    char imageName[100];
    char imagePath[100];
    const char* directory = "input/";
    printf("Veuillez déposer votre image dans le dossier images (format .ppm ou .pgm) \n");
    printf(" nom de votre image : ");

    scanf("%s", &imageName);
    snprintf(imagePath, sizeof(imagePath), "%s%s", directory, imageName);
    char* extension = getFileExtension(imageName);
    if (strcmp(extension, "") == 0){
        // Pas d'extension ou le fichier commence avec un .
        return 103;
    }
    else {
        int errorCode = 0;
        // image chargée correctement
        if (strcmp(extension, "ppm") == 0 || strcmp(extension, "pgm") == 0){
            FILE *imageLoad = fopen(imagePath, "rb");
            if (imageLoad == NULL){
                perror("Error opening file");
                // image introuvable
                return 104;
            }
            else {
                // Image trouvée correctement
                if (strcmp(extension, "ppm") == 0){
                    int response = createImagePPM(imageLoad);
                    if (response == 0) {
                        // Image chargée correctement et convertie en struct

                    }
                    else {
                        // Erreur
                    }
                }
                else {
                    int response = createImagePGM(imageLoad);
                    if (response == 0) {
                        // Image chargée correctement et convertie en struct
                    }
                    else {
                        // Erreur
                    }
                }
                return 0;
            }
        }
        else {
            return 102;
        }
    }
    
}