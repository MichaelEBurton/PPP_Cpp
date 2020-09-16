/*
	Exercise 11: Draw a series of regular polygons, on inside the other. The innermost should be an equilateral triangle enclosed by a square,
	             enclosed by a pentagon, etc. Fro the mathematically adept only: let all the points of eah N-polygon touch sides of the 
				 (N+1)-polygon. Hint: The trigonometric functions are found in <cmath>.

	Note: I did not notice that the second portion of this exercise was supposed to be optional; for this I have thelastpolaris to thank for his solution. This has helped me
	      to understand I need to review my trigonometry. 
*/

#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

constexpr double pi = 3.14159265;

int to_radians_x(int p, int scale, int deg)
{
	return p + int(scale * cos(deg * pi / 180.0));
}

int to_radians_y(int p, int scale, int deg)
{
	return p + int(scale * sin(deg * pi / 180));
}


int main()
{
	Point tl{ 100,100 };

	Simple_window win{ tl, 600, 400, "Exercise 11" };

	//================================================================================================================
	// Triangle
	Graph_lib::Polygon tri;
	tri.add(Point{ to_radians_x(200,100,270),to_radians_y(180,100,270)});
	tri.add(Point{ to_radians_x(200,100,45), to_radians_y(135,100,45)});
	tri.add(Point{ to_radians_x(200,100,135), to_radians_y(135,100,135)});
	tri.set_color(Color::black);
	tri.set_fill_color(Color::red);
	
	//================================================================================================================
	// Square
	Graph_lib::Polygon sq;
	sq.add(Point{ to_radians_x(200,100,45), to_radians_y(150,100,45) });
	sq.add(Point{ to_radians_x(200,100,135), to_radians_y(150,100,135) });
	sq.add(Point{ to_radians_x(200,100,225), to_radians_y(150,100,225) });
	sq.add(Point{ to_radians_x(200,100,315), to_radians_y(150,100,315) });
	sq.set_color(Color::black);
	sq.set_fill_color(Color::blue);

	//================================================================================================================
	// Pentagon
	Graph_lib::Polygon pen;
	pen.add(Point{ to_radians_x(210,115,0), to_radians_y(150,115,0) });
	pen.add(Point{ to_radians_x(210,115,72), to_radians_y(150,115,72) });
	pen.add(Point{ to_radians_x(210,115,144), to_radians_y(150,115,144) });
	pen.add(Point{ to_radians_x(210,115,216), to_radians_y(150,115,216) });
	pen.add(Point{ to_radians_x(210,115,288), to_radians_y(150,115,288) });
	pen.set_color(Color::black);
	pen.set_fill_color(Color::yellow);

	//================================================================================================================
	win.attach(pen);
	win.attach(sq);
	win.attach(tri);

	win.wait_for_button();
}