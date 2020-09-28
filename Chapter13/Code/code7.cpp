/* Code from page 462-463*/

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100,100 };

	Simple_window win{ tl, 600, 400, "Page 462" };

	Graph_lib::Rectangle rect00{ Point{150,100}, 200,100 };
	Graph_lib::Rectangle rect11{ Point{50,50}, Point{250,150} };
	Graph_lib::Rectangle rect12{ Point{50, 150}, Point{250,250} };
	Graph_lib::Rectangle rect21{ Point{250,50}, 200,100 };
	Graph_lib::Rectangle rect22{ Point{250,150}, 200, 100 };

	rect00.set_fill_color(Color::yellow);
	rect11.set_fill_color(Color::blue);
	rect12.set_fill_color(Color::red);
	rect21.set_fill_color(Color::green);

	win.attach(rect00);
	win.attach(rect11);
	win.attach(rect12);
	win.attach(rect21);
	win.attach(rect22);

	win.wait_for_button();

	rect11.move(400, 0);
	rect11.set_fill_color(Color::white);
	win.set_label("rectangles 2");

	win.wait_for_button();
}