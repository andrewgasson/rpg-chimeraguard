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

static void engineviewanimate(void);
static void engineviewdraw(void);
static ViewState *engineviewpeek(void);
static void engineviewupdate(void);

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
				engineviewupdate();
			}
		}

		animtimer++;

		if (animtimer > EngineAnimRate) {
			animtimer = 0;
			drawrequest = True;
			engineviewanimate();
		}

		if (drawrequest) {
			drawrequest = False;
			engineviewdraw();
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
engineviewanimate(void)
{
	ViewState *current;

	current = engineviewpeek();

	if (current && current->animate)
		current->animate();
}

static
void
engineviewdraw(void)
{
	ViewState *current;

	current = engineviewpeek();

	if (current && current->draw)
		current->draw();
}

static
ViewState*
engineviewpeek(void)
{
	return engineviewcount > 0 ? &engineviews[engineviewcount - 1] : Null;
}

static
void
engineviewupdate(void)
{
	ViewState *current;

	current = engineviewpeek();
	assert(current != Null);
	assert(current->update != Null);
	current->update();
}
