/*
	Exercise 8: Define a class Regular_hexagon (a regular hexagon is a six-sided pollygon with all sides of equal length). Use the center and the distance
	            from the center to a corner point as constructor arguments.
*/

#include "Graph.h"
#include "Simple_window.h"

constexpr double pi = 3.14159265;

double get_radian(int deg)
{
	return (pi * deg) / 180;
}

using namespace Graph_lib;

namespace Graph_lib {
	struct Regular_hexagon : Polygon {
		Regular_hexagon(Point cc, int dd);

		Point center() const { return c; }
		//void draw_lines() const;

	private:
		Point c;
		int d;
	};

	Regular_hexagon::Regular_hexagon(Point cc, int dd)
		: c{ cc }, d{ dd }
	{
		if (dd <= 0) error("Invalid distance from center of hexagon ", dd);

		Point start{ c.x + d,c.y };

		for (int deg = 60; deg <= 360; deg+=60)
		{
			//int deg = 60 + 60 * i;
			double rx = (start.x - c.x) * cos(get_radian(deg)) - (start.y - c.y) * sin(get_radian(deg)) + c.x;
			double ry = (start.y - c.y) * cos(get_radian(deg)) + (start.x - c.x) * sin(get_radian(deg)) + c.y;

			//add(Point{ rx,ry });
			Point p = Point{ int(rx), int(ry) };
			add(p);
		}
	}
}


int main()
{
	Point tl{ 100,100 };

	Simple_window win{ tl, 600, 400, "Exercise 8" };

	Regular_hexagon a{ Point{300,200}, 50 };

	a.set_color(Color::black);
	a.set_fill_color(Color::yellow);

	win.attach(a);

	win.wait_for_button();

}