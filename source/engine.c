#include "core.h"
#include "geometry.h"
#include "BearLibTerminal.h"
#include "game.h"

static int animtimer;
static boolean drawrequest;
static boolean enginerunning;

void
enginestart(void)
{
	terminal_open();
	terminal_refresh();
	terminal_setf("window.title='%s';", "Chimera v0.0.0-alpha");
	terminal_setf("window.size=%dx%d;", EngineDisplayWidth, EngineDisplayHeight);
	terminal_setf("input.cursor-blink-rate=%d;", EngineAnimRate);

	animtimer = 0;
	drawrequest = True;
	enginerunning = True;
	gamelaunch();

	while (enginerunning) {
		inputupdate();
		
		if (inputhasactive()) {
			if (inputispressed(InputAppQuit)) {
				enginerunning = False;
			} else {
				drawrequest = True;
				viewstateupdate();
			}
		}

		animtimer++;

		if (animtimer > EngineAnimRate) {
			animtimer = 0;
			drawrequest = True;
			viewstateanimate();
		}

		if (drawrequest) {
			drawrequest = False;
			viewstatedraw();
		}

		terminal_delay(1);
	}

	terminal_close();
}

void
enginestop(void)
{
	enginerunning = False;
}
