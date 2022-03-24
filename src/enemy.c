
#include "common.h"

static void tick(void);
static void touch(Entity* other);


void initEnemy(char* line)
{
	Enemy* e;

	e = malloc(sizeof(Enemy));
	memset(e, 0, sizeof(Enemy));
	stage.entityTail->next = e;
	stage.entityTail = e;
	SDL_Texture* texture[3];

	sscanf(line, "%*s %f %f %f %f", &e->sx, &e->sy, &e->ex, &e->ey);

	e->health = 100;

	e->x = e->sx;
	e->y = e->sy;

	e->tick = tick;
	e->touch = touch;

	texture[0] = loadTexture("gfx/astroF1.png");
	texture[1] = loadTexture("gfx/astroB2.png");
	e->texture = texture[1];


	SDL_QueryTexture(e->texture, NULL, NULL, &e->w, &e->h);
	e->flags = EF_PUSH;
}

static void tick(void)
{
	if (abs(self->x - self->sx) < PLATFORM_SPEED && abs(self->y - self->sy) < PLATFORM_SPEED)
	{
		calcSlope(self->ex, self->ey, self->x, self->y, &self->dx, &self->dy);

		self->dx *= PLATFORM_SPEED;
		self->dy *= PLATFORM_SPEED;
	}

	if (abs(self->x - self->ex) < PLATFORM_SPEED && abs(self->y - self->ey) < PLATFORM_SPEED)
	{
		calcSlope(self->sx, self->sy, self->x, self->y, &self->dx, &self->dy);

		self->dx *= PLATFORM_SPEED;
		self->dy *= PLATFORM_SPEED;
	}
}

static void touch(Enemy* other)
{
	other->health -= 1;
}
