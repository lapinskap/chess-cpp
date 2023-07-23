#pragma once

#include <vector>
#include <iostream>

namespace Chess
{
	struct Point
	{
		Point() = default;
		Point(char x, char y);
		Point(int x, int y);

		char x = 0;
		char y = 0;

		bool operator == (Point p) const;
		Point operator + (Point p) const;
	};

	using Points = std::vector<Point>;
}

std::ostream& operator << (std::ostream& os, Chess::Point p);
