/*
	Exercise 3: Define a class Arrow, which draws a line with an arrowhead.

	Notes: Not perfect, arrowheads look funky unless they are N,S,W,E, NE, NW, SE,SW
*/

#include "Graph.h"
#include "Simple_window.h"
#include "Box.h"
#include <cmath>

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
