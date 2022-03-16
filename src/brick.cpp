#include "brick.h"
#include "collision.h"
#include "engine.h"
#include <SDL/SDL.h>

void Brick::draw()
{
	if (health == 0) return;


	//SDL_Rect rect = {(int)x, (int)y, w, h};
	SDL_SetRenderDrawColor(render, r, g, b, 255);
	//SDL_RenderFillRect(render, &rect);
	AABB box = AABB::make_from_position_size(x, y, w, h);
	draw_box(box);
}
