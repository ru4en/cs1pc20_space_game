
#include "common.h"

static void tick(void);
static void touch(Entity* other);
SDL_Texture* texture[1];

void initEnemy(char* line)
{
	Enemy* e;

	e = malloc(sizeof(Enemy));
	memset(e, 0, sizeof(Enemy));
	stage.entityTail->next = e;
	stage.entityTail = e;

	sscanf(line, "%*s %f %f %f %f", &e->sx, &e->sy, &e->ex, &e->ey);

	e->health = 100;

	e->x = e->sx;
	e->y = e->sy;

	e->tick = tick;
	e->touch = touch;
	e->flags = EF_PUSH;

	texture[0] = loadTexture("gfx/alienF1.png");
	texture[1] = loadTexture("gfx/alienB1.png");
	e->texture = texture[0];

	SDL_QueryTexture(e->texture, NULL, NULL, &e->w, &e->h);
}

static void tick(void)
{
	if (abs(self->x - self->sx) < PLATFORM_SPEED)
	{
		calcSlope(self->ex, self->ey, self->x, self->y, &self->dx, &self->dy);

		self->dx *= PLATFORM_SPEED;
		self->dy *= PLATFORM_SPEED;
		self->texture = texture[0];
	}
	if (abs(self->x - self->ex) < PLATFORM_SPEED)
	{
		calcSlope(self->sx, self->sy, self->x, self->y, &self->dx, &self->dy);

		self->dx *= PLATFORM_SPEED;
		self->dy *= PLATFORM_SPEED;
		self->texture = texture[1];
	}
}

static void touch(Enemy* other)
{
	if (other == player)
	{
		other->health -= 1; 
	}
}