#include "core.h"
#include <assert.h>
#include "geometry.h"
#include "BearLibTerminal.h"
#include "game.h"

static int animtimer;
static boolean drawrequest;
static boolean enginerunning;
static int engineviewcount;
static ViewState *engineviews[MaxViewStates];

static void engineanimate(void);
static void enginedraw(void);
static boolean engineisviewopen(ViewState*);
static void engineupdate(void);

void
enginepopview(void)
{
	assert(engineviewcount > 0);
	engineviews[engineviewcount - 1] = Null;
	engineviewcount--;
	drawrequest = True;
}

void
enginepushview(ViewState *v)
{
	assert(engineviewcount < MaxViewStates);
	assert(!engineisviewopen(v));
	engineviews[engineviewcount] = v;
	engineviewcount++;
	drawrequest = True;
}

void
enginesetview(ViewState *v)
{
	int i;

	for (i = engineviewcount - 1; i >= 0; i--) {
		if (engineviews[i]->close)
			engineviews[i]->close();
	}

	engineviewcount = 0;
	enginepushview(v);
}

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

static
void
engineanimate(void)
{
	int i;
	boolean animworld;

	animworld = True;

	for (i = 0; i < engineviewcount; i++) {
		if (engineviews[i]->disableworldanim) {
			animworld = False;
			break;
		}
	}

	if (animworld) {
		// TODO: animate the world!
	}

	if (engineviews[engineviewcount - 1]->animate)
		engineviews[engineviewcount - 1]->animate();
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
		if (engineviews[i]->disableworlddraw)
			drawworld = False;
		
		if (engineviews[i]->fullscreen)
			lowestfullscreen = i;
	}

	terminal_clear();

	if (drawworld) {
		// TODO
	}

	for (i = lowestfullscreen; i < engineviewcount; i++) {
		if (engineviews[i]->draw)
			engineviews[i]->draw();
	}

	terminal_refresh();
}

static
boolean
engineisviewopen(ViewState *v)
{
	int i;

	for (i = 0; i < engineviewcount; i++) {
		if (engineviews[i] == v)
			return True;
	}

	return False;
}

static
void
engineupdate(void)
{
	int i;
	boolean processturns;

	assert(engineviewcount > 0);

	processturns = True;

	for (i = 0; i < engineviewcount; i++) {
		if (engineviews[i]->disableturnprocess) {
			processturns = False;
			break;
		}
	}

	if (processturns) {
		// TODO
	}

	engineviews[engineviewcount - 1]->update();
}
