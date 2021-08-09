#include "core.h"
#include "geometry.h"

inline
Point
ptadd(Point p0, Point p1)
{
	return (Point){
		.x = p0.x + p1.x,
		.y = p0.y + p1.y
	};
}

inline
Point
ptdiv(Point p0, Point p1)
{
	return (Point){
		.x = p0.x / p1.x,
		.y = p0.y / p1.y
	};
}

inline
boolean
ptequal(Point p0, Point p1)
{
	return p0.x == p1.x
		&& p0.y == p1.y;
}

inline
Point
ptint(int v)
{
	return (Point){ v, v };
}

inline
Point
ptmul(Point p0, Point p1)
{
	return (Point){
		.x = p0.x * p1.x,
		.y = p0.y * p1.y
	};
}

inline
Point
ptsub(Point p0, Point p1)
{
	return (Point){
		.x = p0.x - p1.x,
		.y = p0.y - p1.y
	};
}
