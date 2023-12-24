#include <stdio.h>
#include <stdlib.h>
#include "../include/imageCreate.h"






imagePGM* createImagePGM(FILE* image) {
    imagePGM* pgm = (imagePGM*)malloc(sizeof(imagePGM));

    // Read PGM header
    fscanf(image, "P5 %d %d 255\n", &pgm->width, &pgm->height);

    // Allocate memory for pixel data
    pgm->data = (unsigned char*)malloc(pgm->width * pgm->height * sizeof(unsigned char));

    // Read pixel data
    fread(pgm->data, sizeof(unsigned char), pgm->width * pgm->height, image);


    int errorCode = 0 ;
    printf("Création PGM");
    scanf("%d", &errorCode);

    return pgm;
}

imagePPM* createImagePPM(FILE* image) {
    imagePPM* ppm = (imagePPM*)malloc(sizeof(imagePPM));

    // Read PPM header
    fscanf(image, "P6 %d %d 255\n", &ppm->width, &ppm->height);

    // Allocate memory for pixel data
    ppm->data = (unsigned char*)malloc(3 * ppm->width * ppm->height * sizeof(unsigned char));

    // Read pixel data
    fread(ppm->data, sizeof(unsigned char), 3 * ppm->width * ppm->height, image);



    int errorCode = 0 ;
    printf("Création PPM");
    scanf("%d", &errorCode);
    return ppm;

    
}