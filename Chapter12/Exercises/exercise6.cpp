/*
	Exercise 6: What happens when you draw a Shape that doesn't fit inside its window?

	It is still drawn except it doesn't fit on the screen of course so you only see what does fit.
*/

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100,100 };

	Simple_window win{ tl, 600, 400, "Exercise 6" };

	Graph_lib::Rectangle r(Point(500, 300), 200, 100);
	r.set_fill_color(Color::red);

	win.attach(r);

	win.wait_for_button();
}