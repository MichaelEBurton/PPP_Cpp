/*
	Exercise 2: Draw a 100-by-30 rectangle and place the text "Howdy!" inside it.
*/

#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	Simple_window win{ Point{100,100}, 600, 400, "Exercise 2" };

	Graph_lib::Rectangle r{ Point{50,50}, 100, 50 };
	r.set_color(Color::black);

	Text t{ Point{75,75}, "Howdy!" };
	t.set_color(Color::black);

	win.attach(r);
	win.attach(t);

	win.wait_for_button();
}