/* Code from page 470*/

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100,100 };

	Simple_window win{ tl, 600, 400, "Page 470" };

	Circle c1{ Point{100,200},50 };
	Circle c2{ Point{150,200},100 };
	Circle c3{ Point{200,200}, 150 };

	c1.set_color(Color::black);
	c2.set_color(Color::black);
	c3.set_color(Color::black);


	win.attach(c1);
	win.attach(c2);
	win.attach(c3);
	win.wait_for_button();
}