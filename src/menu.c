
#include "common.h"

void initMenu(void)
{
	SDL_ShowCursor(1);
	long then;
	then = SDL_GetTicks();
	//SDL_SetRenderDrawColor(app.renderer, 200, 53, 53, 235);

	SDL_Texture* menuImg = IMG_LoadTexture(app.renderer, "gfx/menu.png");

	int exit = 0;

	while (!exit)
	{
		SDL_RenderCopy(app.renderer, menuImg, NULL, NULL);
		SDL_RenderPresent(app.renderer);

		doInput();

		if (app.keyboard[SDL_SCANCODE_1])
		{
			level = 1;
			exit = 1;
		}
		if (app.keyboard[SDL_SCANCODE_2])
		{
			level = 2;
			exit = 1;
		}
		if (app.keyboard[SDL_SCANCODE_3])
		{
			level = 3;
			exit = 1;
		}
		if (app.keyboard[SDL_SCANCODE_4])
		{
			level = 4;
			exit = 1;
		}
		if (app.keyboard[SDL_SCANCODE_5])
		{
			level = 5;
			exit = 1;

		}
		if (app.keyboard[SDL_SCANCODE_Q])
		{
			cleanup();
		}
		presentScene();
	}
	initStage();

}
