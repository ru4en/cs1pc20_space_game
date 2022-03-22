
#include "common.h"

static SDL_Texture* bullet;


void initBullet(void)
{
	bullet = malloc(sizeof(Entity));
	memset(bullet, 0, sizeof(bullet));

	bullet = loadTexture("gfx/shot.png");

	bullet->texture = bullet[0];

	SDL_QueryTexture(bullet->texture, NULL, NULL, &bullet->w, &bullet->h);
}