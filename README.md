# EDITEUR PHOTO EN C 

## Expliquation du projet

Ce projet a été fait pour un cours en c avancé à l'ESGI. Il a pour but de créer une application avec une interface graphique sans utiliser des librairies pour l'edition d'images.
Il est basé sur les formats PPM (couleurs) et PGM (noir et blanc), des formats d'images simples qui sont convertis en structs avant les modifications.

# Table de matières
- ## I - Introduction
- ## II - Modes d'utilisations 
    - ### Liste des filtres
- ## III - Fonctionalités
    - ### 1 - Ajoutées
    - ### 2 - A ajouter 
- ## IV - Codes d'erreur
    - ### Les codes 000
    - ### Les codes 100
    - ### Les codes 200
- ## V - Bibliographie


# Introduction 
Le projet d'éditeur photo a pour objectif d'editer les photos de format ppm et pgm, étant écrit en C et sans utiliser des libraries de filtres d'images.

# Modes d'utilisations
Les images PPM sont actuellement fonctionnelles mais contiennent des erreurs, comme le changement de la couleur de l'image lors de la sauvegarde.
### Les filtres actuels : 
      - Filtre négatif
      - Floutage
      - Pixélisation
      - Filtre Sobel
      - Seuillage
### Les effets actuels : 
      - Translation
      - Mirroir (non fonctionnel actuellement)
      - Rotation (non fonctionnel actuellement)
# Fonctionalités 
### Ajoutées :
      - Filtres pour PGM
      - Effets pour PGM
      - Sauvegarde avec noms customisables
      - Erreurs documentées
### A ajouter : 
      - Filtres et Effets pour PPM
      - Interface GUI
# Codes d'erreurs
### Codes 000 : Erreurs Simple
      - Code 0 : Aucune erreur.
      - Code 1 : Mauvais choix menu.
      - Code 2 : Pas d'image à sauvegarder.
      - Code 3 : Le nom d'image est déjà utilisé.
      - Code 4 : Pas d'image choisie.
      - Code 5 : Fonctionalité en developpement.
### Codes 100 : Problèmes d'image
      - Code 101 : L'image n'a pas été chargée correctement.
      - Code 102 : L'image n'est pas du format attendu.
      - Code 103 : L'image n'a pas d'extension, ou commence avec un .
      - Code 104 : Image introuvable.
      - Code 105 : Erreur header PPM/PGM.
      - Code 106 : Erreur lecture données pixels.
      - Code 107 : Données pixels corrompues.
      - Code 108 : Erreur taille d'image
### Codes 200 : Problèmes de chargement
      - Code 201 : Allocation mémoire échouée.
      - Code 202 : Erreur lors de sauvegarde (Impossible de créer fichier).
      - Code 203 : Erreur de création de struct (inconnu).
### Autres Codes : 
      - Code -1 : Sauvegarde de l'image (pas une erreur).
      - Code -2 : Filtre appliqué.
      - Code -3 : Effet appliqué.
# Bibliographies 
Beaucoup de sources ont étés utilisées afin d'accomplir ce projet.
Les compétences sont transférées par les sources, et acquises par la pratique.
### Sources : 
      - Documentations du langage C pour les fonctions std.io et stdlib.h
      - StackOverflow
      - ChatGPT
      - Cours reçus à l'ESGI
