#include "core.h"
#include "geometry.h"
#include "BearLibTerminal.h"
#include "game.h"

flag
compassanticlockwise(flag compass)
{
	switch (compass) {
	case CompassNorth:
		return CompassNorthWest;
	case CompassNorthEast:
		return CompassNorth;
	case CompassEast:
		return CompassNorthEast;
	case CompassSouthEast:
		return CompassEast;
	case CompassSouth:
		return CompassSouthEast;
	case CompassSouthWest:
		return CompassSouth;
	case CompassWest:
		return CompassSouthWest;
	case CompassNorthWest:
		return CompassWest;
	default:
		return CompassNorth;
	}
}

flag
compassanticlockwisecardinal(flag compass)
{
	switch (compass) {
	case CompassNorth:
	case CompassNorthWest:
		return CompassWest;
	case CompassNorthEast:
	case CompassEast:
		return CompassNorth;
	case CompassSouthEast:
	case CompassSouth:
		return CompassEast;
	case CompassSouthWest:
	case CompassWest:
		return CompassSouth;
	default:
		return CompassNorth;
	}
}

flag
compassanticlockwiseordinal(flag compass)
{
	switch (compass) {
	case CompassNorth:
	case CompassNorthEast:
		return CompassNorthWest;
	case CompassEast:
	case CompassSouthEast:
		return CompassNorthEast;
	case CompassSouth:
	case CompassSouthWest:
		return CompassSouthEast;
	case CompassWest:
	case CompassNorthWest:
		return CompassSouthWest;
	default:
		return CompassNorth;
	}
}

flag
compassclockwise(flag compass)
{
	switch (compass) {
	case CompassNorth:
		return CompassNorthEast;
	case CompassNorthEast:
		return CompassEast;
	case CompassEast:
		return CompassSouthEast;
	case CompassSouthEast:
		return CompassSouth;
	case CompassSouth:
		return CompassSouthWest;
	case CompassSouthWest:
		return CompassWest;
	case CompassWest:
		return CompassNorthWest;
	case CompassNorthWest:
		return CompassNorth;
	default:
		return CompassNorth;
	}
}

flag
compassclockwisecardinal(flag compass)
{
	switch (compass) {
	case CompassNorth:
	case CompassNorthEast:
		return CompassEast;
	case CompassEast:
	case CompassSouthEast:
		return CompassSouth;
	case CompassSouth:
	case CompassSouthWest:
		return CompassWest;
	case CompassWest:
	case CompassNorthWest:
		return CompassNorth;
	default:
		return CompassNorth;
	}
}

flag
compassclockwiseordinal(flag compass)
{
	switch (compass) {
	case CompassNorthWest:
	case CompassNorth:
		return CompassNorthEast;
	case CompassNorthEast:
	case CompassEast:
		return CompassSouthEast;
	case CompassSouthEast:
	case CompassSouth:
		return CompassSouthWest;
	case CompassSouthWest:
	case CompassWest:
		return CompassNorthWest;
	default:
		return CompassNorth;
	}
}

boolean
compassiscardinal(flag compass)
{
	switch (compass) {
	case CompassNorth:
	case CompassEast:
	case CompassSouth:
	case CompassWest:
		return 1;
	default:
		return 0;
	}
}

boolean
compassisopposite(flag compass0, flag compass1)
{
	return compassopposite(compass0) == compass1;
}

boolean
compassisordinal(flag compass)
{
	switch (compass) {
	case CompassNorthEast:
	case CompassSouthEast:
	case CompassSouthWest:
	case CompassNorthWest:
		return 1;
	default:
		return 0;
	}
}

flag
compassopposite(flag compass)
{
	switch (compass) {
	case CompassNorth:
		return CompassSouth;
	case CompassNorthEast:
		return CompassSouthWest;
	case CompassEast:
		return CompassWest;
	case CompassSouthEast:
		return CompassNorthWest;
	case CompassSouth:
		return CompassNorth;
	case CompassSouthWest:
		return CompassNorthEast;
	case CompassWest:
		return CompassEast;
	case CompassNorthWest:
		return CompassSouthEast;
	default:
		return CompassNorth;
	}
}

Point
compasstopoint(flag compass)
{
	/* Relative to screen (where 0,0 is top,left) */
	switch (compass) {
	case CompassNorth:
		return (Point){ .x = 0, .y = -1 };
	case CompassNorthEast:
		return (Point){ .x = 1, .y = -1 };
	case CompassEast:
		return (Point){ .x = 1, .y = 0 };
	case CompassSouthEast:
		return (Point){ .x = 1, .y = 1 };
	case CompassSouth:
		return (Point){ .x = 0, .y = 1 };
	case CompassSouthWest:
		return (Point){ .x = -1, .y = 1 };
	case CompassWest:
		return (Point){ .x = -1, .y = 0 };
	case CompassNorthWest:
		return (Point){ .x = -1, .y = -1 };
	default:
		return (Point){ .x = 0, .y = 0 };
	}
}
