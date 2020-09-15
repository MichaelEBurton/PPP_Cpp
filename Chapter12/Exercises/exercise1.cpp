/*
	Exercise 1: Draw a rectangle as a Rectangle and as a Polygon. Make the lines of the Polygon red and the lines of the Rectangle blue.

*/

#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100,100 };

	Simple_window win(tl, 600, 400, "Exercise 1");

	Graph_lib::Polygon rpoly;
	rpoly.add(Point{ 200,200 });
	rpoly.add(Point{ 200,100 });
	rpoly.add(Point{ 300,100 });
	rpoly.add(Point{ 300,200 });

	Graph_lib::Rectangle r{ Point{350,100}, 100, 100 };

	rpoly.set_color(Color::red);
	r.set_color(Color::blue);

	win.attach(rpoly);
	win.attach(r);

	win.wait_for_button();

}