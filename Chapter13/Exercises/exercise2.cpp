/*
	Exercise 2: Draw a box with rounded corners. Define a class Box, consisting of four lines and four arcs.
*/

#include "Graph.h"
#include "Simple_window.h"
#include "Arc.h"

using namespace Graph_lib;

namespace Graph_lib {
	struct Box : Shape {
		Box( Point pp, int ww, int hh );
		Box( Point x, Point y );
		void draw_lines() const;

		int height() const { return h; }
		int width() const { return w; }

	private:
		Point p;
		int w;
		int h;
	};

	Box::Box(Point pp, int ww, int hh)
		:p{ pp },w {ww}, h{ hh }
	{
		if (h <= 0 || w <= 0)
			error("Bad Box: non-positive side");
		add(p);
	}

	Box::Box(Point x, Point y)
		:p{x}, w{ y.x - x.x }, h{ y.y - x.y }
	{
		if (h <= 0 || w <= 0)
			error("Bad Box: non-positive side");
		add(x);
	}

	void Box::draw_lines() const
	{
		int offset{ 10 };

		if (color().visibility()) {
			//Make curved edges!!!
			fl_color(color().as_int());
			fl_line(p.x + offset, p.y, p.x + w - offset, p.y); // top line
			fl_line(p.x + offset, p.y+h, p.x + w - offset, p.y+h); // bottom line
			fl_line(p.x, p.y+offset, p.x, p.y + h-offset); // left line
			fl_line(p.x + w, p.y+offset, p.x + w, p.y + h-offset); // left line

			fl_arc(p.x, p.y, 20, 20, 90, 180);           // top left corner
			fl_arc(p.x + w - offset*2, p.y, 20, 20, 0, 90);       // top right corner
			fl_arc(p.x, p.y + h - offset*2, 20, 20, 180, 270);       // bottom left corner
			fl_arc(p.x + w - offset*2, p.y + h - offset*2, 20, 20, 270, 360);   // bottom right corner
		}
	}
}

int main()
{
	Point tl{ 100,100 };

	Simple_window win{ tl, 600,400,"Exercise 2" };

	Graph_lib::Box b{ Point{200,200}, 100, 100 };
	b.set_color(Color::black);

	Graph_lib::Box c{ Point{300,300}, 50, 100 };
	c.set_color(Color::red);

	Graph_lib::Box d{ Point{400,200}, 100, 50 };
	d.set_color(Color::blue);

	win.attach(a1);
	win.attach(b);
	win.attach(c);
	win.attach(d);

	win.wait_for_button();
}