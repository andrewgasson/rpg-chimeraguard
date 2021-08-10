#include "core.h"
#include <assert.h>
#include "geometry.h"
#include "BearLibTerminal.h"
#include "game.h"

static int animtimer;
static boolean drawrequest;
static boolean enginerunning;
static int engineviewcount;
static ViewState engineviews[MaxViewStates];

static void engineanimate(void);
static void enginedraw(void);
static void engineupdate(void);

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
				engineupdate();
			}
		}

		animtimer++;

		if (animtimer > EngineAnimRate) {
			animtimer = 0;
			drawrequest = True;
			engineanimate();
		}

		if (drawrequest) {
			drawrequest = False;
			enginedraw();
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

void
engineviewpop(void)
{
	assert(engineviewcount > 0);
	engineviewcount--;
}

void
engineviewpush(ViewState v)
{
	assert(engineviewcount < MaxViewStates);
	engineviews[engineviewcount] = v;
	engineviewcount++;
}

static
void
engineanimate(void)
{
	int i;
	boolean animworld;

	animworld = True;

	for (i = 0; i < engineviewcount; i++) {
		if (engineviews[i].disableworldanim) {
			animworld = False;
			break;
		}
	}

	if (animworld) {
		// TODO: animate the world!
	}

	if (engineviews[engineviewcount - 1].animate)
		engineviews[engineviewcount - 1].animate();
}

static
void
enginedraw(void)
{
	int i;
	int lowestfullscreen;
	boolean drawworld;

	lowestfullscreen = 0;
	drawworld = True;

	for (i = 0; i < engineviewcount; i++) {
		if (engineviews[i].disableworlddraw)
			drawworld = False;
		
		if (engineviews[i].fullscreen)
			lowestfullscreen = i;
	}

	if (drawworld) {
		// TODO
	}

	for (i = lowestfullscreen; i < engineviewcount; i++) {
		if (engineviews[i].draw)
			engineviews[i].draw();
	}
}

static
void
engineupdate(void)
{
	int i;
	boolean processturns;

	assert(engineviewcount > 0);

	processturns = True;

	if (processturns) {
		// TODO
	}

	for (i = 0; i < engineviewcount; i++) {
		if (engineviews[i].disableturnprocess) {
			processturns = False;
			break;
		}
	}

	engineviews[engineviewcount - 1].update();
}
