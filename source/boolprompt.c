#include "core.h"
#include <assert.h>
#include "geometry.h"
#include "BearLibTerminal.h"
#include "game.h"

static boolean boolpromptisopen;
static int boolpromptcursor;
static flag boolprompttype;
static char *boolprompttitle;
static char *boolpromptmessage;
static callback boolpromptonaccept;
static callback boolpromptondecline;

static void boolpromptanimate(void);
static void boolpromptclose(void);
static void boolpromptdraw(void);
static void boolpromptopen(void);
static void boolpromptupdate(void);

static ViewState ViewBoolPrompt = {
	.fullscreen = False,
	.disableturnprocess = True,
	.disableworldanim = True,
	.disableworlddraw = False,
	.animate = boolpromptanimate,
	.close = boolpromptclose,
	.draw = boolpromptdraw,
	.open = boolpromptopen,
	.update = boolpromptupdate
};

void
viewboolprompt(callback oaccept, callback ondecline, char *title, char *message, flag boolprompttype)
{
	assert(!boolpromptisopen);
	boolpromptisopen = True;
}

static
void
boolpromptanimate(void)
{
	//
}

static
void
boolpromptclose(void)
{
	boolpromptisopen = False;
}

static
void
boolpromptdraw(void)
{
	//
}

static
void
boolpromptopen(void)
{
	//
}

static
void
boolpromptupdate(void)
{
	//
}
