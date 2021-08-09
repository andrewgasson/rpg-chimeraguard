#include "core.h"
#include "geometry.h"
#include "BearLibTerminal.h"
#include "game.h"

static void mainmenuanimate(void);
static void mainmenuclose(void);
static void mainmenudraw(void);
static void mainmenuopen(void);
static void mainmenuupdate(void);

const EngineState StateMainMenu = {
	.animate = mainmenuanimate,
	.close = mainmenuclose,
	.draw = mainmenudraw,
	.open = mainmenuopen,
	.update = mainmenuupdate
};

static
void
mainmenuanimate(void)
{
	//
}

static
void
mainmenuclose(void)
{
	//
}

static
void
mainmenudraw(void)
{
	//
}

static
void
mainmenuopen(void)
{
	//
}

static
void
mainmenuupdate(void)
{
	//
}
