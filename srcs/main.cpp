#include "../includes/main.h"







int main(int argc, char *argv[])
{
    cout << "hello"<<endl;
    int continuer = 1, precision=20, color=2, WINDOW_HEIGHT=720, WINDOW_LENGTH=1280, fullscreen=1, indiceGeneration=1, temps=0, i=0, posX=0, posY=0, relache=1, bigzoom = 4;
    double x=-0.5,y= 0.0, coefficient=1.01, Re_c=-0.73, Im_c=0.13, zoom=1000.0, facteurZoom = 1.5;

    double a = 16, b=33, c=100;
    // Read parameters from config file
    FILE* configuration = NULL;
    FILE* log = NULL;
    configuration = fopen("configuration.txt", "r+");
    fscanf(configuration, "precision : %d, hauteur : %d, largeur : %d, fullscreen : %d, indiceGeneration : %d, x : %lf, y : %lf, Re_c : %lf, Im_c : %lf, zoom : %lf.", &precision, &WINDOW_HEIGHT, &WINDOW_LENGTH, &fullscreen, &indiceGeneration, &x, &y, &Re_c, &Im_c, &zoom);
    fclose(configuration);

    // Init SDL
    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;
    SDL_Surface *screen = NULL;
    SDL_Surface *big_screen = NULL;
    SDL_Texture* texture;
    srand (time(NULL));

  

    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_CreateRGBSurface (0, WINDOW_LENGTH, WINDOW_HEIGHT, 32, 0, 0, 0, 0);

    SDL_CreateWindowAndRenderer(WINDOW_LENGTH, WINDOW_HEIGHT, 0, &window, &renderer);
   	
   	/*zoom = 2000;
   	precision = 40;
   	color = 2;
    for (float x = 0; x<1; x+=0.05){
	    for (float y = 0; y<1; y+=0.05){  
		    for (float Re_c = -1.0; Re_c<0.5; Re_c+=0.01){
		    	for (float Im_c = 0.0; Im_c<0.6; Im_c+=0.01){
		    		if (Genere(x,y,precision,zoom,coefficient,Re_c, color, Im_c, WINDOW_HEIGHT, WINDOW_LENGTH, indiceGeneration, screen, a, b, c)){
		    			save_image(screen, x ,y, Re_c, Im_c, zoom, precision );
		    		}
				    texture = SDL_CreateTextureFromSurface(renderer, screen);
				    SDL_RenderCopy(renderer, texture, NULL,NULL);
				    SDL_RenderPresent(renderer);
				    
			    }
		    }
		}
	}
    return 0;*/
    	/*color = 2;
		    	for (int precision = 1; precision<100; precision+=1){
		    		if (Genere(x,y,precision,zoom,coefficient,Re_c, color, Im_c, WINDOW_HEIGHT, WINDOW_LENGTH, indiceGeneration, screen, a, b, c)){
		    			save_image(screen, x ,y, Re_c, Im_c, zoom, precision );
		    		}
				    texture = SDL_CreateTextureFromSurface(renderer, screen);
				    SDL_RenderCopy(renderer, texture, NULL,NULL);
				    SDL_RenderPresent(renderer);
				    
			    }*/
	
    Genere(x,y,precision,zoom,coefficient,Re_c, color, Im_c, WINDOW_HEIGHT, WINDOW_LENGTH, indiceGeneration, screen, a, b, c);
    texture = SDL_CreateTextureFromSurface(renderer, screen);
    SDL_RenderCopy(renderer, texture, NULL,NULL);
    SDL_RenderPresent(renderer);
    // event loop
    while (continuer)
    {
        SDL_WaitEvent(&event);

        switch(event.type){

            case SDL_QUIT:
            continuer = 0;

            case SDL_KEYDOWN://Gestion des évènements clavier
            log = fopen("log.txt", "w+");
                        fprintf(log, "%d", event.key.keysym.sym);
                        fclose(log);
                switch (event.key.keysym.sym){
                        case SDLK_z: //déplacement en haut
                        y-=(WINDOW_HEIGHT/zoom)*0.25;
                        break;

                        case SDLK_s: //déplacement en bas
                        y+=(WINDOW_HEIGHT/zoom)*0.25;
                        break;

                        case SDLK_i: //mandelbrot v s Julia
                        indiceGeneration=1-indiceGeneration;
                        break;

                        case SDLK_q: //déplacement à gauche
                        x-=(WINDOW_LENGTH/zoom)*0.2;
                        break;

                        case SDLK_d: //déplacement à droite
                        x+=(WINDOW_LENGTH/zoom)*0.2;
                        break;

                        case SDLK_1: //changement de la couleur
                        color=1;
                        break;

                        case SDLK_2: //changement de la couleur
                        color=2;
                        break;

                        case SDLK_3: //changement de la couleur
                        color=3;
                        break;

                        case SDLK_4: //changement de la couleur
                        color=4;
                        break;

                        case SDLK_5: //changement de la couleur
                        color=5;
                        break;

                        case SDLK_w: //changement de la couleur
  							a = rand() % 100;
  							b = rand() % 100;
  							b = rand() % 100;
                        break;

                       
                        case SDLK_h: //changement de la couleur
                        	bigzoom = 4;
                        	big_screen = SDL_CreateRGBSurface (0, bigzoom*WINDOW_LENGTH, bigzoom*WINDOW_HEIGHT, 32, 0, 0, 0, 0);
                        	Genere(x,y,precision,bigzoom*zoom,coefficient,Re_c, color, Im_c, bigzoom*WINDOW_HEIGHT, bigzoom*WINDOW_LENGTH, indiceGeneration, big_screen, a, b, c);
                        	save_image(big_screen, x ,y, Re_c, Im_c, zoom, precision );
                        	/*for (float Re_c = 0; Re_c<1; Re_c+=0.1){
						    	for (float Im_c = 0; Im_c<1; Im_c+=0.1){
						    		Genere(x,y,precision,zoom,coefficient,Re_c, color, Im_c, WINDOW_HEIGHT, WINDOW_LENGTH, indiceGeneration, screen);
								    texture = SDL_CreateTextureFromSurface(renderer, screen);
								    SDL_RenderCopy(renderer, texture, NULL,NULL);
								    SDL_RenderPresent(renderer);
								    save_image(screen, x ,y, Re_c, Im_c, zoom, precision );
							    }
						    }*/
                        break;
                        

                        case SDLK_KP_PLUS: //zoom
                        zoom*=facteurZoom;
                        break;

                        case SDLK_KP_MINUS: //dé-zoom
                        zoom/=facteurZoom;
                        break;

                        case SDLK_p: //augmenter le niveau de précision
                        precision+=10;
                        break;

                        case SDLK_r: //initialiser
                        x=-0.5;
                        y=0;
                        precision=20;
                        zoom=1000;
                        Re_c=0.285;
                        Im_c=0.01;
                        break;

                        case SDLK_o:
                            if (precision>10){//diminuer niveau de précision
                                precision-=10;
                            }
                            break;

                        case SDLK_RIGHT: //changer le motif
                        Re_c+=0.01;
                        break;

                        case SDLK_LEFT: //changer le motif
                        Re_c-=0.01;
                        break;

                        case SDLK_UP: //changer le motif
                        Im_c+=0.01;
                        break;

                        case SDLK_DOWN: //changer le motif
                        Im_c-=0.01;
                        break;

                        case SDLK_m: //augmenter le nombre de points quand il y a trop d'arrondis
                        coefficient+=0.1;
                        break;

                        case SDLK_n://diminuer le nombre de points quand il y a trop d'arrondis
                        if ( coefficient>1.11){
                            coefficient-=0.1;
                        }
                        break;

                        case SDLK_g: //enregistrer le position actuelle
                        configuration = fopen("export/configuration.txt", "w+");
                        fprintf(configuration, "precision : %d, hauteur : %d, largeur : %d, fullscreen : %d, indiceGeneration : %d, x : %lf, y : %lf, Re_c : %lf, Im_c : %lf, zoom : %lf.", precision, WINDOW_HEIGHT, WINDOW_LENGTH, fullscreen, indiceGeneration, x, y, Re_c, Im_c, zoom);
                        fclose(configuration);
                        break;

                        case SDLK_v: //estimation temps
                        log = fopen("log.txt", "w+");
                        temps=clock();
                        for (i=0; i<100;i++){
                            Genere(x,y,precision,zoom,coefficient,Re_c, color, Im_c, WINDOW_HEIGHT, WINDOW_LENGTH, indiceGeneration, screen, a, b, c);
						    texture = SDL_CreateTextureFromSurface(renderer, screen);
						    SDL_RenderCopy(renderer, texture, NULL,NULL);
						    SDL_RenderPresent(renderer);
						    //save_image(screen, x ,y, Re_c, Im_c, zoom, precision );
                        }
                        fprintf(log, "%d", (clock()-temps));
                        fclose(log);
                        break;


                        case SDLK_ESCAPE:
                        continuer=0;

                        default:
                        break;
                    }

                Genere(x,y,precision,zoom,coefficient,Re_c, color, Im_c, WINDOW_HEIGHT, WINDOW_LENGTH, indiceGeneration, screen, a, b, c);
			    texture = SDL_CreateTextureFromSurface(renderer, screen);
			    SDL_RenderCopy(renderer, texture, NULL,NULL);
			    SDL_RenderPresent(renderer);
            break;

            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button){
                    case SDL_BUTTON_LEFT:
                    if (relache==1){
                       posX=event.button.x;
                       posY=event.button.y;
                       relache = 0;
                   }

                   break;
               }
            break;

            case SDL_MOUSEMOTION:
               if (relache==0){
                x=x-2*(event.button.x-posX)/zoom;
                y=y-2*(event.button.y-posY)/zoom;
                posX=event.button.x;
                posY=event.button.y;
            }
            //Genere(x,y,precision,zoom,coefficient,Re_c, color, Im_c, WINDOW_HEIGHT, WINDOW_LENGTH, indiceGeneration, renderer);
            break;

            case SDL_MOUSEBUTTONUP://Gestion des évènements souris
                switch (event.button.button){
                    case SDL_BUTTON_LEFT:
                    relache = 1;
                    break;
                }
            break;

            case SDL_MOUSEWHEEL:
                if (event.wheel.y > 0){
                    zoom*=facteurZoom;
                    Genere(x,y,precision,zoom,coefficient,Re_c, color, Im_c, WINDOW_HEIGHT, WINDOW_LENGTH, indiceGeneration, screen, a, b, c);
				    texture = SDL_CreateTextureFromSurface(renderer, screen);
				    SDL_RenderCopy(renderer, texture, NULL,NULL);
				    SDL_RenderPresent(renderer);

                } else {
                    zoom/=facteurZoom;
                    Genere(x,y,precision,zoom,coefficient,Re_c, color, Im_c, WINDOW_HEIGHT, WINDOW_LENGTH, indiceGeneration, screen, a, b, c);
				    texture = SDL_CreateTextureFromSurface(renderer, screen);
				    SDL_RenderCopy(renderer, texture, NULL,NULL);
				    SDL_RenderPresent(renderer);	
                }
            break;

        }


    }


    SDL_Quit();
    fclose(configuration);
    return EXIT_SUCCESS;
}




bool Genere(double x,double y,int precision,double zoom, double coefficient,double Re_c,int color, double Im_c,int WINDOW_HEIGHT, int WINDOW_LENGTH,  int indiceGeneration, SDL_Surface *screen, double a, double b, double c){

    int i = 0;
    int n = 16  ;
    bool reach_iteration = false;

    //#pragma omp parallel for num_threads(16)
        for (i=-n/2; i<n/2; i++){
            if (indiceGeneration == 0){
                 reach_iteration = Julia (x+(2*i+1)*WINDOW_LENGTH/(n*zoom),y,precision,zoom,coefficient,Re_c, color,Im_c, WINDOW_HEIGHT, WINDOW_LENGTH/n+3, screen, (i+n/2)*WINDOW_LENGTH/n, a, b, c) || reach_iteration;
            } else {
                reach_iteration =   MendelBrot (x+(2*i+1)*WINDOW_LENGTH/(n*zoom),y,precision,zoom,coefficient, color, WINDOW_HEIGHT, WINDOW_LENGTH/n+3, screen, (i+n/2)*WINDOW_LENGTH/n, a, b, c) || reach_iteration;
            }
            
        }
        return reach_iteration;
}



bool Julia(double x,double y,int iteration_max, double zoom, double coefficient, double Re_c, int color, double Im_c, int WINDOW_HEIGHT, int WINDOW_LENGTH, SDL_Surface *screen, int ajout, double a, double b, double c)
{
    int iteration=0, x_point=0, y_point=0, iMax=0, jMax=0;
    double i=0, j=0;
    double Re_z=0, Im_z=0, temp=0, t=0;
    double Lz=0, Hz=0, zoomSurDeux=0, xMoinsLz=0,yMoinsHz=0, coefficientX=0, coefficientY=0,zoomSurDeuxFoisCoef=0, Re_z_carre=0, Im_z_carre=0;

    Lz=(WINDOW_LENGTH)/zoom;//pour éviter de le recalculer plein de fois !
    Hz=(WINDOW_HEIGHT)/zoom;//idem
    zoomSurDeux=(zoom/2);//idem
    zoomSurDeuxFoisCoef=1/((zoom/2)*coefficient);//idem
    xMoinsLz=x-Lz;//idem
    yMoinsHz=y-Hz;//idem
    coefficientX=(-x+Lz)*zoomSurDeux;//idem
    coefficientY=(-y+Hz)*zoomSurDeux;//idem

    iMax=coefficient*WINDOW_LENGTH;
    jMax=coefficient*WINDOW_HEIGHT;
    bool reach_iteration = false;

    for(i=0; i<iMax ;i++){
        for (j=0; j<jMax ;j++){

            Re_z = xMoinsLz + (i*zoomSurDeuxFoisCoef);
            Im_z = yMoinsHz + (j*zoomSurDeuxFoisCoef);

            x_point=(Re_z*zoomSurDeux+coefficientX);
            y_point=(Im_z*zoomSurDeux+coefficientY);

            if(x_point>0 && x_point<WINDOW_LENGTH && y_point>0 && y_point<WINDOW_HEIGHT){

                iteration = 0;
                Re_z_carre=Re_z*Re_z;
                Im_z_carre=Im_z*Im_z;

                while (Re_z_carre+Im_z_carre<4 && iteration < iteration_max){
                    temp=Re_z;
                    Re_z = Re_z_carre - Im_z_carre + Re_c;
                    Im_z = 2*Im_z*temp + Im_c;
                    Re_z_carre=Re_z*Re_z;
                    Im_z_carre=Im_z*Im_z;
                    iteration++;

                }
                if (!reach_iteration && iteration < iteration_max){
                	reach_iteration = true;
                }

                t=(iteration/iteration_max);


                colorify(screen, x_point+ajout, y_point, iteration, iteration_max, color, a, b, c);
            }



        }
    }
    return reach_iteration;
}



bool MendelBrot(double x,double y,int iteration_max, double zoom, double coefficient, int color, int WINDOW_HEIGHT, int WINDOW_LENGTH, SDL_Surface *screen, int ajout, double a, double b, double c)
{
    int iteration=0, x_point=0, y_point=0;
    int i=0, j=0, iMax=0, Jmax=0;
    double Re_c=0, Im_c=0, Re_z=0, Im_z=0, temp=0, Re_z_carre=0, Im_z_carre=0;
    double Lz=0, Hz=0, zoomSurDeux=0, xMoinsLz=0,yMoinsHz=0, coefficientX=0, coefficientY=0,zoomSurDeuxFoisCoef=0;

    Lz=(WINDOW_LENGTH)/zoom;//pour éviter de le recalculer plein de fois !
    Hz=(WINDOW_HEIGHT)/zoom;//idem
    zoomSurDeux=(zoom/2);//idem
    zoomSurDeuxFoisCoef=1/((zoom/2)*coefficient);
    xMoinsLz=x-Lz;
    yMoinsHz=y-Hz;
    coefficientX=(-x+Lz)*zoomSurDeux;
    coefficientY=(-y+Hz)*zoomSurDeux;

    iMax=coefficient*WINDOW_LENGTH;
    Jmax=coefficient*WINDOW_HEIGHT;

    bool reach_iteration = false;

    for(i=0; i<iMax;i++){
        for (j=0; j<Jmax;j++){
            Re_c = xMoinsLz + (i*zoomSurDeuxFoisCoef);
            Im_c = yMoinsHz + (j*zoomSurDeuxFoisCoef);

            x_point=(Re_c*zoomSurDeux+coefficientX);
            y_point=(Im_c*zoomSurDeux+coefficientY);

            if(x_point>0 && x_point<WINDOW_LENGTH && y_point>0 && y_point<WINDOW_HEIGHT){

                Re_z = 0;
                Im_z = 0;
                iteration = 0;
                Re_z_carre=0;
                Im_z_carre=0;


                while (Re_z_carre+Im_z_carre<4 && iteration < iteration_max){
                    temp=Re_z;
                    Re_z=Re_z_carre-Im_z_carre;
                    Re_z += Re_c;
                    Im_z = 2*Im_z*temp + Im_c;
                    Re_z_carre=Re_z*Re_z;
                    Im_z_carre=Im_z*Im_z;
                    iteration++;

                }
                if (!reach_iteration && iteration < iteration_max){
                	reach_iteration = true;
                }

                colorify(screen, x_point+ajout, y_point, iteration, iteration_max, color, a, b, c);

            }


        }
    }

return reach_iteration;

}

void colorify(SDL_Surface *screen, int x, int y, int iteration, int iteration_max, int color, double a, double b, double c){
	Uint32 largeur = screen->w;
	int coloration;
    switch (color){
        case 1://noir et blanc
        if (iteration%2==0){
        	*((Uint32*)(screen->pixels) + x + y * largeur) = SDL_MapRGB(screen->format, 0, 0, 0);
        } else {
             *((Uint32*)(screen->pixels) + x + y * largeur) = SDL_MapRGB(screen->format, 255, 255, 255);
        }

        break;


        case 2://dégradé bleu
       coloration = 7*(iteration-iteration_max);
        *((Uint32*)(screen->pixels) + x + y * largeur) = SDL_MapRGB(screen->format, coloration, coloration, coloration);
        break;


        case 3://multicolor
        *((Uint32*)(screen->pixels) + x + y * largeur) = SDL_MapRGB(screen->format, a*sin((iteration-iteration_max)/10), b*sin((iteration-iteration_max)/10), c*sin((iteration-iteration_max)/10));
        break;


        case 4://multicolor
        *((Uint32*)(screen->pixels) + x + y * largeur) = SDL_MapRGB(screen->format, tan((iteration-iteration_max+0.5)), 0.5*tan((iteration-iteration_max+0.5)), tan((iteration-iteration_max)));
        break;


        case 5://dégradé orange
        *((Uint32*)(screen->pixels) + x + y * largeur) = SDL_MapRGB(screen->format, 255, 50*log2f(iteration_max-iteration), 0);
        break;

    }
}

void save_image(SDL_Surface *screen, float x ,float y, float Re_c, float Im_c, float zoom, int precision ){
	string name("export/out");
    name += to_string(x);
    name+= ",";
    name += to_string(y);
    name+= ",";
    name += to_string(Re_c);
    name+= ",";
    name += to_string(Im_c);
    name+= ",";
    name += to_string(zoom);
    name+= ",";
    name += to_string(precision);
    name+= ".bmp";
    // declaring character array
    char name_array[name.length() + 1];
    // copying the contents of the
    // string to char array
    strcpy(name_array, name.c_str());

	SDL_SaveBMP (screen, name_array);
}