#include "game.h"
#include <iostream>


const char* LEVEL1COLORS =
"   222   "
"  21112  "
" 2110112 "
"211000112"
" 2110112 "
"  21112  "
"   222   ";

const char* LEVEL1HEALTH =
"   111   "
"  12221  "
" 1223221 "
"122333221"
" 1223221 "
"  12221  "
"   111   ";

Player player;
Projectile projectiles[PROJECTILES_MAX];
Brick* bricks[BRICKS_MAX] = {nullptr};



void load_map()
{
	const char* color_ptr = LEVEL1COLORS;
	const char* health_ptr = LEVEL1HEALTH;

	for (size_t y = 0; y < BRICKS_ROWS; y++)
	{
		for (int x = 0; x < BRICKS_COLS; ++x, ++color_ptr, ++health_ptr)
		{

			if (*color_ptr != ' ')
			{
				Brick* brick = new Brick;
				brick->x = x * 80 + 80;
				brick->y = y * 30 + 50;
				//brick->color = *color_ptr - 48;
				brick->health = *health_ptr -48;
				switch (*color_ptr)
				{
					case 0 + 48: brick->r = 255;
						break;
					case 1 + 48: brick->g = 255;
						break;
					case 2 + 48: brick->b = 255;
						break;
				}
				bricks[y * BRICKS_COLS + x] = brick;
			}
			else
			{
				Brick* brick = new Brick;
				brick->alive == false;
				bricks[y * BRICKS_COLS + x] = brick;
			}
			
		}
	}
}