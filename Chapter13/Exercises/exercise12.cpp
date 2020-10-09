/*
	Exercise 12: Draw a circle . Move a mark around on the circle (let it move a bit each time you hit the next button.
*/

#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

const double pi = 3.14159265359;

double get_radian(int deg)
{
	return (pi * deg) / 180;
}

Point rotate_point(Point start, Point center, int angle)
{
	double rx = (start.x - center.x) * cos(get_radian(angle)) - (start.y - center.y) * sin(get_radian(angle)) + center.x;
	double ry = (start.y - center.y) * cos(get_radian(angle)) + (start.x - center.x) * sin(get_radian(angle)) + center.y;

	return Point{ static_cast<int>(rx), static_cast<int>(ry) };
}

int main()
{
	Point tl{ 100,100 };

	Simple_window win{ tl, 600,400, "Exercise 12" };

	Graph_lib::Circle c{ Point{300,200}, 100 };
	c.set_color(Color::black);
	c.set_fill_color(Color::green);
	win.attach(c);

	Point begin{ c.center().x + c.radius(), c.center().y };

	Vector_ref<Mark> vr;
	for (int i = 0; i < 360; i += 30)
	{
		if (i > 0) win.detach(vr[vr.size() - 1]);

		vr.push_back(new Mark{rotate_point(begin, c.center(), i), 'X' });
		vr[vr.size() - 1].set_color(Color::black);
		win.attach(vr[vr.size() - 1]);
		win.wait_for_button();
	}

}