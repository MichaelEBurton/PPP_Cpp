/* Code from page 473*/

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100,100 };

	Simple_window win{ tl, 600, 400, "Page 473" };

	Graph_lib::Ellipse e1{ Point{200,200},50, 50 };
	Graph_lib::Ellipse e2{ Point{200,200},100, 50 };
	Graph_lib::Ellipse e3{ Point{200,200}, 100, 150 };

	e1.set_color(Color::black);
	e2.set_color(Color::black);
	e3.set_color(Color::black);


	win.attach(e1);
	win.attach(e2);
	win.attach(e3);
	win.wait_for_button();
}