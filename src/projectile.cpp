#include "projectile.h"
#include "engine.h"
#include "collision.h"
#include "game.h"
#include <stdlib.h>
float sign(float a) { return a > 0.f ? 1.f : -1.f; }

void Projectile::update()
{
	if (!alive)
		return;

	if (!step(velocity_x * delta_time, 0.f))
	{
		velocity_x = -velocity_x + sign(-velocity_x) * 10;
	}
	if (!step(0.f, velocity_y * delta_time))
	{
		velocity_y = -velocity_y + sign(-velocity_y) * 10;
	}
	//step(velocity_x * delta_time, velocity_y * delta_time);
}

void Projectile::draw()
{
	if (!alive)
		return;
	
	SDL_SetRenderDrawColor(render, rand()%256, rand()%256, rand()%256, rand()%256);

	//SDL_Rect rect = { (int)x - 4, (int)y - 4, 8, 8 };
	//SDL_RenderFillRect(render, &rect);

	int radius = 8;
	for (int w = 0; w < radius * 2; w++)
	{
		for (int h = 0; h < radius * 2; h++)
		{
			int dx = radius - w; // horizontal offset
			int dy = radius - h; // vertical offset
			if ((dx * dx + dy * dy) <= (radius * radius))
			{
				SDL_RenderDrawPoint(render, x + dx, y + dy);
			}
		}
	}
}

bool Projectile::step(float dx, float dy)
{
	// Collision check with brick!
	Circle circle = { x + dx, y + dy, 4 };
	draw_circle(circle);

	for (int i = 0; i < BRICKS_MAX; ++i)
	{
		
		Brick& brick = *bricks[i];
		if (!brick.alive)
			continue;

		AABB box = AABB::make_from_position_size(brick.x, brick.y, brick.w, brick.h);

		if (aabb_circle_intersect(box, circle))
		{
			brick.health--;
			if (brick.health == 0) 
			{ 
				brick.alive = false; 
			}
			else
			{
				brick.r = (brick.r == 0) ? 0 : brick.r / 2;
				brick.g = (brick.g == 0) ? 0 : brick.g / 2;
				brick.b = (brick.b == 0) ? 0 : brick.b / 2;
			}
			// Check if level is cleared here maybe?
			return false;
		}
	}

	
	if (dy > 0.f)
	{
		AABB box = AABB::make_from_position_size(player.x, player.y + 10, player.w, player.h);
		if (aabb_circle_intersect(box, circle))
		{
			/*velocity_y *= -1;*/
			return false;
		}
	}

	

	if (y > 600)
	{
		alive = false;
	}

	// Check collisions with game borders
	if (x + dx < 0 || x + dx >= 800 ||
		y + dy < 0)
	{
		return false;
	}

	x += dx;
	y += dy;
	return true;
}
