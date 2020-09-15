/*
	Exercise 3: Draw your initials 150 pixels high. Use a thick line. Draw each initial in a different color.
*/

#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100,100 };

	Simple_window win(tl, 600, 400, "Exercise 3");
	// First initial ==================================================================================================================

	Lines m;

	m.add(Point(100, 250), Point(100, 100));
	m.add(Point(100, 100), Point(125, 150));
	m.add(Point(125, 150), Point(150, 100));
	m.add(Point(150, 100), Point(150, 250));

	m.set_color(Color::dark_green);

	// Second initial =================================================================================================================
	Lines e;

	e.add(Point(175, 250), Point(175, 100));
	e.add(Point(175, 100), Point(225, 100));
	e.add(Point(175, 175), Point(225, 175));
	e.add(Point(175, 250), Point(225, 250));

	e.set_color(Color::dark_yellow);

	// Third initial ==================================================================================================================
	Lines b;

	b.add(Point(250, 250), Point(250, 100));
	b.add(Point(250, 100), Point(300, 137));
	b.add(Point(300, 137), Point(250, 175));
	b.add(Point(250, 175), Point(300, 212));
	b.add(Point(300, 212), Point(250, 250));

	b.set_color(Color::dark_red);

	//======================================================================================================================================

	win.attach(m);
	win.attach(e);
	win.attach(b);

	win.wait_for_button();
}