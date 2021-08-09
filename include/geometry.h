typedef struct Point Point;

struct Point {
	int x;
	int y;
};

Point ptadd(Point, Point);
Point ptdiv(Point, Point);
boolean ptequal(Point, Point);
Point ptint(int);
Point ptmul(Point, Point);
Point ptsub(Point, Point);
