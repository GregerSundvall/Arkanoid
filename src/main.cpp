#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include "engine.h"
#include "player.h"
#include "game.h"
#include "collision.h"

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING); 
	TTF_Init();

	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,600,0); 
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
 
	TTF_Font* font = TTF_OpenFont("res/roboto.ttf", 14);
	SDL_Surface* text_surf = TTF_RenderText_Solid(font, "Bleep bloop", {255, 0, 255, 255});
	SDL_Texture* text_texture = SDL_CreateTextureFromSurface(render, text_surf);
	
	// In case youre changing the texture (updating tect etc)
	// RenderCopy stuff goes here
	// SDL_FreeSurface(text_surf);
	// SDL_DestroyTexture(text_texture);

	bool running = true;
	Uint64 previous_ticks = SDL_GetPerformanceCounter();

	load_map();

	while (running)
	{
		frame_number++;

		Uint64 ticks = SDL_GetPerformanceCounter();
		Uint64 delta_ticks = ticks - previous_ticks;
		previous_ticks = ticks; 
		delta_time = (float)delta_ticks / SDL_GetPerformanceFrequency(); 
 
		SDL_Event event;
		while(SDL_PollEvent(&event)) 
		{
			switch(event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
 
			case SDL_KEYDOWN:
			{
				if (event.key.repeat)
				{
					break;
				}
				int scancode = event.key.keysym.scancode;
				if (scancode == SDL_SCANCODE_ESCAPE)
					running = false;

				keys[scancode].state = true;
				keys[scancode].change_frame = frame_number;
 
				break;
			}
 
			case SDL_KEYUP:
			{
				int scancode = event.key.keysym.scancode;
				keys[scancode].state = false;
				keys[scancode].change_frame = frame_number;
 
				break;
			}
			}
		}
 
		SDL_SetRenderDrawColor(render, 25, 25, 40, 255); 
		SDL_RenderClear(render);

		player.update();
		player.draw();

		for(int i=0; i<PROJECTILES_MAX; ++i)
		{
			projectiles[i].update();
			projectiles[i].draw();
		}

		for(int i=0; i<BRICKS_MAX; ++i)
		{
			Brick* brick = bricks[i];
			brick->draw();
			if (brick == nullptr) continue;
		}

		SDL_Rect text_dst = {20, 20, text_surf->w, text_surf->h};
		SDL_RenderCopy(render, text_texture, NULL, &text_dst);

		SDL_RenderPresent(render);
 
		SDL_Delay(16); 
	}
}
