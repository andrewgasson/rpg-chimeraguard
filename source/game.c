#include "core.h"
#include "geometry.h"
#include "BearLibTerminal.h"
#include "game.h"

Creature player;
int currentsaveindex = -1;

static void gameunloadsave(void);

void
gamelaunch(void)
{
	// Used for doing things like creating config and save files,
	// setting the initial UI, and etc. It's the "game" starting point.
	viewstatepush(ViewSandbox);
	gamenewsave(0);
}

void
gameloadsave(int saveindex, flag savetype)
{
	// TODO
}

void
gamenewsave(int saveindex)
{
	player.position = ptint(0);
}

void
gamesave(flag savetype)
{
	// TODO
}

static
void
gameunloadsave(void)
{
	// TODO
}
