#pragma once
#include <SDL/SDL.h>

extern SDL_Window* window;
extern SDL_Renderer* render;

struct Key_state
{
	bool state = false;
	int change_frame = 0;
};

extern Key_state keys[SDL_NUM_SCANCODES];
bool get_key(SDL_Scancode key);
bool get_key_pressed(SDL_Scancode key);
bool get_key_released(SDL_Scancode key);


extern float delta_time;
extern int frame_number;
