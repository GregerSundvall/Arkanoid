#pragma once
#include "collision.h"



struct Brick
{
	bool alive = true;
	int health = 1;
	int color = 0;

	float x;
	float y;
	float w = 70.f;
	float h = 20.f;

	int r = 0, g = 0, b = 0;

	AABB get_collision() { return { x, y, x + w / 2, y + h / 2 }; }
	void draw();
};
