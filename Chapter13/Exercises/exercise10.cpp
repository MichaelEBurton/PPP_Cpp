/*
	Exercise 9: Define a class Regular_polygon. Use the center, number of sides, and the distance from the center to a corner as constructor arguments
*/

#include "Graph.h"
#include "Simple_window.h"
#include <cmath>

constexpr double pi = 3.14159265;

double get_radian(int deg)
{
	return (pi * deg) / 180;
}

using namespace Graph_lib;

namespace Graph_lib {
	struct Regular_polygon : Polygon 
	{
		Regular_polygon(Point cc, int nn, int dd);

	private:
		Point c;
		int n;
		int d;
	};

	Regular_polygon::Regular_polygon(Point cc, int nn, int dd)
		: c{ cc }, n{ nn }, d{ dd }
	{
		if (nn <= 2) error("Invalid number of sides: ", n);

		Point start{ c.x + d,c.y };

		int begin_deg = int(360 / n);

		for (int deg = begin_deg; deg <= 360; deg += begin_deg)
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

	Simple_window win{ tl, 600,400, "Exercise 10" };

	Point center{ 200,200 };

	Vector_ref<Regular_polygon> vr;
	for (int i = 12; i > 2; --i)
	{
		vr.push_back(new Regular_polygon{ center, i, (15 - i) * 10 });
		vr[vr.size() - 1].set_color(Color::black);
		win.attach(vr[vr.size() - 1]);
	}

	win.wait_for_button();

}