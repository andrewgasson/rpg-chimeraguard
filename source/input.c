#include "core.h"
#include "geometry.h"
#include "BearLibTerminal.h"
#include "game.h"

static boolean inputavailable = False;
static int inputstate = TK_INPUT_NONE;

boolean
inputhasactive(void)
{
	return inputavailable;
}

boolean
inputispressed(flag input)
{
	switch (input) {
	case InputAppQuit:
		return inputstate == TK_CLOSE;
	case InputUIUp:
		return inputstate == TK_UP;
	case InputUIRight:
		return inputstate == TK_RIGHT;
	case InputUIDown:
		return inputstate == TK_DOWN;
	case InputUILeft:
		return inputstate == TK_LEFT;
	case InputUISubmit:
		return inputstate == TK_ENTER;
	case InputUICancel:
		return inputstate == TK_ESCAPE;
	case InputMoveNorth:
		return inputstate == TK_UP;
	case InputMoveEast:
		return inputstate == TK_RIGHT;
	case InputMoveSouth:
		return inputstate == TK_DOWN;
	case InputMoveWest:
		return inputstate == TK_LEFT;
	default:
		return False;
	}
}

void
inputupdate(void)
{
	if (terminal_has_input()) {
		inputavailable = True;
		inputstate = terminal_read();
	} else {
		inputavailable = False;
		inputstate = TK_INPUT_NONE;
	}
}
