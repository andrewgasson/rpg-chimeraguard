#include "core.h"
#include "geometry.h"
#include "BearLibTerminal.h"
#include "game.h"

boolean
creaturecanmove(Creature *cr, flag dir)
{
	return True;
}

void
creaturemove(Creature *cr, flag dir)
{
	cr->position = ptadd(cr->position, compasstopoint(dir));
}
