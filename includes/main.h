#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <omp.h>
#include "../includes/SDL2/SDL.h"
#include<iostream>
#include<fstream>
using namespace std;



/* ---Déclaration des fonctions--- */
unsigned int tps(unsigned int intervalle, void *i);
bool Genere(double x,double y,int precision,double zoom, double coefficient,double Re_c,int color, double Im_c,int WINDOW_HEIGHT, int WINDOW_LENGTH,  int indiceGeneration, SDL_Surface *screen, double a, double b, double c);
bool Julia(double x,double y,int iteration_max,double zoom, double coefficient,double Re_c,int color, double Im_c,int WINDOW_HEIGHT, int WINDOW_LENGTH, SDL_Surface *screen, int ajout, double a, double b, double c);
bool MendelBrot(double x,double y,int iteration_max, double zoom, double coefficient, int color, int WINDOW_HEIGHT, int WINDOW_LENGTH, SDL_Surface *screen, int ajout, double a, double b, double c);
void colorify(SDL_Surface *screen, int x, int y, int iteration, int max_iteration, int color_pattern, double a, double b, double c);
void save_image(SDL_Surface *screen, float x ,float y, float Re_c, float Im_c, float zoom, int precision );
/* ------------------------------- */

