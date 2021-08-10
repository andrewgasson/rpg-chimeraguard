#include "core.h"
#include <assert.h>
#include "geometry.h"
#include "BearLibTerminal.h"
#include "game.h"

int viewstatecount;
ViewState viewstates[MaxViewStates];

static ViewState *viewstatepeek(void);

void
viewstateanimate(void)
{
	ViewState *current;

	current = viewstatepeek();

	if (current && current->animate)
		current->animate();
}

void
viewstatedraw(void)
{
	ViewState *current;

	current = viewstatepeek();

	if (current && current->draw)
		current->draw();
}

void
viewstatepop(void)
{
	assert(viewstatecount > 0);
	viewstatecount--;
}

void
viewstatepush(ViewState v)
{
	assert(viewstatecount < MaxViewStates);
	viewstates[viewstatecount] = v;
	viewstatecount++;
}

void
viewstateupdate(void)
{
	ViewState *current;

	current = viewstatepeek();
	assert(current != Null);
	assert(current->update != Null);
	current->update();
}

static
ViewState*
viewstatepeek(void)
{
	return viewstatecount > 0 ? &viewstates[viewstatecount - 1] : Null;
}
