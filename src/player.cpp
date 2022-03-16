#include "player.h"
#include "engine.h"
#include "game.h"

void Player::update()
{
	// move
	if (get_key(SDL_SCANCODE_D))
		x += 300 * delta_time;
	if (get_key(SDL_SCANCODE_A))
		x -= 300 * delta_time;
	//if (keys[SDL_SCANCODE_W])
	//	y -= 200 * delta_time;
	//if (keys[SDL_SCANCODE_S])
	//	y += 200 * delta_time;

	// shoot! pew pew
	shoot_timer -= delta_time;
	if (get_key_pressed(SDL_SCANCODE_SPACE))
	{
		Projectile& proj = projectiles[next_projectile_index];
		proj.alive = true;
		proj.x = x;
		proj.y = y-10;

		proj.velocity_x = 200.f;
		
		if (next_projectile_index % 2)
			proj.velocity_y = 200.f;
		else
			proj.velocity_y = -200.f;
			

		shoot_timer = 1.f;

		next_projectile_index++;
		next_projectile_index = next_projectile_index % PROJECTILES_MAX;
	}
}

void Player::draw()
{
	SDL_SetRenderDrawColor(render, 150, 25, 40, 255);
	SDL_Rect rect = { (int)x - (w/2), (int)y, w, h};
	SDL_RenderFillRect(render, &rect);
}
