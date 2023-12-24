#include <stdlib.h>
#include <stdio.h>
#include "../include/imageRender.h"
#include "../include/imageCreate.h"
#include "../include/openImage.h"
#include "../include/menumain.h"

void saveImage(){
    int errorCode = 0;
    if(imageIsLoadedPGM == 1 || imageIsLoadedPPM == 1){
        if (imageIsLoadedPGM == 1 ){
            // Image de format PGM
            if (pgm != NULL){
                // Image non NULL
                savePGM();
            }
            else {
                // Image NULL
            }
        }
        else {
            // Image de format PPM
            if (ppm != NULL){
                // Image non NULL
                savePPM();
            }
            else {
                // L'image est NULL
            }
        }
    }
    else {
        // Pas d'image à sauvegarder
        showMenuText(2);
    }
}

void savePPM(){

}
void savePGM(){
    
}