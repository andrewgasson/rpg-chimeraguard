#include "core.h"
#include "geometry.h"
#include "BearLibTerminal.h"
#include "game.h"

//static boolean titleflash;
static int xbox;
static int ybox;
static int wbox;
static int hbox;

static void sandboxanimate(void);
static void sandboxclose(void);
static void sandboxdraw(void);
static void sandboxopen(void);
static void sandboxupdate(void);

ViewState ViewSandbox = {
	.fullscreen = False,
	.disableturnprocess = False,
	.disableworldanim = False,
	.disableworlddraw = False,
	.animate = sandboxanimate,
	.close = sandboxclose,
	.draw = sandboxdraw,
	.open = sandboxopen,
	.update = sandboxupdate
};

static
void
sandboxanimate(void)
{
	//titleflash = !titleflash;
}

static
void
sandboxclose(void)
{
	//
}

static
void
sandboxdraw(void)
{
	/*
	// Title flash
	if (titleflash)
		terminal_color(color_from_name("amber"));
	else
		terminal_color(color_from_name("grey"));

	terminal_print(0, 0, "chimera v0.0.0-alpha");

	// Player
	terminal_color(color_from_argb(255, 255, 255, 255));
	terminal_put(player.position.x, player.position.y, '@');
	*/

	int x;
	int y;

	x = terminal_state(TK_WIDTH / 2);
	y = terminal_state(TK_HEIGHT / 2);

	drawfill(x, y, 20, 20, color_from_name("amber"), color_from_argb(255, 0, 0, 0), '.');
}

static
void
sandboxopen(void)
{
	//
}

static
void
sandboxupdate(void)
{
	/*
	if (inputispressed(InputMoveNorth))
		creaturemove(&player, CompassNorth);
	else if (inputispressed(InputMoveEast))
		creaturemove(&player, CompassEast);
	else if (inputispressed(InputMoveSouth))
		creaturemove(&player, CompassSouth);
	else if (inputispressed(InputMoveWest))
		creaturemove(&player, CompassWest);
	else if (inputispressed(InputUICancel))
		enginesetview(&ViewMainMenu);
	*/

	if (inputispressed(InputUIUp))
		ybox--;
	else if (inputispressed(InputUIRight))
		xbox++;
	else if (inputispressed(InputUIDown))
		ybox++;
	else if (inputispressed(InputUILeft))
		xbox--;
}
