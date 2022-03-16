#pragma once

struct Player
{
	float x = 400.f;
	float y = 550.f;
	float w = 100.f;
	float h = 20.f;

	bool is_alive = true;

	float shoot_timer = 0.f;
	int next_projectile_index = 0;

	void update();
	void draw();
};
