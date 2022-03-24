#include "common.h"
void initWidgets(void);
Widget* createWidget(char* name);
void doWidgets(void);

void initWidgets(void)
{
	memset(&widgetHead, 0, sizeof(Widget));
	widgetTail = &widgetHead;
}

Widget* createWidget(char* name)
{
	Widget* w;

	w = malloc(sizeof(Widget));
	memset(w, 0, sizeof(Widget));
	widgetTail->next = w;
	w->prev = widgetTail;
	widgetTail = w;

	STRCPY(w->name, name);

	return w;
}

void doWidgets(void)
{
	if (app.keyboard[SDL_SCANCODE_UP])
	{
		app.keyboard[SDL_SCANCODE_UP] = 0;

		app.activeWidget = app.activeWidget->prev;

		if (app.activeWidget == &widgetHead)
		{
			app.activeWidget = widgetTail;
		}
	}

	if (app.keyboard[SDL_SCANCODE_DOWN])
	{
		app.keyboard[SDL_SCANCODE_DOWN] = 0;

		app.activeWidget = app.activeWidget->next;

		if (app.activeWidget == NULL)
		{
			app.activeWidget = widgetHead.next;
		}
	}
}

void drawWidgets(void)
{
	Widget* w;
	SDL_Color c;

	for (w = widgetHead.next; w != NULL; w = w->next)
	{
		if (w == app.activeWidget)
		{
			c.g = 255;
			c.r = c.b = 0;

			drawText(">", w->x - 40, w->y, c.r, c.g, c.b, TEXT_ALIGN_LEFT, 0);
		}
		else
		{
			c.r = c.g = c.b = 255;
		}

		drawText(w->label, w->x, w->y, c.r, c.g, c.b, TEXT_ALIGN_LEFT, 0);
	}
}

void initDemo(void)
{
	Widget* w;
	int x;

	x = 500;

	w = createWidget("start");
	w->x = x;
	w->y = 200;
	STRCPY(w->label, "Start");

	app.activeWidget = w;

	w = createWidget("load");
	w->x = x;
	w->y = 250;
	STRCPY(w->label, "Load");

	w = createWidget("options");
	w->x = x;
	w->y = 300;
	STRCPY(w->label, "Options");

	w = createWidget("credits");
	w->x = x;
	w->y = 350;
	STRCPY(w->label, "Credits");

	w = createWidget("exit");
	w->x = x;
	w->y = 400;
	STRCPY(w->label, "Exit");

	app.delegate.logic = &logic;
	app.delegate.draw = &draw;
}

static void logic(void)
{
	doWidgets();
}
static void draw(void)
{
	drawWidgets();
}

void initGameSystem(void)
{
	initFonts();

	initWidgets();
}