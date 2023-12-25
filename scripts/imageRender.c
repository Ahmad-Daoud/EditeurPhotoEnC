#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/imageRender.h"
#include "../include/imageCreate.h"
#include "../include/openImage.h"
#include "../include/menumain.h"

void saveImage(int errorCode){
    if (errorCode == 3){
        printf("Nom d'image existe déjà");
    }
    if(imageIsLoadedPGM == 1 || imageIsLoadedPPM == 1){
        if (imageIsLoadedPGM == 1 ){
            // Image de format PGM
            if (loadedImagePGM != NULL){
                // Image non NULL
                savePGM();
            }
            else {
                // Image NULL
            }
        }
        else {
            // Image de format PPM
            if (loadedImagePPM != NULL){
                // Image non NULL
                savePPM();
            }
            else {
                // L'image est NULL
                imageIsLoadedPPM = 0;
                free(loadedImagePPM);
                loadedImagePPM = NULL;
                showMenuText(101);
            }
        }
    }
    else {
        // Pas d'image à sauvegarder
        showMenuText(2);
    }
}

void savePPM(){  
    char outputName[100];
    char directory[] = "output/";
    char extension[] = ".ppm";
    printf("Veuillez choisir un nom pour l'image : ");
    scanf("%99s", outputName);
    int totalLength = strlen(directory) + strlen(outputName) + strlen(extension) + 1;
    char *fullOutput = (char *)malloc(totalLength * sizeof(char));
    if (fullOutput != NULL) {
        snprintf(fullOutput, totalLength, "%s%s%s", directory, outputName, extension);
        FILE *outputFile = fopen(fullOutput,"rb"); 
        if(outputFile != NULL){
            // l'image existe déjà
            free(fullOutput);
            fclose(outputFile);
            saveImage(1);
        }
        else {
            // On crée notre nouvelle image
            fclose(outputFile);
            outputFile = fopen(fullOutput, "wb");
            if (!outputFile){
                int errorCode = 0;
                printf("%s", fullOutput);
                scanf("%d",errorCode);
                free(fullOutput);
                showMenuText(202);
            }
            else{
                int errorCode = 0;

                fprintf(outputFile, "P6\n%d %d\n%d\n", loadedImagePPM->width, loadedImagePPM->height, loadedImagePPM->max_color_value);

                // Write pixel data
                fwrite(loadedImagePPM->pixels, sizeof(unsigned char), loadedImagePPM->width * loadedImagePPM->height * 3, outputFile);

                fclose(outputFile);


                printf("%s Sucessfully saved", fullOutput);
                scanf("%d",errorCode);
            }
        }
        // On libère la mémoire du malloc
        free(fullOutput);
    } 
    else {
        // allocation de mémoire échouée.
        free(fullOutput);
        showMenuText(201);
    }
}
void savePGM(){

}