/*
	Exercise 1: Define a class Arc, which draws a part of an ellipse. Hint: fl_arc().
*/

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

namespace Graph_lib {

	struct Arc : Shape {
		Arc(Point p, int w, int h, int b, int e); //center, width, height, begin angle, end angle

		void draw_lines() const;

		Point center() const;


		void set_major(int ww)
		{
			set_point(0, Point{ center().x - ww,center().y - h });

			w = ww;
		}
		int major() const { return w; }

		void set_minor(int hh)
		{
			set_point(0, Point{ center().x - w, center().y - hh });

			h = hh;
		}
		int minor() const { return h; }

	private:
		int w;
		int h;
		int b;
		int e;

	};

}
Arc::Arc(Point p, int ww, int hh, int bb, int ee)
	:w{ ww }, h{ hh }, b{ bb }, e{ ee }
{
	add(Point{ p.x - w/2,p.y - h/2 });
}

Point Arc::center() const
{
	return { point(0).x + w, point(0).y + h };
}

void Arc::draw_lines() const
{
	if (color().visibility())
		fl_arc(point(0).x, point(0).y, w, h, b, e);
}

int main()
{
	Point tl{ 100,100 };

	Simple_window win{ tl, 600, 400, "Exercise 1" };

	Graph_lib::Arc a1 { Point{200,200}, 100,40,0,270 };
	a1.set_color(Color::black);

	Graph_lib::Arc a2{ Point{400,200}, 50, 150, 90, 270 };
	a2.set_color(Color::red);

	Graph_lib::Arc a3{ Point{200,200}, 100,100,25,350 };
	a3.set_color(Color::blue);

	Mark m{ Point{200,200}, 'X' };
	m.set_color(Color::black);
	Mark m2{ Point{400,200}, 'X' };
	m2.set_color(Color::black);

	win.attach(a1);
	win.attach(a2);
	win.attach(a3);
	win.attach(m);
	win.attach(m2);
	win.wait_for_button();
}