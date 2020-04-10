/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <memory>
#include "EventHandler.h"
#include "game.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;



int main( int argc, char* args[] )
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;
	
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface( window );

			//Fill the surface white
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0x00, 0x00 ) );
			
			//Update the surface
			SDL_UpdateWindowSurface( window );

			// Init the Game
			Game game = Game();

			bool quit = false;
			SDL_Event e;
			std::shared_ptr<EventHandler> Eh = std::make_shared<EventHandler>(EventHandler());
			KeyPress p;
			// Main loop
			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					else if (e.type == SDL_KEYDOWN)
					{
						switch (e.key.keysym.sym)
						{
						case SDLK_UP:
							p = KEY_PRESS_UP;
							break;
						case SDLK_DOWN:
							p = KEY_PRESS_DOWN;
							break;
						case SDLK_LEFT:
							p = KEY_PRESS_LEFT;
							break;
						case SDLK_RIGHT:
							p = KEY_PRESS_RIGHT;
							break;
						default:
							p = KEY_PRESS_DEFAULT;
							break;
						}
						Eh->handleEvent(p);
					}

				}

				//Apply the image
				SDL_BlitSurface(gXOut, NULL, screenSurface, NULL);

				//Update the surface
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}

	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}