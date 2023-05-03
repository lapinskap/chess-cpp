#pragma once

#include <vector>
#include <iostream>

namespace Chess
{
	struct Point
	{
		Point() = default;
		Point(int x, int y);

		int x = 0;
		int y = 0;

		bool operator == (Point p) const;
		Point operator + (Point p) const;
	};

	using Points = std::vector<Point>;
}

std::ostream& operator << (std::ostream& os, Chess::Point p);
