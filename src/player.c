/*
Copyright (C) 2015-2018 Parallel Realities

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#include "common.h"

static SDL_Texture *astronut[7];

void initPlayer(void)
{
	player = malloc(sizeof(Entity));
	memset(player, 0, sizeof(Entity));
	stage.entityTail->next = player;
	stage.entityTail = player;

	player->health = 1;

	astronut[0] = loadTexture("gfx/astroF1.png"); // stand faceing right
	astronut[1] = loadTexture("gfx/astroB1.png"); // stand faceing left

	astronut[2] = loadTexture("gfx/astroF2.png"); // walking faceing right
	astronut[3] = loadTexture("gfx/astroB2.png"); // walking faceing left

	astronut[4] = loadTexture("gfx/astroFJ.png"); // jump faceing right
	astronut[5] = loadTexture("gfx/astroBJ.png"); // jump faceing left

	astronut[6] = loadTexture("gfx/astroFS.png"); // shoot faceing right
	astronut[7] = loadTexture("gfx/astroBS.png"); // shoot faceing left


	player->texture = astronut[2];

	SDL_QueryTexture(player->texture, NULL, NULL, &player->w, &player->h);
}

void doPlayer(void)
{
	player->dx = 0;

	if (app.keyboard[SDL_SCANCODE_A])
	{
		player->dx = -PLAYER_MOVE_SPEED;

		player->texture = astronut[3];
		player->facing = LEFT;
	}

	if (app.keyboard[SDL_SCANCODE_D])
	{
		player->dx = PLAYER_MOVE_SPEED;

		player->texture = astronut[2];
		player->facing = RIGHT;
	}

	if (app.keyboard[SDL_SCANCODE_SPACE] && player->isOnGround) // jumping
	{
		player->dy = -15;
	}

	if (app.keyboard[SDL_SCANCODE_LSHIFT])
	{
		initBullet();
	}

	if (app.keyboard[SDL_SCANCODE_R] && player->health <= 0)
	{
		initPlayer();
	}

	if (player->facing == RIGHT && player->dx == 0)
	{
		player->texture = astronut[0];
	}
	if (player->facing == LEFT && player->dx == 0)
	{
		player->texture = astronut[1];
	}
	if (player->facing == RIGHT && !player->isOnGround)
	{
		player->texture = astronut[4];
	}
	if (player->facing == LEFT && !player->isOnGround)
	{
		player->texture = astronut[5];
	}
}