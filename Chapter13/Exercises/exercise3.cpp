/*
	Exercise 3: Define a class Arrow, which draws a line with an arrowhead.

	Disclaimer: Most of the code for this was taken from TheLastPolaris 
	            check him out here: https://github.com/thelastpolaris/Programming-Principles-and-Practice-Using-C-/blob/master/13/ex3.cpp
	            My original attempt did not work (included in comments) because I did not take a mathematical approach to rotating the vectors to get proper arrowheads.
				So in order to better understand what Polaris has done, I have commented his code.
*/

#include "Graph.h"
#include "Simple_window.h"
#include "Box.h"
#include <cmath>

constexpr double pi = 3.14159265;

double get_radian(double d) {
	return d * (pi / 180);
}

using namespace Graph_lib;

namespace Graph_lib {
	struct Arrow : Shape {
		Arrow(Point p1, Point p2);

		void draw_lines() const;

	private:
		Point i;
		Point j;

	};

	Arrow::Arrow(Point p1, Point p2)
		:i{ p1 }, j{ p2 }
	{}

	void Arrow::draw_lines() const
	{
		if (color().visibility())
		{
			fl_line(i.x, i.y, j.x, j.y);

			// convert degrees to radians for left and right arrowhead
			double left_rotation = get_radian(45);
			double right_rotation = get_radian(315);

			// length of arrow
			double distance = 10; 

			// Create the x component and y component vector from the first point to the second point
			double vx = j.x - i.x; 
			double vy = j.y - i.y;

			double mag = sqrt(vx * vx + vy * vy); // Length of vector

			//Normalization of vectors (i.e. magintude of <vx, vy> = 1)
			vx /= mag;
			vy /= mag;

			// This next bit of code essentially reduces the length of the line by shortening the second point
			// 1. Take our first point (i)
			// 2. Add to it in the direction we want to go but only as far as the 
			//      magnitude of the orignial second point minus some distance

			int px = int(double(i.x) + vx * (mag - distance)); 
			int py = int(double(i.y) + vy * (mag - distance)); 


			// These next few lines of code deal with rotating a set of points
			// (https://math.stackexchange.com/questions/1687901/how-to-rotate-a-line-segment-around-one-of-the-end-points)

			//Left line of arrow	
			double rx_l = (px - j.x) * cos(left_rotation) - (py - j.y) * sin(left_rotation) + j.x;
			double ry_l = (py - j.y) * cos(left_rotation) + (px - j.x) * sin(left_rotation) + j.y;

			//Right line of arrow	
			double rx_r = (px - j.x) * cos(right_rotation) - (py - j.y) * sin(right_rotation) + j.x;
			double ry_r = (py - j.y) * cos(right_rotation) + (px - j.x) * sin(right_rotation) + j.y;

			//draw the lines
			fl_line(j.x, j.y, rx_l, ry_l);
			fl_line(j.x, j.y, rx_r, ry_r);

			/*
			if(i.x < j.x && i.y == j.y)
			{
				fl_line(j.x, j.y, j.x - 10, j.y + 10);
				fl_line(j.x, j.y, j.x - 10, j.y - 10);
			}
			else if(j.x < i.x && i.y == j.y)
			{
				fl_line(j.x, j.y, j.x + 10, j.y + 10);
				fl_line(j.x, j.y, j.x + 10, j.y - 10);
			}
			else if(i.x == j.x && i.y < j.y)
			{
				fl_line(j.x, j.y, j.x - 10, j.y - 10);
				fl_line(j.x, j.y, j.x + 10, j.y - 10);
			}
			else if(i.x == j.x && j.y < i.y)
			{
				fl_line(j.x, j.y, j.x - 10, j.y + 10);
				fl_line(j.x, j.y, j.x + 10, j.y + 10);
			}
			else if (i.x < j.x && j.y < i.y)
			{
				fl_line(j.x, j.y, j.x - sqrt(200), j.y);
				fl_line(j.x, j.y, j.x, j.y + sqrt(200));
			}
			else if (i.x < j.x && i.y < j.y)
			{
				fl_line(j.x, j.y, j.x - sqrt(200), j.y);
				fl_line(j.x, j.y, j.x, j.y - sqrt(200));
			}
			else if (j.x < i.x && i.y < j.y)
			{
				fl_line(j.x, j.y, j.x + sqrt(200), j.y);
				fl_line(j.x, j.y, j.x, j.y - sqrt(200));
			}
			else if (j.x < i.x && j.y < i.y)
			{
				fl_line(j.x, j.y, j.x + sqrt(200), j.y);
				fl_line(j.x, j.y, j.x, j.y + sqrt(200));
			}
			*/
			
		}
	}
}

int main()
{
	Point tl{ 100,100 };

	Simple_window win{ tl, 600, 400, "Exercise 3" };

	Graph_lib::Arrow a{ Point{305,200}, Point{400,200} }; // east
	
	a.set_color(Color::black);

	Graph_lib::Arrow b{ Point{295,200},Point{200,200} }; // west
	b.set_color(Color::black);

	Graph_lib::Arrow c{ Point{300,195},Point{300,100} }; // north
	c.set_color(Color::black);

	Graph_lib::Arrow d{ Point{300,205},Point{300,300} }; // south
	d.set_color(Color::black);
	
	Graph_lib::Arrow e{ Point{305,195}, Point{400, 100} }; // northeast
	e.set_color(Color::black);


	Graph_lib::Arrow f{ Point{295,205}, Point{200, 300} }; // southwest
	f.set_color(Color::black);

	Graph_lib::Arrow g{ Point{305,205}, Point{400, 300} }; // southeast
	g.set_color(Color::black);

	Graph_lib::Arrow h{ Point{295,195}, Point{200, 100} }; // southeast
	h.set_color(Color::black);
	
	Graph_lib::Arrow i{ Point{100,100},Point{200,50} };
	i.set_color(Color::black);

	win.attach(a);
	win.attach(b);
	win.attach(c);
	win.attach(d);
	win.attach(e);
	win.attach(f);
	win.attach(g);
	win.attach(h);
	win.attach(i);
	

	win.wait_for_button();
}
