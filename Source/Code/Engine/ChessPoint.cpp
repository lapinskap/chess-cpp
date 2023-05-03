#include "ChessPoint.h"


Chess::Point::Point(char x_, char y_)
: x((int)x_ - (int)('a') + 1)
, y(int(y_ - '0'))
{
}
Chess::Point::Point(int x_, int y_)
: x(x_)
, y(y_)
{
}
bool Chess::Point::operator == (Point p) const
{
	return x == p.x && y == p.y;
}

Chess::Point Chess::Point::operator + (Point p) const
{
	return Point(x + p.x, y + p.y);
}

std::ostream& operator << (std::ostream& os, Chess::Point p)
{
	os << (char)('a' + p.x - 1) << p.y;
	// 3 5 -> d5
	return os;
}
