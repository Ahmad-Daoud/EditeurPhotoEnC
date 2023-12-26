#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/openImage.h"
#include "../include/imageCreate.h"
#include "../include/menumain.h"


imagePPM* loadedImagePPM = NULL;
imagePGM* loadedImagePGM = NULL;

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
    printf("Veuillez déposer votre image dans le dossier input (format .ppm ou .pgm) \n");
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
                    // Image = PPM
                    loadedImagePPM = createImagePPM(imageLoad);
                    if (loadedImagePPM != NULL) {
                        // Image chargée correctement et convertie en struct
                        fclose(imageLoad);
                        showMenuText(0);
                    }
                    else {
                        // Erreur
                        imageIsLoadedPPM = 0;
                        free(loadedImagePPM);
                        fclose(imageLoad);
                        loadedImagePPM = NULL;
                        showMenuText(203);
                    }
                }
                else {
                    // Image = PGM
                    loadedImagePGM = createImagePGM(imageLoad);
                    if (loadedImagePGM != NULL) {
                        // Image chargée correctement et convertie en struct
                            fclose(imageLoad);
                            showMenuText(0);
                    }
                    else {
                        // Erreur
                        free(loadedImagePGM);
                        loadedImagePGM = NULL;
                        fclose(imageLoad);
                        imageIsLoadedPGM = 0;
                        showMenuText(203);
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