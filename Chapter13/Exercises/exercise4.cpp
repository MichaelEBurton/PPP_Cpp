/*
	Exercise 4: Define functions n(), s(), e(), w(), center(), ne(), se(), sw(), and nw().
	            Each takes a rectangle argument and returns a Point. These functions define 
				"connection points" on and in the rectangle. For example, nw(r) is the northwest
				(top left) corner of a Rectangle called r.
*/

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

Point n(const Graph_lib::Rectangle& r)
{
	return Point{ r.point(0).x + r.width() / 2, r.point(0).y };
}

Point s(const Graph_lib::Rectangle& r)
{
	return Point{ r.point(0).x + r.width() / 2, r.point(0).y + r.height() };
}

Point e(const Graph_lib::Rectangle& r)
{
	return Point{ r.point(0).x + r.width(), r.point(0).y + r.height()/2 };
}

Point w(const Graph_lib::Rectangle& r)
{
	return Point{ r.point(0).x, r.point(0).y + r.height() / 2 };
}

Point ne(const Graph_lib::Rectangle& r)
{
	return Point{ r.point(0).x + r.width(), r.point(0).y };
}

Point nw(const Graph_lib::Rectangle& r)
{
	return Point{ r.point(0).x, r.point(0).y};
}

Point se(const Graph_lib::Rectangle& r)
{
	return Point{ r.point(0).x + r.width(), r.point(0).y + r.height() };
}

Point sw(const Graph_lib::Rectangle& r)
{
	return Point{ r.point(0).x, r.point(0).y + r.height() };
}

Point center(const Graph_lib::Rectangle& r)
{
	return Point{ r.point(0).x + r.width()/2, r.point(0).y + r.height()/2 };
}
int main()
{
	Point tl{ 100,100 };

	Simple_window win{ tl, 600, 400, "Exercise 4" };

	Graph_lib::Rectangle r{ tl, 300,200 };
	r.set_color(Color::red);

	Graph_lib::Marks m{ "*" };

	m.add(n(r));
	m.add(s(r));
	m.add(e(r));
	m.add(w(r));
	m.add(ne(r));
	m.add(nw(r));
	m.add(se(r));
	m.add(sw(r));
	m.add(center(r));

	win.attach(r);
	win.attach(m);

	win.wait_for_button();
	
}