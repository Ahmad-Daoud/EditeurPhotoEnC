#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/imageRender.h"
#include "../include/imageCreate.h"
#include "../include/openImage.h"
#include "../include/menumain.h"

void saveImage(int errorCode){
    int sf;
    printf("lolol");
    scanf("%d", &sf);
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
                imageIsLoadedPGM = 0;
                imageIsLoadedPPM = 0;
                showMenuText(101);
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
                free(fullOutput);
                showMenuText(202);
            }
            else{
                int totalPixels = loadedImagePPM->width * loadedImagePPM->height;
                unsigned char* pixelData = (unsigned char*)malloc((totalPixels * 3 + 1) * sizeof(unsigned char));
                if (pixelData == NULL) {
                    // Allocation mémoire échouée
                    free(fullOutput);
                    free(loadedImagePPM);
                    free(pixelData);
                    loadedImagePPM = NULL;
                    imageIsLoadedPPM = 0;
                    showMenuText(201);
                    return NULL;
                }

                // Ecriture editeur header ppm
                fprintf(outputFile, "P6\n%d %d\n%d\n", loadedImagePPM->width, loadedImagePPM->height, 255);
                // Ecriture données pixel
                int pixelIndex = 0;
                for (int i = 0; i < loadedImagePPM->height; i++) {
                    for (int j = 0; j < loadedImagePPM->width; j++) {
                        pixelData[pixelIndex++] = loadedImagePPM->red[i][j];
                        pixelData[pixelIndex++] = loadedImagePPM->green[i][j];
                        pixelData[pixelIndex++] = loadedImagePPM->blue[i][j];
                    }
                }
                // Ecriture des données pixel
                fwrite(pixelData, sizeof(unsigned char), totalPixels * 3, outputFile);

                fclose(outputFile);
                printf("\033[2J\033[1;1H");
                printf("Sauvegardé : %s \n ", fullOutput);
                // On libère la mémoire du malloc
                free(fullOutput);
                free(loadedImagePPM);
                loadedImagePPM = NULL;
                imageIsLoadedPPM = 0;
                showMenuText(-1);
            }
        }
    } 
    else {
        // allocation de mémoire échouée.
        free(fullOutput);
        showMenuText(201);
    }
}
void savePGM(){
    char outputName[100];
    char directory[] = "output/";
    char extension[] = ".pgm";
    printf("Veuillez choisir un nom pour l'image : ");
    scanf("%99s", &outputName);
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
            for (int i = 0; i < loadedImagePGM->height; i++) {
                for (int j = 0; j < loadedImagePGM->width; j++) {
                    printf("%3d ", loadedImagePGM->color[i][j]); // Assuming you want to print each value as an integer
                }
                printf("\n");
            }
            outputFile = fopen(fullOutput, "wb");
            if (!outputFile){
                free(fullOutput);
                showMenuText(202);
            }
            else{
                fprintf(outputFile, "P5\n");
                fprintf(outputFile, "%d %d\n255\n", loadedImagePGM->width, loadedImagePGM->height);
                unsigned char tmp = 0;
                int i = 0;
                int j = 0;
                for (j=0; j < loadedImagePGM->width; j++ ){
                    for (i=0; i<loadedImagePGM->height; i++){
                        tmp = (unsigned char) (loadedImagePGM->color[i][j]);
                        fwrite(&tmp, sizeof(unsigned char), 1, outputFile);
                    }
                    showMenuText(-1);
                }
            }
        }
    }
    else {
        // allocation de mémoire échouée.
        free(fullOutput);
        showMenuText(201);
    }
}