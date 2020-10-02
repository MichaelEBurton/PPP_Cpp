/*
	Exercise 5: Define the functions from exercise 4 for a Circle and an Ellipse. Place the 
	            connection points on or outside the shape but not outsie the bounding 
				rectangle.

	Note: If it wasn't for TheLastPolaris I would have forgotten all about polar coordinates
*/

#include "Graph.h"
#include "Simple_window.h"
#include <cmath>

double get_radians(int deg)
{
	return (3.14159265358979323846 * deg) / 180;
}

using namespace Graph_lib;

//Circle
Point n(const Graph_lib::Circle& r)
{
	return Point{r.point(0).x + r.radius(), r.point(0).y};
}

Point s(const Graph_lib::Circle& r)
{
	return Point{ r.point(0).x + r.radius(), r.point(0).y + r.radius()*2 };
}

Point e(const Graph_lib::Circle& r)
{
	return Point{ r.point(0).x + r.radius()*2, r.point(0).y + r.radius()};
}

Point w(const Graph_lib::Circle& r)
{
	return Point{ r.point(0).x, r.point(0).y + r.radius() };
}


Point ne(const Graph_lib::Circle& r)
{
	int x = static_cast<int>( r.center().x + r.radius() * cos(get_radians(225)));
	int y = static_cast<int>(r.center().y + r.radius() * sin(get_radians(225)));
	return Point{ x, y };
}


Point nw(const Graph_lib::Circle& r)
{
	int x = static_cast<int>(r.center().x + r.radius() * cos(get_radians(315)));
	int y = static_cast<int>(r.center().y + r.radius() * sin(get_radians(315)));
	return Point{ x, y };
}

Point se(const Graph_lib::Circle& r)
{
	int x = static_cast<int>(r.center().x + r.radius() * cos(get_radians(45)));
	int y = static_cast<int>(r.center().y + r.radius() * sin(get_radians(45)));
	return Point{ x, y };
}

Point sw(const Graph_lib::Circle& r)
{
	int x = static_cast<int>(r.center().x + r.radius() * cos(get_radians(135)));
	int y = static_cast<int>(r.center().y + r.radius() * sin(get_radians(135)));
	return Point{ x, y };
}

Point center(const Graph_lib::Circle& r)
{
	return r.center();
}

//Ellipse
Point n(const Graph_lib::Ellipse& r)
{
	return Point{ r.point(0).x + r.major(), r.point(0).y };
}

Point s(const Graph_lib::Ellipse& r)
{
	return Point{ r.point(0).x + r.major(), r.point(0).y + r.minor() * 2 };
}

Point e(const Graph_lib::Ellipse& r)
{
	return Point{ r.point(0).x + r.major() * 2, r.point(0).y + r.minor() };
}

Point w(const Graph_lib::Ellipse& r)
{
	return Point{ r.point(0).x, r.point(0).y + r.minor() };
}


Point ne(const Graph_lib::Ellipse& r)
{
	int x = static_cast<int>(r.center().x + r.major() * cos(get_radians(225)));
	int y = static_cast<int>(r.center().y + r.minor() * sin(get_radians(225)));
	return Point{ x, y };
}


Point nw(const Graph_lib::Ellipse& r)
{
	int x = static_cast<int>(r.center().x + r.major() * cos(get_radians(315)));
	int y = static_cast<int>(r.center().y + r.minor() * sin(get_radians(315)));
	return Point{ x, y };
}

Point se(const Graph_lib::Ellipse& r)
{
	int x = static_cast<int>(r.center().x + r.major() * cos(get_radians(45)));
	int y = static_cast<int>(r.center().y + r.minor() * sin(get_radians(45)));
	return Point{ x, y };
}

Point sw(const Graph_lib::Ellipse& r)
{
	int x = static_cast<int>(r.center().x + r.major() * cos(get_radians(135)));
	int y = static_cast<int>(r.center().y + r.minor() * sin(get_radians(135)));
	return Point{ x, y };
}

Point center(const Graph_lib::Ellipse& r)
{
	return r.center();
}

int main()
{
	Point tl{ 100,100 };

	Simple_window win{ tl, 600, 400, "Exercise 5" };

	Circle r{ Point{200,200}, 50 };
	r.set_color(Color::black);

	Graph_lib::Ellipse el{ Point{450,300}, 100,50 };
	el.set_color(Color::black);

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

	m.add(n(el));
	m.add(s(el));
	m.add(e(el));
	m.add(w(el));
	m.add(ne(el));
	m.add(nw(el));
	m.add(se(el));
	m.add(sw(el));
	m.add(center(el));

	win.attach(r);
	win.attach(el);
	win.attach(m);

	win.wait_for_button();
}