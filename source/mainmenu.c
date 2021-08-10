#include "core.h"
#include "geometry.h"
#include "BearLibTerminal.h"
#include "game.h"

static int mainmenucursor;

static void mainmenuanimate(void);
static void mainmenuclose(void);
static void mainmenudraw(void);
static void mainmenuopen(void);
static void mainmenuupdate(void);

const ViewState ViewMainMenu = {
	.fullscreen = True,
	.disableturnprocess = True,
	.disableworldanim = True,
	.disableworlddraw = True,
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

// Main Menu
// > Option
static
void
mainmenudraw(void)
{
	terminal_color(color_from_argb(255, 255, 255, 255));
	terminal_print(1, 0, "Main Menu");
	terminal_print(2, 1, "Sandbox");
	terminal_print(2, 2, "Quit");
	terminal_print(1, 1 + mainmenucursor, ">");
}

static
void
mainmenuopen(void)
{
	mainmenucursor = 0;
}

static
void
mainmenuupdate(void)
{
	if (inputispressed(InputUIUp))
		mainmenucursor--;
	else if (inputispressed(InputUIDown))
		mainmenucursor++;

	if (mainmenucursor < 0)
		mainmenucursor = 0;
	else if (mainmenucursor > 1)
		mainmenucursor = 1;

	if (inputispressed(InputUISubmit)) {
		if (mainmenucursor == 0)
			enginesetview(ViewSandbox);
		else
			enginestop();
	}
}
