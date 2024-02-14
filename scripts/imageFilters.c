#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "math.h"
#include "../include/imageEffects.h"
#include "../include/imageCreate.h"
#include "../include/menumain.h"
#include "../include/openImage.h"

void showFilterMenu();
void applyNegativeEffect();
void chosenFilter(int choice);
void applyBlurEffect(int level);
void pixeliseImage(int blockSize);
void applySobelEffect();
void seuillageImage(int niv);


void filterChoice(int errorCode){
    if (imageIsLoadedPGM == 1 || imageIsLoadedPPM == 1){
        // Image chargée
        if(errorCode == 1){
            printf("Veuillez choisir une option valide! \n");
        }
        else {
           printf("Veuillez choisir un filtre parmis les filtres suivants : \n");
        }
        showFilterMenu();
        int choice;
        scanf("%d", &choice);
        chosenFilter(choice);
    }
    else {
        // image non chargée
        showMenuText(4);
    }
}
void showFilterMenu(){
    printf("1 : Seuillage. \n");
    printf("2 : Blur. \n");
    printf("3 : Pixelisation.\n");
    printf("4 : Effet négatif.\n");
    printf("5 : Effet Sobel.\n");
    printf("0 : Quitter\n ");
}
void chosenFilter(int choice){
    if (choice == 1){
        int niv;
        printf("Choisir un niveau de seuillage : ");
        scanf("%d", &niv);
        seuillageImage(niv);
        showMenuText(-2);
    }
    else if (choice == 2) {
        printf("Choisir un niveau de blur : ");
        int blurChoice;
        scanf("%d", &blurChoice);
        applyBlurEffect(blurChoice);
        showMenuText(-2);
    }
    else if (choice == 3) {
        int pixChoice;
        printf("Veuillez choisir un niveau de pixelisation : ");
        scanf("%d",&pixChoice);
        pixeliseImage(pixChoice);
        showMenuText(-2);
    }
    else if (choice == 4) {
        applyNegativeEffect();
        showMenuText(-2);
    }
    else if (choice == 5){
        applySobelEffect();
        showMenuText(-2);
    }
    else if (choice == 0){
        showMenuText(0);
    }
    else {
        filterChoice(1);
    }
}


void applyNegativeEffect() {
    if (imageIsLoadedPGM == 1) {
        // For PGM images
        int imageWidth = loadedImagePGM->width;
        int imageHeight = loadedImagePGM->height;
        unsigned char* imageData = loadedImagePGM->pixels;
        // Create a temporary array to store the negative result
        imageData = (unsigned char*)malloc(imageWidth * imageHeight * sizeof(unsigned char));
        if (imageData == NULL){
            // allocation mémoire échouée.
            free(imageData);
            showMenuText(201);
        }
        // Apply the negative effect
        for (int i = 0; i < imageWidth * imageHeight; ++i) {
            imageData[i] = 255 - loadedImagePGM->pixels[i];
        }
        // Replace the original PGM image with the negative image
        free(loadedImagePGM->pixels);
        loadedImagePGM->pixels = imageData;

        printf("Effect applied: Negative (PGM)\n");

    } else if (imageIsLoadedPPM == 1) {
        // For PPM images
        showMenuText(5);
    }
}
void applyBlurEffect(int level){
        if (imageIsLoadedPGM == 1) {
        unsigned char* pixelData;
        int kernelSize = 2 * level + 1;
        int halfKernelSize = kernelSize / 2;
        pixelData = (unsigned char*)malloc(loadedImagePGM->width * loadedImagePGM->height * sizeof(unsigned char));
        for (int row = halfKernelSize; row < loadedImagePGM->height - halfKernelSize; ++row) {
            for (int col = halfKernelSize; col < loadedImagePGM->width - halfKernelSize; ++col) {
                unsigned int sum = 0;
                for (int i = -halfKernelSize; i <= halfKernelSize; ++i) {
                    for (int j = -halfKernelSize; j <= halfKernelSize; ++j) {
                        sum += loadedImagePGM->pixels[(row + i) * loadedImagePGM->width + (col + j)];
                    }
                }
                pixelData[row * loadedImagePGM->width + col] = sum / (kernelSize * kernelSize);
            }
        }
        for (int i = 0; i < loadedImagePGM->width * loadedImagePGM->height; ++i) {
            loadedImagePGM->pixels[i] = pixelData[i];
        }
        free(pixelData);
    }
    else {
        showMenuText(1);
    }
}


void pixeliseImage(int blockSize){
     if (imageIsLoadedPGM == 1) {
        // For PGM images
        int imageWidth = loadedImagePGM->width;
        int imageHeight = loadedImagePGM->height;
        unsigned char* pixelatedImage = loadedImagePGM->pixels;

        // Calculate the number of blocks in each dimension
        int blocksX = (int)ceil((double)imageWidth / blockSize);
        int blocksY = (int)ceil((double)imageHeight / blockSize);

        // Create a temporary array to store the pixelated result
        pixelatedImage = (unsigned char*)malloc(imageHeight * imageWidth * sizeof(unsigned char));

        // Apply the pixelation effect
        for (int blockX = 0; blockX < blocksX; ++blockX) {
            for (int blockY = 0; blockY < blocksY; ++blockY) {
                // Calculate the bounds of the current block
                int startX = blockX * blockSize;
                int startY = blockY * blockSize;
                int endX = fmin(startX + blockSize, imageWidth);
                int endY = fmin(startY + blockSize, imageHeight);

                // Calculate the average color of the current block
                int avgIntensity = 0;
                int pixelCount = 0;

                for (int x = startX; x < endX; ++x) {
                    for (int y = startY; y < endY; ++y) {
                        int index = y * imageWidth + x;
                        avgIntensity += loadedImagePGM->pixels[index];
                        pixelCount++;
                    }
                }

                avgIntensity /= pixelCount;

                // Fill the current block with the average intensity
                for (int x = startX; x < endX; ++x) {
                    for (int y = startY; y < endY; ++y) {
                        int index = y * imageWidth + x;
                        pixelatedImage[index] = avgIntensity;
                    }
                }
            }
        }

        // Replace the original PGM image with the pixelated image
        free(loadedImagePGM->pixels);
        loadedImagePGM->pixels = pixelatedImage;
        printf("Effect applied: Pixelation (PGM)\n");
     }
    else {
        showMenuText(5);
    }
}


void applySobelEffect() {
    // Créer un array temporaire pour stocker le résultat du filtre de Sobel
    unsigned char* sobelImage = (unsigned char*)malloc(loadedImagePGM->width * loadedImagePGM->height * sizeof(unsigned char));
    // Définir les noyaux de Sobel pour la détection de contour
    int sobelKernelX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int sobelKernelY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    // Appliquer le filtre de Sobel
    for (int row = 1; row < loadedImagePGM->height - 1; ++row) {
        for (int col = 1; col < loadedImagePGM->width - 1; ++col) {
            int gx = 0, gy = 0;
            // Appliquer le noyau de Sobel en X et Y
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    gx += sobelKernelX[i + 1][j + 1] * loadedImagePGM->pixels[(row + i) * loadedImagePGM->width + (col + j)];
                    gy += sobelKernelY[i + 1][j + 1] * loadedImagePGM->pixels[(row + i) * loadedImagePGM->width + (col + j)];
                }
            }
            // Calculer le gradient total
            int gradient = (int)sqrt(gx * gx + gy * gy);
            // Limiter la valeur du gradient à 255
            sobelImage[row * loadedImagePGM->width + col] = (unsigned char)(gradient > 255 ? 255 : gradient);
        }
    }

    // Copier l'image résultante dans l'image originale
    for (int i = 0; i < loadedImagePGM->width * loadedImagePGM->height; ++i) {
        loadedImagePGM->pixels[i] = sobelImage[i];
    }

    // Libérer l'array temporaire
    free(sobelImage);
}


void seuillageImage(int threshold) {
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
        // Seuillage
        for (int i = 0; i < width * height; i++) {
            if (loadedImagePGM->pixels[i] < threshold) {
                newPixels[i] = 0; // En dessous de valeur minimale
            } else {
                newPixels[i] = 255; // Au dessus de valeur maximale
            }
        }

        // liberer la mémoire
        free(loadedImagePGM->pixels);

        // Update the image structure with the new pixel data
        loadedImagePGM->pixels = newPixels;

    } else {
        showMenuText(5);
    }
}
