#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "math.h"
#include "../include/imageEffects.h"
#include "../include/imageCreate.h"
#include "../include/menumain.h"
#include "../include/openImage.h"

void showEffectMenu();
void chosenEffect(int choice);
void translationPGM();
void translationPPM();
void applyMirrorEffect();
void applyImageRotation(double angle);
void translationPGM(int dx, int dy);


void effectChoose(int errorCode){
    if (imageIsLoadedPGM == 1 || imageIsLoadedPPM){
        int effectChoice = 0;
        // Image chargée
        printf("Veuillez choisir un effet parmis les effets suivants : \n");
        showEffectMenu();
        scanf("%d", &effectChoice);
        chosenEffect(effectChoice);
    }
    else {
        // image non chargée
        showMenuText(4);
    }
}

void showEffectMenu(){
    printf("1 : Rotation. \n");
    printf("2 : Mirroir. \n");
    printf("3 : Translation.\n");
    printf("0 : Quitter \n");
}
void chosenEffect(int choice){
    if (choice == 1){
        // Rotation
        printf("Choose an angle");
        double angle;
        scanf("%lf", &angle);
        applyImageRotation(angle);
        showMenuText(-3);
    }
    else if (choice == 2)
    {
        // Mirroir
        applyMirrorEffect();
        showMenuText(-3);
    }
    else if (choice == 3)
    {
        int dx, dy;
        printf("Veuillez choisir une marge horizontale : ");
        scanf("%d",&dx);
        printf("Veuillez choisir une marge verticale : ");
        scanf("%d",&dy);
        translationPGM(dx, dy);
        showMenuText(-3);
    }
    else if (choice == 0)
    {
        // Quitter
    }
    else {
        // Erreur
    }
}



void applyMirrorEffect() {
    if (imageIsLoadedPGM == 1) {
        // PGM Image Mirror Effect
        // Calculate the middle column
        int middleColumn = loadedImagePGM->width / 2;

        for (int row = 0; row < loadedImagePGM->height; ++row) {
            for (int col = 0; col < middleColumn; ++col) {
                int leftIndex = row * loadedImagePGM->width + col;
                int rightIndex = row * loadedImagePGM->width + (loadedImagePGM->width - 1 - col);

                unsigned char temp = loadedImagePGM->pixels[leftIndex];
                loadedImagePGM->pixels[leftIndex] = loadedImagePGM->pixels[rightIndex];
                loadedImagePGM->pixels[rightIndex] = temp;
            }
        }
    }
    else{
        showMenuText(5);
    }
}



void applyImageRotation(double angle) {

    
    // Convert angle to radians
    double radians = angle * M_PI / 180.0;

    // Determine the type of image (PGM or PPM)

    // Set dimensions based on the type of image
    int width, height;
    width = loadedImagePGM->width;
    height = loadedImagePGM->height;



    // Create a temporary array with the same dimensions
    unsigned char* pixelData;
    pixelData = (unsigned char*)malloc(width * height * sizeof(unsigned char));

    // Iterate through each pixel in the destination image
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            // Convert coordinates to center-relative
            int centerX = width / 2;
            int centerY = height / 2;
            int relX = col - centerX;
            int relY = row - centerY;

            // Rotate coordinates
            int newX = round(relX * cos(radians) - relY * sin(radians));
            int newY = round(relX * sin(radians) + relY * cos(radians));

            // Convert back to absolute coordinates
            newX += centerX;
            newY += centerY;

            // Check if the new coordinates are within bounds
            if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
                // Copy pixel value from source to destination
                pixelData[newY * width + newX] = loadedImagePGM->pixels[row * width + col];
            }
        }
    }

    // Replace the original image with the rotated image
    free(loadedImagePGM);
    loadedImagePGM->pixels = pixelData;
    printf("PGM Image rotated by %f degrees.\n", angle);
}


void translationPGM(int dx, int dy) {
    if (imageIsLoadedPGM == 1) {
        int width = loadedImagePGM->width;
        int height = loadedImagePGM->height;
        // Allocation de mémoire
        unsigned char *newPixels = (unsigned char *)malloc(width * height * sizeof(unsigned char));

        if (newPixels == NULL) {
            // Allocation de mémoire échouée
            free(newPixels);
            showMenuText(201);
        }

        // translation
        for (int newY = 0; newY < height; newY++) {
            for (int newX = 0; newX < width; newX++) {
                int oldX = newX - dx;
                int oldY = newY - dy;

                if (oldX >= 0 && oldX < width && oldY >= 0 && oldY < height) {
                    newPixels[newY * width + newX] = loadedImagePGM->pixels[oldY * width + oldX];
                } else {
                    // Set new pixel to some default value, for example, 0 or 255
                    newPixels[newY * width + newX] = 255; // White pixel
                }
            }
        }


        // Free memory of the original image pixels
        free(loadedImagePGM->pixels);

        loadedImagePGM->pixels = newPixels;
    } else {
        printf("LULva2");
        // Pas de PGM
        showMenuText(5);
    }
}
