/*
	Exercise 11: Draw a 300-by-300 pixel ellipse. 
	             Draw a 400-pixel long x axis and a 300-pixel long y axis through the center of the ellipse.
	             Mark the foci.
				 Mark a point on the ellipse that is not on one of the axes. Draw the two lines from the foci to the point.
*/

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100,100 };

	Simple_window win{ tl, 800,800, "Exercise 10" };

	// Ellipse
	Graph_lib::Ellipse e(Point{ 400,350 }, 300, 300);
	e.set_color(Color::black);
	win.attach(e);

	// Axes
	Axis xa{ Axis::x, Point{ 200, 350}, 400, 20, "x axis" };
	xa.set_color(Color::black);
	win.attach(xa);

	Axis ya{ Axis::y, Point{400, 500}, 300, 20, "yaxis" };
	ya.set_color(Color::black);
	win.attach(ya);

	// Mark the foci

	Marks mk{ "x", {e.focus1(), e.focus2()}};
	mk.set_color(Color::black);
	win.attach(mk);

	// mark a point not on the axes
	Point rp{}

	Text t{ {100,100}, to_string(e.focus1().x) + ' ' + to_string(e.focus1().y) };
	t.set_color(Color::black);
	win.attach(t);

	win.wait_for_button();
}