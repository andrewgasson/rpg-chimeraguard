#include "core.h"
#include "geometry.h"
#include "BearLibTerminal.h"
#include "game.h"

static int animtimer;
static boolean drawrequest;
static boolean enginerunning;
static EngineState enginestate;

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
				enginestate.update();
			}
		}

		animtimer++;

		if (animtimer > EngineAnimRate) {
			animtimer = 0;
			drawrequest = True;

			if (enginestate.animate)
				enginestate.animate();
		}

		if (drawrequest) {
			drawrequest = False;

			if (enginestate.draw)
				enginestate.draw();
		}

		terminal_delay(1);
	}

	terminal_close();
}

void
enginestatepop(void)
{
	// TODO: Deck
}

void
enginestatepush(EngineState s)
{
	// TODO: Deck
	enginestate = s;
}

void
enginestop(void)
{
	enginerunning = False;
}
