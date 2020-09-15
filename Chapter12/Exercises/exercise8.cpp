/*
	Exercise 8: Draw the Olympic five rings. If you can't remember the colors, look them up.

	Notes: How fitting for what was supposed to be an olympic year :(
*/

#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100,100 };

	Simple_window win{ tl, 600, 400, "Exercise 8" };

	Graph_lib::Circle r1{ Point{100,150}, 50 };
	r1.set_color(Color::blue);
	Graph_lib::Circle r2{ Point{220,150}, 50 };
	r2.set_color(Color::black);
	Graph_lib::Circle r3{ Point{340,150}, 50 };
	r3.set_color(Color::red);
	Graph_lib::Circle r4{ Point{160,205}, 50 };
	r4.set_color(Color::yellow);
	Graph_lib::Circle r5{ Point{280,205}, 50 };
	r5.set_color(Color::green);

	win.attach(r1);
	win.attach(r2);
	win.attach(r3);
	win.attach(r4);
	win.attach(r5);

	win.wait_for_button();
}