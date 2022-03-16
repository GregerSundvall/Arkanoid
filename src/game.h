#pragma once
#include "player.h"
#include "projectile.h"
#include "brick.h"
#define PROJECTILES_MAX 20
#define BRICKS_COLS 9
#define BRICKS_ROWS 7
#define BRICKS_MAX (BRICKS_COLS * BRICKS_ROWS)

extern Player player;
extern Projectile projectiles[PROJECTILES_MAX];
extern Brick* bricks[BRICKS_MAX];

void load_map();