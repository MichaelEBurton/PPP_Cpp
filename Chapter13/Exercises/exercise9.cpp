/*
	Exercise 9: Tile a part of a window with Regular_hexagon (use at least eight hexagons)
*/

#include "Graph.h"
#include "Regular_hexagon.h"
#include "Simple_window.h"

using namespace Graph_lib;

double distance_to_midpoint(int d)
{
	double rad = get_radian(30);
	return 50 * cos(rad);
}

 

int main()
{
	Point tl{ 100,100 };

	Simple_window win{ tl, 600, 400, "Exercise 9" };

	Regular_hexagon h1{ tl, 50 };
	h1.set_fill_color(Color::yellow);
	h1.set_color(Color::black);

	Regular_hexagon h2{ Point{100 ,100 + int(distance_to_midpoint(50) * 2)}, 50 };
	h2.set_fill_color(Color::green);
	h2.set_color(Color::black);

	Regular_hexagon h3{ Point{100,100 + int(distance_to_midpoint(50)*4)}, 50 };
	h3.set_fill_color(Color::red);
	h3.set_color(Color::black);

	Regular_hexagon h4{ Point{100 + int((50 + 50*sin(get_radian(30))) ) 
						      ,100 + int(distance_to_midpoint(50))}, 50 };
	h4.set_fill_color(Color::blue);
	h4.set_color(Color::black);

	Regular_hexagon h5{ Point{100 + int((50 + 50 * sin(get_radian(30))))
							  ,100 + int(distance_to_midpoint(50) * 3)}, 50 };
	h5.set_fill_color(Color::white);
	h5.set_color(Color::black);

	Regular_hexagon h6{ Point{100 + int((50 + 50 * sin(get_radian(30))))
							  ,100 + int(distance_to_midpoint(50) * 5)}, 50 };
	h6.set_fill_color(Color::cyan);
	h6.set_color(Color::black);

	Regular_hexagon h7{ Point{100 + int((50 + 50 * sin(get_radian(30))))
							  ,100 - int(distance_to_midpoint(50))}, 50 };
	h7.set_fill_color(Color::black);
	h7.set_color(Color::black);

	Regular_hexagon h8{ Point{100 + int((50 + 50 * sin(get_radian(30)) * 4)) ,100}, 50 };
	h8.set_fill_color(Color::magenta);
	h8.set_color(Color::black);

	win.attach(h1);
	win.attach(h2);
	win.attach(h3);
	win.attach(h4);
	win.attach(h5);
	win.attach(h6);
	win.attach(h7);
	win.attach(h8);

	win.wait_for_button();
}